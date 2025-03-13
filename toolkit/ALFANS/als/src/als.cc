#include "als.h"
#include "error.h"
#include "lac.h"
#include "my_util.h"
#include <cmath>
#include <cstddef>


using namespace std;
using namespace ABC_NAMESPACE;
using namespace boost;

namespace alfans {
void ALSOpt::Print() {
    cout << endl << "******************** options ********************" << endl;
    cout << (isSign? "use signed output": "use unsigned output") << endl;
    cout << "enable fast error estimation = " << (enableFastErrEst? "YES": "NO") << endl;
    cout << "source seed = " << sourceSeed << endl;
    cout << "lacType = " << lacType << endl;
    cout << "distrType = " << distrType << endl;
    cout << "#simulation patterns = " << nFrame << endl;
    cout << "#simulation patterns for candidate AppResub generation = " << nFrame4ResubGen << endl;
    cout << "max #candidate AppResubs = " << maxCandResub << endl;
    cout << "#threads = " << nThread << endl;
    cout << "threshold of ER = " << thresholdER << endl;
    cout << "threshold of MEM = " << thresholdMEM << endl;
    cout << "initial value of T = " << Ti << endl;
    cout << "final stopping threshold of T = " << Tf << endl;
    cout << "standard cell path: " << standCellPath << endl;
    cout << "output path: " << outpPath << endl;
    cout << "*************************************************" << endl << endl;
}


ALSMan::ALSMan(ALSOpt & opt): isSign(opt.isSign), enableFastErrEst(opt.enableFastErrEst), sourceSeed(opt.sourceSeed), seed(0), lacType(opt.lacType), distrType(opt.distrType), nFrame(opt.nFrame), nFrame4ResubGen(opt.nFrame4ResubGen), maxCandResub(opt.maxCandResub), nThread(opt.nThread), maxLevelDiff(INT_MAX), round(0), maxDelay(DBL_MAX), accNet(NetMan(opt.pNtk, true)), standCellPath(opt.standCellPath), outpPath(opt.outpPath), thresholdER(opt.thresholdER), thresholdMEM(opt.thresholdMEM), Tcur(opt.Ti), Tf(opt.Tf), NC(0) {
    if (accNet.GetNetType() == NET_TYPE::GATE) {
        cout << "convert gate netlist into AIG" << endl;
        accNet.Comm("st; compress2rs; logic; sop; ps;");
    }
    randGen.seed(sourceSeed);
}


void ALSMan::Run() {
    assert(lacType == LAC_TYPE::RESUB);

    // initialize
    cout << endl << "******************** init status ********************" << endl;
    assert(maxDelay == DBL_MAX);
    maxDelay = Eval(accNet, 0.0, 0.0, true, true);
    cout << "max delay = " << maxDelay << endl;
    accNet.Comm("st; logic; sop; ps;");
    auto currNet = accNet;
    cout << "*****************************************************" << endl << endl;

    auto start = chrono::system_clock::now();
    // double err = 0.0;
    int maxPOmag = 0;
    int NC = 0;

    // single selection
    while (true) {
        cout << "------------------- round " << ++round << "-------------------" << endl;
        maxPOmag = ApplyTheBestLAC(currNet);
        auto duration = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start);
        cout << "actual runtime = " << double(duration.count()) * chrono::microseconds::period::num / chrono::microseconds::period::den << " sec" << endl;
        cout << "------------------------------------------------" << endl << endl;
        if (maxPOmag == -1){
            break;
        } else {
            Tcur = Tcur * std::pow(0.8 * thresholdER, std::log2(1+NC));
            if((double)maxPOmag > thresholdMEM){
                NC = 0;
            } else {
                NC++;
            }
            if (Tcur < Tf){
                Tcur = Tf;
            }
        }
    }
}


int ALSMan::ApplyTheBestLAC(NetMan & net) {
    cout << "current " << "T" << " = " << Tcur << endl;
    // backup network
    NetMan& backNet = net;

    // use new seed
    seed = NewSeed();
    auto backER = CalcErr(accNet, net, isSign, seed, nFrame, METR_TYPE::ER, distrType);
    auto backMEM = CalcErr(accNet, net, isSign, seed, nFrame, METR_TYPE::MAXED, distrType);
    cout << "base " << "ER" << " = " << backER << endl;
    cout << "base " << "MEM" << " = " << backMEM << endl;
    if (DoubleGreat(backER, thresholdER)) {
        Eval(backNet, backER, backMEM, true);
        cout << "WARNING: exceed error bound due to unstable " << METR_TYPE::ER << " measurement" << endl;
        return -1;
    }
    
    // create constant nodes
    net.CreateConst(true);

    // get target nodes
    auto nodes = net.TopoSortWithIds();

    // generate LACs
    LACMan lacMan(lacType, nThread);
    lacMan.Gen012ResubLACsPro(net, nodes, seed, maxLevelDiff, nFrame4ResubGen, maxCandResub);
    cout << "#lacs = " << lacMan.GetLacNum() << endl;

    // error estimation
    // ER calculation
    // const BigInt uppBound = (BigInt)(BigFlt(nFrame) * BigFlt(errUppBound)) + 8192;
    // BigInt backErrInt = (BigInt)(BigFlt(nFrame) * BigFlt(backErr)) - 1;
    {// this block is for memory management
    VECBEEMan vecbeeMan(isSign, seed, nFrame, METR_TYPE::ER, lacType, distrType, nThread);
    vecbeeMan.BatchErrEstPro(accNet, net, lacMan, enableFastErrEst);
    }

    bool pickFlag = false;
    // apply best LAC
    assert(lacType == LAC_TYPE::RESUB);
    double tempER, tempMEM;
    LACPtr pBestLac = nullptr;
    std::vector<LACPtr> pCandLACs = lacMan.GetCandLACswithERMEM(net, thresholdER, thresholdMEM, Tcur, nFrame);
    for (ll i = pCandLACs.size() - 1; i >= 0; i--) {
        auto pLac = pCandLACs[i];
        auto tempNet = net;
        ApplyLacPro(tempNet, pLac, false);
        tempER = CalcErr(accNet, tempNet, isSign, seed, nFrame, METR_TYPE::ER, distrType);
        tempMEM = CalcErr(accNet, tempNet, isSign, seed, nFrame, METR_TYPE::MAXED, distrType);
        if (DoubleLessEqual(tempER, thresholdER) && DoubleLessEqual(tempMEM, thresholdMEM)){
            cout << "current " << "ER" << " = " << tempER << endl;
            cout << "current " << "MEM" << " = " << tempMEM << endl;
            pBestLac = pLac;
            ApplyLacPro(net, pBestLac, true);
            pickFlag = true;
            break;
        }
    }
    
    // ApplyLacPro(net, pLac, false);

    // get error
    // double err = CalcErr(accNet, net, isSign, seed, nFrame, metrType, distrType);
    // cout << "current " << metrType << " = " << err << endl;

    if (pickFlag){
        // check error estimation
        auto estER = double(BigFlt(pBestLac->GetER()) / BigFlt(nFrame));
        if (!enableFastErrEst && !DoubleEqual(estER, tempER, 1e-4)) {
            cout << "================== WARNING: wrong error estimation ================" << endl;
            cout << setprecision(10) << estER << "\t" << tempER << endl;
            assert(0);
        }

        // simplify without errors
        const ll SYNTH_ROUND = 10;
        if (round % SYNTH_ROUND == 0 || (backER > 0.5 * thresholdER && backMEM > 0.5 * thresholdMEM)){
            ExactSimpl(net);
        } else {
            net.CleanUp();
            net.MergeConst();
            net.PrintStat();
        }

        // measure, synthesis & mapping, output
        // const int EVAL_ROUND = 10;
        const int EVAL_ROUND = 5;
        if (round % EVAL_ROUND == 0 || tempER > 0.5 * thresholdER){
            Eval(net, tempER, tempMEM);}
        return pBestLac->GetMaxPOId();
        // else {
        //     net = backNet;
        //     Eval(backNet, backER, true);
        // }
    } else {
        net = backNet;
        Eval(backNet, backER, backMEM, true);
        return -1;
    }
}

unsigned ALSMan::NewSeed() {
    boost::uniform_int <> unDistr(numeric_limits <int>::min(), numeric_limits <int>::max());
    unsigned _seed = static_cast <unsigned> (unDistr(randGen));
    cout << "new seed = " << _seed << endl;
    return _seed;
}


void ALSMan::ApplyLacPro(NetMan & net, std::shared_ptr <LAC> pLac, bool print) {
    if (lacType == LAC_TYPE::RESUB) {
        assert(net.GetNetType() == NET_TYPE::SOP);
        net.GetLev();
        auto pSpecLac = dynamic_pointer_cast <ResubLAC> (pLac);
        auto targId = pSpecLac->GetTargId();
        auto faninIds = pSpecLac->GetDivIds();
        auto sop = pSpecLac->GetSop();
        if (print) {
            cout << "replace " << net.GetObj(targId);
            cout << "(l=" << net.GetObjLev(targId) << ") with old fanins (";
            for (ll i = 0; i < net.GetFaninNum(targId); ++i)
                cout << net.GetFaninId(targId, i) << "(l=" << net.GetObjLev(net.GetFanin(targId, i)) << "),";
            cout << ")";
            cout << " by ";
            cout << "(";
            for (const auto & faninId: faninIds)
                cout << faninId << "(l=" << net.GetObjLev(faninId) << "),";
            cout << ")";
            cout << " with estimated ER " << double(BigFlt(pSpecLac->GetER()) / BigFlt(nFrame)) << endl;
            cout << " with estimated MEM " << double(BigFlt(pSpecLac->GetMEM()) / BigFlt(nFrame)) << endl;
            cout << " using function:" << endl;
            cout << sop;
        }

        auto consts = net.CreateConst();
        if (sop == " 0\n") {
            net.Replace(targId, consts.first);
            net.PropagateConst(consts.first, print);
        }
        else if (sop == " 1\n") {
            net.Replace(targId, consts.second);
            net.PropagateConst(consts.second, print);
        }
        else if (sop == "1 1\n") {
            assert(faninIds.size() == 1);
            net.Replace(targId, faninIds[0]);
        }
        else if (sop == "0 1\n") {
            assert(faninIds.size() == 1);
            net.ReplaceByComplementedObj(targId, faninIds[0]);
        }
        else {
            auto newNodeId = net.CreateNodeAIG(faninIds, sop);
            net.Replace(targId, newNodeId);
        }
    }
    else
        assert(0);
}



void ALSMan::ExactSimpl(NetMan & net) {
    cout << endl << "******************** simplify ********************" << endl;
    cout << "before simplification: ";
    net.PrintStat();

    cout << "after simplification: ";
    if (net.GetNetType() == NET_TYPE::GATE) {
        net.SynthAndMap(maxDelay, false);
    }
    else {
        net.Comm("st; compress2rs; logic; sop; ps;");
        // net.SynthWithResyn2Comm();
    }
    net.MergeConst();
    cout << "**********************************************************" << endl << endl;
}


double ALSMan::Eval(NetMan& net, double errER, double errMEM, bool useYosys, bool IsInitialCircuit) {
    useYosys = false;
    assert(net.GetNetType() == NET_TYPE::SOP);

    // measure and output SOP
    ostringstream oss("");
    oss << outpPath << round << "_" << net.GetNet()->pName << "_" << METR_TYPE::ER << "_" << errER << "_" << METR_TYPE::MAXED << "_" << errMEM << "_size_" << net.GetArea() << "_depth_" << net.GetDelay();
    net.WriteBlif(oss.str() + ".blif");

    // synthesize and technology mapping with ABC
    static double recArea = numeric_limits<double>::max();
    static double recDelay = numeric_limits<double>::max();
    double tempNetArea = DBL_MAX, tempNetDelay = DBL_MAX;
    {
        auto tempNet = net;
        if (IsInitialCircuit)
            tempNet.Comm("st; dch; amap;");
            // tempNet.Comm("st; map;"); // for EPFL only, because the initial circuit is delay optimized
        else
            tempNet.Compile(maxDelay);
            // tempNet.CompileNew(maxDelay); // for EPFL only, because the initial circuit is delay optimized
        // update best
        tempNetArea = tempNet.GetArea();
        tempNetDelay = tempNet.GetDelay();
        if (DoubleLess(tempNetArea, recArea) || 
            (DoubleEqual(tempNetArea, recArea) && DoubleLess(tempNetDelay, recDelay)) ) {
            recArea = tempNetArea;
            recDelay = tempNetDelay;
        }
    }

    // synthesize and technology mapping with Yosys
    if (!IsInitialCircuit && useYosys) { // (optional,) for obtaining better results
        auto tempNet= net;
        tempNet.CompileWithYosys(standCellPath);
        tempNetArea = tempNet.GetArea();
        tempNetDelay = tempNet.GetDelay();
        if (DoubleLess(tempNetDelay, maxDelay) || DoubleGreat(recDelay, maxDelay)) { 
            if (DoubleLess(tempNetArea, recArea) || 
            (DoubleEqual(tempNetArea, recArea) && DoubleLess(tempNetDelay, recDelay)) ) {
                recArea = tempNetArea;
                recDelay = tempNetDelay;
            }
        }
    }

    // output and return
    cout << "current best: area = " << recArea << ", delay = " << recDelay << endl;
    return recDelay;
}


static void AppendNet(Abc_Ntk_t* pResNtk, Abc_Ntk_t* pNtkAcc, Abc_Ntk_t* pNtkApp, Abc_Ntk_t* pNtkMit, int netMark, RETURN_VAR IntVect& miterId2AppId, RETURN_VAR IntVect& appId2MiterId) {
    // init
    // netMark = 0, accNet; netMark = 1, appNet; netMark = 2, mitNet;
    Abc_Ntk_t* pNtkDeal = nullptr;
    if (netMark == 0)
        pNtkDeal = pNtkAcc;
    else if (netMark == 1)
        pNtkDeal = pNtkApp;
    else if (netMark == 2)
        pNtkDeal = pNtkMit;
    else
        assert(0);
    assert(!Abc_NtkIsStrash(pNtkDeal));
    Abc_Obj_t* pObj = nullptr;
    Abc_Obj_t* pFanin = nullptr;
    int i = 0, k = 0;
    Abc_NtkCleanCopy(pNtkDeal);

    // deal with PIs
    if (netMark == 0) {
        Abc_NtkForEachPi(pNtkDeal, pObj, i)
            ABC_NAMESPACE::Abc_NtkDupObj(pResNtk, pObj, 1);
    }
    else if (netMark == 1) {
        Abc_NtkForEachPi(pNtkDeal, pObj, i) {
            auto pPi = ABC_NAMESPACE::Abc_NtkPi(pResNtk, i);
            pObj->pCopy = pPi;
            miterId2AppId[pPi->Id] = pObj->Id;
            appId2MiterId[pObj->Id] = pPi->Id;
        }
    }
    else if (netMark == 2) {
        Abc_NtkForEachPo(pNtkAcc, pObj, i)
            ABC_NAMESPACE::Abc_NtkPi(pNtkDeal, i)->pCopy = ABC_NAMESPACE::Abc_ObjChild0Copy(pObj);
        int nWidth = ABC_NAMESPACE::Abc_NtkPoNum(pNtkAcc);
        Abc_NtkForEachPo(pNtkApp, pObj, i)
            ABC_NAMESPACE::Abc_NtkPi(pNtkDeal, i + nWidth)->pCopy = ABC_NAMESPACE::Abc_ObjChild0Copy(pObj);
    }
    else
        assert(0);
    // duplicate nodes
    Abc_NtkForEachNode(pNtkDeal, pObj, i) {
        if (pObj->pCopy == nullptr) {
            auto pNewNode = ABC_NAMESPACE::Abc_NtkDupObj(pResNtk, pObj, 0);
            if (netMark == 1) {
                miterId2AppId[pNewNode->Id] = pObj->Id;
                appId2MiterId[pObj->Id] = pNewNode->Id;
            }
            if (netMark == 0)
                RenameAbcObj(pObj->pCopy, string(Abc_ObjName(pObj)) + "_acc");
            else if (netMark == 1)
                RenameAbcObj(pObj->pCopy, string(Abc_ObjName(pObj)) + "_app");
            else if (netMark == 2)
                RenameAbcObj(pObj->pCopy, string(Abc_ObjName(pObj)) + "_dev");
            else
                assert(0);
        }
    }
    // reconnect all nodes
    Abc_NtkForEachNode(pNtkDeal, pObj, i) {
        Abc_ObjForEachFanin(pObj, pFanin, k)
            Abc_ObjAddFanin(pObj->pCopy, pFanin->pCopy);
    }
    // deal with POs
    if (netMark == 2) {
        Abc_NtkForEachPo(pNtkDeal, pObj, i)
            ABC_NAMESPACE::Abc_NtkDupObj(pResNtk, pObj, 1);
        Abc_NtkForEachPo(pNtkDeal, pObj, i)
            Abc_ObjAddFanin(pObj->pCopy, ABC_NAMESPACE::Abc_ObjChild0Copy(pObj));
    }
}


static void CreateBehLevDeviation(METR_TYPE metrType, bool isSign, int nBits, const string& fileName) {
    FILE* f = fopen(fileName.c_str(), "w");
    fprintf(f, "module deviation(a, b, f);\n");
    fprintf(f, "parameter width = %d;\n", nBits);
    if (isSign) {
        fprintf(f, "input signed [width - 1: 0] a;\n");
        fprintf(f, "input signed [width - 1: 0] b;\n");
    }
    else {
        fprintf(f, "input [width - 1: 0] a;\n");
        fprintf(f, "input [width - 1: 0] b;\n");
    }
    if (metrType == METR_TYPE::MSE)
        fprintf(f, "output [width * 2 - 1: 0] f;\n");
    else if (metrType == METR_TYPE::MHD) {
        int poWidth = (int)(log2(nBits)) + 1;
        fprintf(f, "output [%d: 0] f;\n", poWidth - 1);
    }
    else
        assert(0);
    
    if (metrType == METR_TYPE::MSE) {
        fprintf(f, "wire [width - 1: 0] diff;\n");
        fprintf(f, "assign diff = (a > b)? (a - b): (b - a);\n");
        fprintf(f, "assign f = diff * diff;\n");
    }
    else if (metrType == METR_TYPE::MHD) {
        fprintf(f, "wire [width - 1: 0] diff;\n");
        fprintf(f, "assign diff = a ^ b;\n");
        fprintf(f, "assign f = 1'b0");
        for (int i = 0; i < nBits; ++i)
            fprintf(f, " + diff[%d]", i);
        fprintf(f, ";\n");
    }
    else
        assert(0);
    fprintf(f, "endmodule\n");
    fclose(f);
}

}

