#pragma once

#include "header.h"
#include "my_util.h"

#include "aig/aig/aig.h"
#include "aig/gia/gia.h"
#include "aig/hop/hop.h"
#include "base/main/main.h"
#include "base/main/mainInt.h"
#include "base/cmd/cmd.h"
#include "base/io/ioAbc.h"
#include "base/abc/abc.h"
#include "bool/bdc/bdc.h"
#include "bool/kit/kit.h"
#include "bool/dec/dec.h"
#include "misc/nm/nm.h"
#include "misc/nm/nmInt.h"
#include "misc/util/abc_global.h"
#include "misc/util/util_hack.h"
#include "map/mio/mio.h"
#include "map/mio/mioInt.h"
#include "map/mapper/mapper.h"
#include "map/mapper/mapperInt.h"
#include "map/scl/scl.h"
#include "map/scl/sclCon.h"
#include "map/scl/sclSize.h"
#include "opt/cut/cut.h"
#include "opt/cut/cutInt.h"
#include "opt/cut/cutList.h"
#include "opt/mfs/mfs.h"
#include "opt/mfs/mfsInt.h"
#include "opt/sim/sim.h"
#include "opt/rwr/rwr.h"
#include "proof/fraig/fraig.h"
#include "proof/ssw/ssw.h"
#include "sat/bsat/satSolver.h"
#include "sat/cnf/cnf.h"

namespace ABC_NAMESPACE {
struct Abc_ManTime_t_ {
    Abc_Time_t     tArrDef;
    Abc_Time_t     tReqDef;
    Vec_Ptr_t  *   vArrs;
    Vec_Ptr_t  *   vReqs;
    Abc_Time_t     tInDriveDef;
    Abc_Time_t     tOutLoadDef;
    Abc_Time_t *   tInDrive;
    Abc_Time_t *   tOutLoad;
};
}

namespace vacsem{
using AbcObj = ABC_NAMESPACE::Abc_Obj_t;
using ObjList = std::list<AbcObj*>;
using ObjSet = std::unordered_set<AbcObj*>;
using ObjVec = std::vector<AbcObj*>;
using ObjQueue = std::queue<AbcObj*>;
using ObjPair = std::pair<AbcObj*, AbcObj*>;


enum class NET_TYPE {
    AIG, GATE, SOP, STRASH
};


enum class ORIENT {
    AREA, DELAY
};


enum class MAP_TYPE {
    LUT, SCL
};


enum class IMPR {
    GOOD, BAD, SAME
};


std::ostream & operator << (std::ostream & os, const NET_TYPE netwType);
std::ostream & operator << (std::ostream & os, const ORIENT orient);
std::ostream & operator << (std::ostream & os, const MAP_TYPE cell);
std::ostream & operator << (std::ostream & os, const IMPR impr);


// call ABC commands
class AbcMan {
private:
    const int LutInp = 6; 

public:
    explicit AbcMan();
    ~AbcMan() = default;
    AbcMan(const AbcMan &) = delete;
    AbcMan(AbcMan &&) = delete;
    AbcMan & operator = (const AbcMan &) = delete;
    AbcMan & operator = (AbcMan &&) = delete;

    void Comm(const std::string & cmd, bool isVerb = false);
    void ReadNet(const std::string & fileName);
    void WriteNet(const std::string & fileName, bool isVerb = false);
    void ReadStandCell(const std::string & fileName);
    void ConvToAig();
    void ConvToGate();
    void ConvToSop();
    void Strash();
    void PrintStat();
    void TopoSort();
    void StatTimeAnal();
    void Synth(ORIENT orient, bool isVerb = false);
    void SynthAndMap(double maxDelay, bool isVerb = false);
    void Sweep();
    std::pair <double, double> Map(MAP_TYPE targ, ORIENT orient, bool isVerb = false);
    std::pair <double, double> Map2(double maxDelay, bool isVerb = false);
    IMPR UpdNetw(double oldArea, double oldDelay, ABC_NAMESPACE::Abc_Ntk_t * oldNtk, double newArea, double newDelay, ORIENT orient);
    NET_TYPE GetNetType(ABC_NAMESPACE::Abc_Ntk_t * pNtk) const;
    double GetArea(ABC_NAMESPACE::Abc_Ntk_t * pNtk) const;
    double GetDelay(ABC_NAMESPACE::Abc_Ntk_t * pNtk) const;
    bool CheckSCLNet(ABC_NAMESPACE::Abc_Ntk_t * pNtk) const;
    ABC_NAMESPACE::Abc_Obj_t * GetTwinNode( ABC_NAMESPACE::Abc_Obj_t * pNode );
    void LoadAlias();

    inline ABC_NAMESPACE::Abc_Frame_t * GetAbcFrame() const {return ABC_NAMESPACE::Abc_FrameGetGlobalFrame();}
    inline ABC_NAMESPACE::Abc_Ntk_t * GetNet() const {return ABC_NAMESPACE::Abc_FrameReadNtk(GetAbcFrame());}
    inline NET_TYPE GetNetType() const {return GetNetType(GetNet());}
    inline double GetArea() const {return GetArea(GetNet());}
    inline double GetDelay() const {return GetDelay(GetNet());}
    inline bool IsLutNetw() const {return GetNetType() != NET_TYPE::GATE && Abc_NtkGetFaninMax(GetNet()) <= LutInp;}
    inline bool UseModernSCL() const {return static_cast <ABC_NAMESPACE::SC_Lib *> (GetAbcFrame()->pLibScl) != nullptr;}
    inline void SetMainNetw(ABC_NAMESPACE::Abc_Ntk_t * pNtk) {assert(pNtk != nullptr); if (pNtk != GetNet()) Abc_FrameReplaceCurrentNetwork(GetAbcFrame(), pNtk);}
};


// call ABC functions
class NetMan: public AbcMan {
private:
    ABC_NAMESPACE::Abc_Ntk_t * pNtk;
    bool isDupl;

public:
    explicit NetMan();
    explicit NetMan(ABC_NAMESPACE::Abc_Ntk_t * p_ntk, bool is_dupl = false);
    explicit NetMan(const std::string & fileName);
    ~NetMan();
    NetMan(const NetMan & net_man);
    NetMan(NetMan && net_man);
    NetMan & operator = (const NetMan & net_man);
    NetMan & operator = (NetMan && net_man);

    // print & check & show
    void Print(bool showFunct = false) const;
    void PrintObjBas(ABC_NAMESPACE::Abc_Obj_t * pObj, std::string && endWith) const;
    void PrintObj(ABC_NAMESPACE::Abc_Obj_t * pObj, bool showFunct = false) const;
    bool IsPIOSame(const NetMan & oth_net) const;
    void Show(const IntVec& nodes, const std::string & fileName, const IntVec& cut) const;
    void Show(const IntVec& nodes, const std::string & fileName, const IntVec& cut, const DblVec& dat, double bound) const;

    // get sub-structure
    std::vector <ABC_NAMESPACE::Abc_Obj_t * > CalcTopoOrd() const;
    std::vector <int> CalcTopoOrdOfIds() const;
    void CalcTopoOrdOfIdsRec(ABC_NAMESPACE::Abc_Obj_t * pObj, std::vector <int> & nodes) const; 
    std::vector <ABC_NAMESPACE::Abc_Obj_t *> GetTFI(ABC_NAMESPACE::Abc_Obj_t * pObj) const;
    void GetTFIRec(ABC_NAMESPACE::Abc_Obj_t * pObj, std::vector <ABC_NAMESPACE::Abc_Obj_t *> & nodes) const;
    std::vector <int> GetTFI(ABC_NAMESPACE::Abc_Obj_t * pObj, const std::set <int> & critGraph) const;
    void GetTFIRec(ABC_NAMESPACE::Abc_Obj_t * pObj, std::vector <int> & objs, const std::set <int> & critGraph) const;
    std::vector <ABC_NAMESPACE::Abc_Obj_t *> GetTFO(ABC_NAMESPACE::Abc_Obj_t * pObj) const;
    void GetTFORec(ABC_NAMESPACE::Abc_Obj_t * pObj, std::vector <ABC_NAMESPACE::Abc_Obj_t *> & nodes) const;
    std::vector <int> GetTFO(ABC_NAMESPACE::Abc_Obj_t * pObj, const std::set <int> & critGraph) const;
    void GetTFORec(ABC_NAMESPACE::Abc_Obj_t * pObj, std::vector <int> & objs, const std::set <int> & critGraph) const;
    int GetNodeMffcSize(ABC_NAMESPACE::Abc_Obj_t * pNode) const;
    std::vector <ABC_NAMESPACE::Abc_Obj_t *> GetNodeMffc(ABC_NAMESPACE::Abc_Obj_t * pNode) const;

    // modify network
    std::pair <int, int> GetConstId(bool isVerb = false);
    std::pair <int, int> CreateConst(bool isVerb = false);
    void MergeConst();
    void TopoSort();
    void Comm(const std::string& cmd, bool isVerb = false);
    void Sweep();
    void ConvToSopWithTwoInps();
    void SimpOpt();
    void Synth(ORIENT orient, bool isVerb = false);
    void SynthAndMap(double maxDelay = std::numeric_limits<double>::max(), bool isVerb = false);
    void SATSweep();
    std::pair <double, double> Map(MAP_TYPE targ, ORIENT orient, bool isVerb = false);
    std::vector <int> TempRepl(ABC_NAMESPACE::Abc_Obj_t * pTS, ABC_NAMESPACE::Abc_Obj_t * pSS);
    void Recov(std::vector <int> & replTrace, bool isVerb = false);
    void PatchFanin(ABC_NAMESPACE::Abc_Obj_t * pObj, int iFanin, ABC_NAMESPACE::Abc_Obj_t * pFaninOld, ABC_NAMESPACE::Abc_Obj_t * pFaninNew);
    void Trunc(int truncBit);
    bool CleanUp();
    bool ProcHalfAndFullAdd();
    void ProcHalfAndFullAddNew();
    ABC_NAMESPACE::Abc_Obj_t* CreateNode(const std::vector<ABC_NAMESPACE::Abc_Obj_t*>& pFanins, const std::string& sop);
    int CreateNode(const std::vector<int>& faninIds, const std::string& sop);
    ABC_NAMESPACE::Abc_Obj_t * CreateGate(std::vector <ABC_NAMESPACE::Abc_Obj_t *> && fanins, const std::string & gateName);
    ABC_NAMESPACE::Abc_Obj_t * DupObj(ABC_NAMESPACE::Abc_Obj_t * pObj, const char* pSuff);
    void LimFanout();
    
    // get properties of network
    inline ABC_NAMESPACE::Abc_Ntk_t * GetNet() const {return pNtk;}
    inline NET_TYPE GetNetType() const {return AbcMan::GetNetType(GetNet());}
    inline bool IsStrash() const {return GetNetType() == NET_TYPE::STRASH;}
    inline int Check() const {return ABC_NAMESPACE::Abc_NtkDoCheck(GetNet());}
    inline double GetArea() const {return AbcMan::GetArea(GetNet());}
    inline double GetDelay() const {return AbcMan::GetDelay(GetNet());}
    inline void WriteNet(const std::string & fileName, bool isVerb = false) {AbcMan::SetMainNetw(ABC_NAMESPACE::Abc_NtkDup(GetNet())); AbcMan::WriteNet(fileName, isVerb);}
    inline void WriteNet(const std::string && fileName, bool isVerb = false) {AbcMan::SetMainNetw(ABC_NAMESPACE::Abc_NtkDup(GetNet())); AbcMan::WriteNet(fileName, isVerb);}
    inline void PrintStat() {AbcMan::SetMainNetw(ABC_NAMESPACE::Abc_NtkDup(GetNet())); AbcMan::PrintStat();}
    inline bool IsInTopoOrd() const {auto type = GetNetType(); assert(type == NET_TYPE::AIG || type == NET_TYPE::GATE || type == NET_TYPE::SOP); return ABC_NAMESPACE::Abc_SclCheckNtk(GetNet(), 0);}
    inline bool CheckSCLNet() const {return AbcMan::CheckSCLNet(pNtk);}

    // convert network representation
    inline void ConvToSop() {ABC_NAMESPACE::Abc_NtkToSop(pNtk, -1, ABC_INFINITY);}
    inline void Strash() {assert(isDupl); auto pNtkAig = ABC_NAMESPACE::Abc_NtkStrash(pNtk, 0, 1, 0); ABC_NAMESPACE::Abc_NtkDelete(pNtk); pNtk = pNtkAig;}

    // get PIs & POs
    inline int GetPiNum() const {return ABC_NAMESPACE::Abc_NtkPiNum(GetNet());}
    inline int GetObjNumMax() const {return ABC_NAMESPACE::Abc_NtkObjNumMax(GetNet());}
    inline int GetObjNum() const {return ABC_NAMESPACE::Abc_NtkObjNum(GetNet());}
    inline int GetPoNum() const {return ABC_NAMESPACE::Abc_NtkPoNum(GetNet());}
    inline int GetNodeNum() const {return ABC_NAMESPACE::Abc_NtkNodeNum(GetNet());}
    inline ABC_NAMESPACE::Abc_Obj_t* GetPi(int i) const {return ABC_NAMESPACE::Abc_NtkPi(GetNet(), i);}
    inline ABC_NAMESPACE::Abc_Obj_t* GetObj(int i) const {return ABC_NAMESPACE::Abc_NtkObj(GetNet(), i);}
    inline ABC_NAMESPACE::Abc_Obj_t* GetPo(int i) const {return ABC_NAMESPACE::Abc_NtkPo(GetNet(), i);}
    inline int GetIdMaxPlus1() const {return ABC_NAMESPACE::Abc_NtkObjNumMax(GetNet());}
    inline int GetIdMax() const {return ABC_NAMESPACE::Abc_NtkObjNumMax(GetNet()) - 1;}
    inline int GetId(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjId(pObj);}
    inline int GetPiId(int i) const {return GetId(GetPi(i));}
    inline int GetPoId(int i) const {return GetId(GetPo(i));}
    inline ABC_NAMESPACE::Abc_Obj_t* GetPoDriv(int i) const {return ABC_NAMESPACE::Abc_ObjFanin0(GetPo(i));}
    inline int GetPoDrivId(int i) const {return GetId(GetPoDriv(i));}

    // get/set properties of objects
    inline bool IsObj(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return pObj != nullptr;}
    inline bool IsObj(int id) const {return IsObj(GetObj(id));}
    inline bool IsNode(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return pObj != nullptr && ABC_NAMESPACE::Abc_ObjIsNode(pObj);}
    inline bool IsNode(int id) const {return IsNode(GetObj(id));}
    inline bool IsObjPi(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjIsPi(pObj);}
    inline bool IsObjPi(int id) const {return IsObjPi(GetObj(id));}
    inline bool IsObjPo(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjIsPo(pObj);}
    inline bool IsObjPo(int id) const {return IsObjPo(GetObj(id));}
    inline bool IsConst(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return IsNode(pObj) && ABC_NAMESPACE::Abc_NodeIsConst(pObj);}
    inline bool IsConst(int id) const {return IsConst(GetObj(id));}
    inline bool IsConst0(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return IsNode(pObj) && ABC_NAMESPACE::Abc_NodeIsConst0(pObj);}
    inline bool IsConst0(int id) const {return IsConst0(GetObj(id));}
    inline bool IsConst1(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return IsNode(pObj) && ABC_NAMESPACE::Abc_NodeIsConst1(pObj);}
    inline bool IsConst1(int id) const {return IsConst1(GetObj(id));}
    inline bool IsInv(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return IsNode(pObj) && ABC_NAMESPACE::Abc_NodeIsInv(pObj);}
    inline bool IsInv(int id) const {return IsNode(GetObj(id)) && ABC_NAMESPACE::Abc_NodeIsInv(GetObj(id));}
    inline bool IsCompl(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjIsComplement(pObj);}
    inline bool IsCompl(int id) const {return IsCompl(GetObj(id));}
    inline bool IsFi0Compl(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjFaninC0(pObj);}
    inline bool IsFi0Compl(int id) const {return IsFi0Compl(GetObj(id));}
    inline bool IsFi1Compl(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjFaninC1(pObj);}
    inline bool IsFi1Compl(int id) const {return IsFi1Compl(GetObj(id));}
    inline std::string GetName(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return std::string(ABC_NAMESPACE::Abc_ObjName(pObj));}
    inline std::string GetName(int i) const {return GetName(GetObj(i));}
    inline std::string GetPiName(int i) const {return std::string(ABC_NAMESPACE::Abc_ObjName(GetPi(i)));}
    inline std::string GetPoName(int i) const {return std::string(ABC_NAMESPACE::Abc_ObjName(GetPo(i)));}
    inline std::string GetSop(ABC_NAMESPACE::Abc_Obj_t * pNode) const {return std::string(static_cast <char *> (pNode->pData));}
    inline std::string GetSop(int id) const {return GetSop(GetObj(id));}
    inline int GetNodeMffcSize(int i) const {return GetNodeMffcSize(GetObj(i));}
    inline void SetNetNotTrav() const {ABC_NAMESPACE::Abc_NtkIncrementTravId(GetNet());}
    inline bool GetObjTrav(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_NodeIsTravIdCurrent(pObj);}
    inline bool GetObjTrav(int id) const {return GetObjTrav(GetObj(id));}
    inline void SetObjTrav(ABC_NAMESPACE::Abc_Obj_t * pObj) const {ABC_NAMESPACE::Abc_NodeSetTravIdCurrent(pObj);}
    inline void SetObjTrav(int id) const {SetObjTrav(GetObj(id));}
    inline void PrintObj(int id, bool showFunct = false) const {PrintObj(GetObj(id), showFunct);}
    inline void PrintObjBas(int id, std::string && endWith = "") const {PrintObjBas(GetObj(id), std::move(endWith));}

    // get fanins & fanouts
    inline int GetFaninNum(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjFaninNum(pObj);}
    inline int GetFaninNum(int id) const {return GetFaninNum(GetObj(id));}
    inline ABC_NAMESPACE::Abc_Obj_t * GetFanin(ABC_NAMESPACE::Abc_Obj_t * pObj, int i) const {return ABC_NAMESPACE::Abc_ObjFanin(pObj, i);}
    inline ABC_NAMESPACE::Abc_Obj_t * GetFanin(int id, int i) const {return GetFanin(GetObj(id), i);}
    inline int GetFaninId(ABC_NAMESPACE::Abc_Obj_t * pObj, int i) const {return GetId(GetFanin(pObj, i));}
    inline int GetFaninId(int nodeId, int i) const {return GetFaninId(GetObj(nodeId), i);}
    inline int GetFanoutNum(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjFanoutNum(pObj);}
    inline int GetFanoutNum(int id) const {return GetFanoutNum(GetObj(id));}
    inline ABC_NAMESPACE::Abc_Obj_t * GetFanout(ABC_NAMESPACE::Abc_Obj_t * pObj, int i) const {return ABC_NAMESPACE::Abc_ObjFanout(pObj, i);}
    inline ABC_NAMESPACE::Abc_Obj_t * GetFanout(int id, int i) const {return GetFanout(GetObj(id), i);}
    inline int GetFanoutId(ABC_NAMESPACE::Abc_Obj_t * pObj, int i) const {return GetId(GetFanout(pObj, i));}
    inline int GetFanoutId(int id, int i) const {return GetFanoutId(GetObj(id), i);}
    inline std::vector <ABC_NAMESPACE::Abc_Obj_t *> GetFanoutsThatArePos(ABC_NAMESPACE::Abc_Obj_t * pObj) {
        std::vector <ABC_NAMESPACE::Abc_Obj_t *> pos;
        for (int i = 0; i < GetFanoutNum(pObj); ++i) {
            auto fanout = GetFanout(pObj, i);
            if (IsObjPo(fanout))
                pos.emplace_back(fanout);
        }
        return pos;
    }
    inline std::vector <ABC_NAMESPACE::Abc_Obj_t *> GetFanoutsThatArePos(int id) {return GetFanoutsThatArePos(GetObj(id));}

    // get timing information
    inline int GetLev() const {return ABC_NAMESPACE::Abc_NtkLevel(GetNet());}
    inline int GetObjLev(ABC_NAMESPACE::Abc_Obj_t * pObj) const {
        if (IsObjPo(pObj)) {
            assert(GetFaninNum(pObj) == 1);
            return ABC_NAMESPACE::Abc_ObjLevel(GetFanin(pObj, 0)) + 1;
        }
        else
            return ABC_NAMESPACE::Abc_ObjLevel(pObj);
    }
    inline int GetObjLev(int i) const {return ABC_NAMESPACE::Abc_ObjLevel(GetObj(i));}
    inline void SetObjLev(ABC_NAMESPACE::Abc_Obj_t* pObj, int lev) {ABC_NAMESPACE::Abc_ObjSetLevel(pObj, lev);}
    inline void SetObjLev(int i, int lev) {SetObjLev(GetObj(i), lev);}
    inline double GetObjArrTime(ABC_NAMESPACE::Abc_Obj_t * pObj) const {
        if (IsObjPo(pObj)) {
            assert(GetFaninNum(pObj) == 1);
            return GetObjArrTime(GetFanin(pObj, 0));
        }
        if (IsObjPi(pObj))
            return 0.0;
        if (IsConst(pObj))
            return 0.0;
        auto type = GetNetType();
        if (type == NET_TYPE::AIG || type == NET_TYPE::SOP || type == NET_TYPE::STRASH)
            return ABC_NAMESPACE::Abc_ObjLevel(pObj);
        if (type == NET_TYPE::GATE) {
            if (!UseModernSCL())
                return static_cast <ABC_NAMESPACE::Abc_Time_t *> (pObj->pNtk->pManTime->vArrs->pArray[pObj->Id])->Rise;
            else
                return pObj->dTemp;
        }
        assert(0);
        return 0.0;
    }
    inline double GetObjArrTime(ll id) const {return GetObjArrTime(GetObj(id));} 
    inline double GetGateDelay(ABC_NAMESPACE::Abc_Obj_t * pNode) const {assert(!UseModernSCL()); return ABC_NAMESPACE::Mio_GateReadDelayMax(static_cast <ABC_NAMESPACE::Mio_Gate_t *> (pNode->pData));}
    inline double GetGateDelay(int id) const {return GetGateDelay(GetObj(id));}
    inline double GetInvDelay() const {return ABC_NAMESPACE::Mio_LibraryReadDelayInvMax(static_cast <ABC_NAMESPACE::Mio_Library_t *> (GetNet()->pManFunc));}
    inline std::string GetGateName(ABC_NAMESPACE::Abc_Obj_t * pNode) const {
        assert(NetMan::GetNetType() == NET_TYPE::GATE);
        if (IsNode(pNode))
            return std::string(ABC_NAMESPACE::Mio_GateReadName(static_cast <ABC_NAMESPACE::Mio_Gate_t *> (pNode->pData)));
        else
            return std::string("");
    }
    inline double GetObjDelay(AbcObj * pObj) const {
        if (IsObjPo(pObj) || IsObjPi(pObj))
            return 0.0;
        auto type = GetNetType();
        if (type == NET_TYPE::AIG || type == NET_TYPE::SOP || type == NET_TYPE::STRASH)
            return 1.0;
        if (type == NET_TYPE::GATE) {
            assert(!UseModernSCL());
            return GetGateDelay(pObj);
        }
        assert(0);
        return 0.0;
    }
    inline double GetObjDelay(int id) const {return GetObjDelay(GetObj(id));}
    inline double GetMostCritArrTimeOfFanins(AbcObj* pObj) const {
        double mostCritArrTime = -std::numeric_limits<double>::max();
        AbcObj* pFanin = nullptr;
        int i = 0;
        Abc_ObjForEachFanin(pObj, pFanin, i)
            mostCritArrTime = std::max(mostCritArrTime, GetObjArrTime(pFanin));
        return mostCritArrTime;
    }
    inline double GetMostCritArrTimeOfFanins(int id) const {return GetMostCritArrTimeOfFanins(GetObj(id));}

    // modify network
    inline ABC_NAMESPACE::Abc_Ntk_t* StartSopNet() {pNtk = ABC_NAMESPACE::Abc_NtkAlloc(ABC_NAMESPACE::ABC_NTK_LOGIC, ABC_NAMESPACE::ABC_FUNC_SOP, 1); return pNtk;}
    inline ABC_NAMESPACE::Abc_Ntk_t* StartStrashNet() {pNtk = ABC_NAMESPACE::Abc_NtkAlloc(ABC_NAMESPACE::ABC_NTK_STRASH, ABC_NAMESPACE::ABC_FUNC_AIG, 1); return pNtk;}
    inline void AddFanin(ABC_NAMESPACE::Abc_Obj_t* pObj, ABC_NAMESPACE::Abc_Obj_t* pFanin) {ABC_NAMESPACE::Abc_ObjAddFanin(pObj, pFanin);}
    inline void Replace(ABC_NAMESPACE::Abc_Obj_t * pTS, ABC_NAMESPACE::Abc_Obj_t * pSS) {ABC_NAMESPACE::Abc_ObjReplace(pTS, pSS);}
    inline void Replace(int tsId, int ssId) {Replace(GetObj(tsId), GetObj(ssId));}
    inline IntVec TempRepl(int tsId, int ssId) {return TempRepl(GetObj(tsId), GetObj(ssId));}
    inline void TransfFanout(ABC_NAMESPACE::Abc_Obj_t * pTS, ABC_NAMESPACE::Abc_Obj_t * pSS) {ABC_NAMESPACE::Abc_ObjTransferFanout(pTS, pSS);}
    inline void TransfFanout(int tsId, int ssId) {TransfFanout(GetObj(tsId), GetObj(ssId));}
    inline void DelObj(ABC_NAMESPACE::Abc_Obj_t * pObj) {ABC_NAMESPACE::Abc_NtkDeleteObj(pObj);}
    inline void DelObj(int id) {DelObj(GetObj(id));}
    inline void DelObjRec(ABC_NAMESPACE::Abc_Obj_t * pObj) {ABC_NAMESPACE::Abc_NtkDeleteObj_rec(pObj, 1);}
    inline void DelObjRec(int id) {DelObjRec(GetObj(id));}
    inline ABC_NAMESPACE::Abc_Obj_t* CreateNode(const char* pName) {auto pNode = Abc_NtkCreateNode(pNtk); Rename(pNode, pName); return pNode;}
    inline ABC_NAMESPACE::Abc_Obj_t* CreateInv(ABC_NAMESPACE::Abc_Obj_t * pFanin) {assert(pFanin->pNtk == pNtk); return Abc_NtkCreateNodeInv(pNtk, pFanin);}
    inline int CreateInv(int faninId) {return GetId(CreateInv(GetObj(faninId)));}
    inline ABC_NAMESPACE::Abc_Obj_t* CreateBuf(ABC_NAMESPACE::Abc_Obj_t * pFanin) {assert(pFanin->pNtk == pNtk); return Abc_NtkCreateNodeBuf(pNtk, pFanin);}
    inline int CreateBuf(int faninId) {return GetId(CreateBuf(GetObj(faninId)));}
    inline ABC_NAMESPACE::Abc_Obj_t* CreateAnd(ABC_NAMESPACE::Abc_Obj_t* pA, ABC_NAMESPACE::Abc_Obj_t* pB) {assert(pA->pNtk == pNtk && pB->pNtk == pNtk); return CreateNode(std::vector<ABC_NAMESPACE::Abc_Obj_t*>({pA, pB}), "11 1\n");}
    inline int CreateAnd(int a, int b) {return GetId(CreateAnd(GetObj(a), GetObj(b)));}
    inline ABC_NAMESPACE::Abc_Obj_t* CreateOr(ABC_NAMESPACE::Abc_Obj_t* pA, ABC_NAMESPACE::Abc_Obj_t* pB) {assert(pA->pNtk == pNtk && pB->pNtk == pNtk); return CreateNode(std::vector<ABC_NAMESPACE::Abc_Obj_t*>({pA, pB}), "00 0\n");}
    inline int CreateOr(int a, int b) {return GetId(CreateOr(GetObj(a), GetObj(b)));}
    inline ABC_NAMESPACE::Abc_Obj_t* CreateXor(ABC_NAMESPACE::Abc_Obj_t* pA, ABC_NAMESPACE::Abc_Obj_t* pB) {assert(pA->pNtk == pNtk && pB->pNtk == pNtk); return CreateNode(std::vector<ABC_NAMESPACE::Abc_Obj_t*>({pA, pB}), "01 1\n10 1\n");}
    inline int CreateXor(int a, int b) {return GetId(CreateXor(GetObj(a), GetObj(b)));}
    inline ABC_NAMESPACE::Abc_Obj_t* CreateXnor(ABC_NAMESPACE::Abc_Obj_t* pA, ABC_NAMESPACE::Abc_Obj_t* pB) {assert(pA->pNtk == pNtk && pB->pNtk == pNtk); return CreateNode(std::vector<ABC_NAMESPACE::Abc_Obj_t*>({pA, pB}), "00 1\n11 1\n");}
    inline int CreateXnor(int a, int b) {return GetId(CreateXnor(GetObj(a), GetObj(b)));}
    inline ABC_NAMESPACE::Abc_Obj_t* CreatePo(ABC_NAMESPACE::Abc_Obj_t* pFanin, const char* pName) {auto pPo = ABC_NAMESPACE::Abc_NtkCreatePo(pNtk); AddFanin(pPo, pFanin); Abc_ObjAssignName(pPo, const_cast<char*>(pName), nullptr); return pPo;}
    inline ABC_NAMESPACE::Abc_Obj_t* CreatePi(const char* pName) {auto pPi = ABC_NAMESPACE::Abc_NtkCreatePi(pNtk); Abc_ObjAssignName(pPi, const_cast<char*>(pName), nullptr); return pPi;}
    inline void Rename(ABC_NAMESPACE::Abc_Obj_t* pObj, const char* pName) {Abc_ObjAssignName(pObj, const_cast<char*>(pName), nullptr);}
    inline void Rename(int id, const char* pName) {Rename(GetObj(id), pName);}
    inline void RenameWithSuff(ABC_NAMESPACE::Abc_Obj_t* pObj, const char* pSuff) {Abc_ObjNameSuffix(pObj, const_cast<char*>(pSuff));}
    inline void RenameWithSuff(int id, const char* pSuff) {RenameWithSuff(GetObj(id), pSuff);}
};


void GlobStartAbc();
void GlobStopAbc();


static inline std::ostream & operator << (std::ostream & os, ABC_NAMESPACE::Abc_Obj_t * pObj) {
    assert(pObj != nullptr);
    os << ABC_NAMESPACE::Abc_ObjName(pObj) << "(" << ABC_NAMESPACE::Abc_ObjId(pObj) << ")";
    return os;
}


inline void RenameAbcObj(ABC_NAMESPACE::Abc_Obj_t* pObj, const std::string& name) {
    auto pNameMan = pObj->pNtk->pManName;
    auto pEntry = ABC_NAMESPACE::Nm_ManTableLookupId(pNameMan, pObj->Id);
    if (pEntry != nullptr)
        ABC_NAMESPACE::Nm_ManDeleteIdName(pNameMan, pObj->Id);
    ABC_NAMESPACE::Abc_ObjAssignName(pObj, const_cast<char*>(name.c_str()), nullptr);
}
}