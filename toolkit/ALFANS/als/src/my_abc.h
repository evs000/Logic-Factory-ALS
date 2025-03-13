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
#include "map/amap/amap.h"
#include "map/amap/amapInt.h"
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

namespace alfans {
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


using AbcObjVect = std::vector<ABC_NAMESPACE::Abc_Obj_t *>;
using AbcObjList = std::list<ABC_NAMESPACE::Abc_Obj_t *>;
using AbcObjSet = std::unordered_set<ABC_NAMESPACE::Abc_Obj_t *>;


// call ABC commands
class AbcMan {
private:
    const ll LutInp = 6; 

public:
    explicit AbcMan();
    ~AbcMan() = default;
    AbcMan(const AbcMan &) = delete;
    AbcMan(AbcMan &&) = delete;
    AbcMan & operator = (const AbcMan &) = delete;
    AbcMan & operator = (AbcMan &&) = delete;

    void Comm(const std::string & cmd, bool isVerb = false);
    void ReadNet(const std::string & fileName, bool inpMapVerilog = false);
    void WriteNet(const std::string & fileName, bool isVerb = false);
    void ReadStandCell(const std::string & fileName);
    void ConvToAig();
    void ConvToGate();
    void ConvToSop();
    void ConvToStrash();
    void PrintStat();
    void TopoSort();
    void StatTimeAnal();
    void Synth(ORIENT orient, bool isVerb = false);
    void SynthWithResyn2Comm();
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

    inline ABC_NAMESPACE::Abc_Frame_t * GetAbcFame() const {return ABC_NAMESPACE::Abc_FrameGetGlobalFrame();}
    inline ABC_NAMESPACE::Abc_Ntk_t * GetNet() const {return ABC_NAMESPACE::Abc_FrameReadNtk(GetAbcFame());}
    inline NET_TYPE GetNetType() const {return GetNetType(GetNet());}
    inline double GetArea() const {return GetArea(GetNet());}
    inline double GetDelay() const {return GetDelay(GetNet());}
    inline bool IsLutNetw() const {return GetNetType() != NET_TYPE::GATE && Abc_NtkGetFaninMax(GetNet()) <= LutInp;}
    inline void SetMainNetw(ABC_NAMESPACE::Abc_Ntk_t * pNtk) {assert(pNtk != nullptr); if (pNtk != GetNet()) Abc_FrameReplaceCurrentNetwork(GetAbcFame(), pNtk);}
};


// call ABC functions
class NetMan: public AbcMan {
private:
    ABC_NAMESPACE::Abc_Ntk_t * pNtk;
    bool isDupl;

public:
    explicit NetMan();
    explicit NetMan(ABC_NAMESPACE::Abc_Ntk_t * p_ntk, bool is_dupl = false);
    explicit NetMan(std::string & fileName);
    ~NetMan();
    NetMan(const NetMan & net_man);
    NetMan(NetMan && net_man);
    NetMan & operator = (const NetMan & net_man);
    NetMan & operator = (NetMan && net_man);

    std::pair <ll, ll> GetConstId(bool isVerb = false);
    std::pair <ll, ll> CreateConst(bool isVerb = false);
    void MergeConst();
    void ReArrInTopoOrd();
    std::vector <ABC_NAMESPACE::Abc_Obj_t * > TopoSort() const;
    void TopoSortRec(ABC_NAMESPACE::Abc_Obj_t * pObj, std::vector <ABC_NAMESPACE::Abc_Obj_t *> & nodes) const;
    IntVect TopoSortWithIds() const;
    void TopoSortRecWithIds(ABC_NAMESPACE::Abc_Obj_t* pObj, RETURN_VAR IntVect& nodes) const;

    std::vector <ABC_NAMESPACE::Abc_Obj_t *> GetTFI(ABC_NAMESPACE::Abc_Obj_t * pObj) const;
    void GetTFIRec(ABC_NAMESPACE::Abc_Obj_t * pObj, std::vector <ABC_NAMESPACE::Abc_Obj_t *> & nodes) const;
    std::vector <ll> GetTFI(ABC_NAMESPACE::Abc_Obj_t * pObj, const std::set <ll> & critGraph) const;
    void GetTFIRec(ABC_NAMESPACE::Abc_Obj_t * pObj, std::vector <ll> & objs, const std::set <ll> & critGraph) const;

    std::vector <ABC_NAMESPACE::Abc_Obj_t *> GetTFO(ABC_NAMESPACE::Abc_Obj_t * pObj) const;
    void GetTFORec(ABC_NAMESPACE::Abc_Obj_t * pObj, std::vector <ABC_NAMESPACE::Abc_Obj_t *> & nodes) const;
    std::vector <ll> GetTFO(ABC_NAMESPACE::Abc_Obj_t * pObj, const std::set <ll> & critGraph) const;
    void GetTFORec(ABC_NAMESPACE::Abc_Obj_t * pObj, std::vector <ll> & objs, const std::set <ll> & critGraph) const;
    std::vector <int> GetReachablePOIds(ABC_NAMESPACE::Abc_Obj_t* pObj) const;

    std::vector <ABC_NAMESPACE::Abc_Obj_t *> GetFanins(ABC_NAMESPACE::Abc_Obj_t * pObj) const;
    std::vector <ABC_NAMESPACE::Abc_Obj_t *> GetFanouts(ABC_NAMESPACE::Abc_Obj_t * pObj) const;

    ABC_NAMESPACE::Abc_Obj_t* GetObjByName(const std::string & name, bool considerPO = false) const;

    void Comm(const std::string & cmd, bool isVerb = false);
    void Sweep();
    void ConvToSopWithTwoInps();
    void SynthWithResyn2Comm();
    void SynthWithCompress2rsComm();
    void SynthAndMap(double maxDelay, bool isVerb = false);
    void Compile(double maxDelay);
    void CompileNew(double maxDelay);
    void CompileExtremeArea(double maxDelay);
    void CompileFast4Area();
    void CompileWithYosys(std::string& standCellPath);
    void WriteBlif(const std::string & fileName) const;
    void WriteDot(const std::string & fileName, std::vector<double>* pData = nullptr, double threshold = 0.5) const;
    void Print(bool showFunct = false) const;
    void PrintObjBas(ABC_NAMESPACE::Abc_Obj_t * pObj, std::string && endWith) const;
    void PrintObj(ABC_NAMESPACE::Abc_Obj_t * pObj, bool showFunct = false) const;
    bool IsPIOSame(NetMan & oth_net) const;
    ll GetNodeMffcSize(ABC_NAMESPACE::Abc_Obj_t * pNode) const;
    std::vector <ABC_NAMESPACE::Abc_Obj_t *> GetNodeMffc(ABC_NAMESPACE::Abc_Obj_t * pNode) const;
    int NodeDeref_rec(ABC_NAMESPACE::Abc_Obj_t* pRoot, ABC_NAMESPACE::Abc_Obj_t* pNode, std::unordered_set<ABC_NAMESPACE::Abc_Obj_t*>& divSet) const;
    int NodeRef_rec(ABC_NAMESPACE::Abc_Obj_t* pRoot, ABC_NAMESPACE::Abc_Obj_t* pNode, std::unordered_set<ABC_NAMESPACE::Abc_Obj_t*>& divSet) const;
    int GetSizeGain(int rootId, const IntVect& divIds) const;
    int GetSizeGain(const IntVect& targetIds, const IntVect& divIds) const;
    ABC_NAMESPACE::Abc_Obj_t* CreateNode(const AbcObjVect& pFanins, const std::string& sop);
    int CreateNode(const IntVect& faninIds, const std::string & sop); 
    int CreateNodeAIG(const IntVect& faninIds, const std::string & sop);
    IntVect TempRepl(ABC_NAMESPACE::Abc_Obj_t * pTS, ABC_NAMESPACE::Abc_Obj_t * pSS);
    void Recov(IntVect& replTrace, bool isVerb = false);
    void PatchFanin(ABC_NAMESPACE::Abc_Obj_t * pObj, ll iFanin, ABC_NAMESPACE::Abc_Obj_t * pFaninOld, ABC_NAMESPACE::Abc_Obj_t * pFaninNew);
    void Trunc(ll truncBit);
    void SetBit(ll iBit, bool useConst1);
    bool CleanUp();
    // void CleanUpPro();
    // bool ProcHalfAndFullAdd();
    // void ProcHalfAndFullAddNew();
    ABC_NAMESPACE::Abc_Obj_t * CreateGate(std::vector <ABC_NAMESPACE::Abc_Obj_t *> && fanins, const std::string & gateName);
    void ReplaceByComplementedObj(ll targId, ll subId);
    void SetConstantInput(ABC_NAMESPACE::Abc_Obj_t * pNode, ABC_NAMESPACE::Abc_Obj_t * pFanin, int fConst0);
    void PropagateConst(ll startId, bool print);
    bool IsNodeXor(ll nodeId, ll& div0, ll& div1, bool print = false);
    void DumpCFile(std::string&& fileName);
    
    inline ABC_NAMESPACE::Abc_Ntk_t * GetNet() const {return pNtk;}
    inline NET_TYPE GetNetType() const {return AbcMan::GetNetType(GetNet());}
    inline ll Check() const {return ABC_NAMESPACE::Abc_NtkDoCheck(GetNet());}
    inline double GetArea() const {return AbcMan::GetArea(GetNet());}
    inline double GetDelay() const {return AbcMan::GetDelay(GetNet());}
    inline void WriteNet(const std::string & fileName, bool isVerb = false) {AbcMan::SetMainNetw(ABC_NAMESPACE::Abc_NtkDup(GetNet())); AbcMan::WriteNet(fileName, isVerb);}
    inline void WriteNet(const std::string && fileName, bool isVerb = false) {AbcMan::SetMainNetw(ABC_NAMESPACE::Abc_NtkDup(GetNet())); AbcMan::WriteNet(fileName, isVerb);}
    inline void PrintStat() {AbcMan::SetMainNetw(ABC_NAMESPACE::Abc_NtkDup(GetNet())); AbcMan::PrintStat();}

    inline void ConvToSop() {ABC_NAMESPACE::Abc_NtkToSop(GetNet(), -1, ABC_INFINITY);}
    inline ABC_NAMESPACE::Abc_Ntk_t* StartSopNet() {pNtk = ABC_NAMESPACE::Abc_NtkAlloc(ABC_NAMESPACE::ABC_NTK_LOGIC, ABC_NAMESPACE::ABC_FUNC_SOP, 1); return pNtk;}

    inline bool IsInTopoOrd() const {assert(GetNetType() == NET_TYPE::AIG || GetNetType() == NET_TYPE::GATE || GetNetType() == NET_TYPE::SOP); return ABC_NAMESPACE::Abc_SclCheckNtk(GetNet(), 0);}

    inline int GetPiNum() const {return ABC_NAMESPACE::Abc_NtkPiNum(GetNet());}
    inline int GetObjNumMax() const {return ABC_NAMESPACE::Abc_NtkObjNumMax(GetNet());}
    inline int GetObjNum() const {return ABC_NAMESPACE::Abc_NtkObjNum(GetNet());}
    inline int GetPoNum() const {return ABC_NAMESPACE::Abc_NtkPoNum(GetNet());}
    inline int GetNodeNum() const {return ABC_NAMESPACE::Abc_NtkNodeNum(GetNet());}

    inline ABC_NAMESPACE::Abc_Obj_t * GetPi(int i) const {return ABC_NAMESPACE::Abc_NtkPi(GetNet(), i);}
    inline ABC_NAMESPACE::Abc_Obj_t * GetObj(int i) const {return ABC_NAMESPACE::Abc_NtkObj(GetNet(), i);}
    inline ABC_NAMESPACE::Abc_Obj_t * GetPo(int i) const {return ABC_NAMESPACE::Abc_NtkPo(GetNet(), i);}

    inline int GetIdMaxPlus1() const {return ABC_NAMESPACE::Abc_NtkObjNumMax(GetNet());}
    inline int GetIdMax() const {return ABC_NAMESPACE::Abc_NtkObjNumMax(GetNet()) - 1;}
    inline int GetId(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjId(pObj);}
    inline int GetPiId(int i) const {return GetId(GetPi(i));}
    inline int GetPoId(int i) const {return GetId(GetPo(i));}

    inline bool IsObj(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return pObj != nullptr;}
    inline bool IsObj(ll id) const {return IsObj(GetObj(id));}
    inline bool IsNode(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return pObj != nullptr && ABC_NAMESPACE::Abc_ObjIsNode(pObj);}
    inline bool IsNode(ll id) const {return IsNode(GetObj(id));}
    inline bool IsObjPi(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjIsPi(pObj);}
    inline bool IsObjPi(ll id) const {return IsObjPi(GetObj(id));}
    inline bool IsObjPo(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjIsPo(pObj);}
    inline bool IsObjPo(ll id) const {return IsObjPo(GetObj(id));}
    inline bool IsNonPoObj(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return IsObj(pObj) && !IsObjPo(pObj);}
    inline bool IsNonPoObj(ll id) const {return IsNonPoObj(GetObj(id));}
    inline bool IsConst(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return IsNode(pObj) && ABC_NAMESPACE::Abc_NodeIsConst(pObj);}
    inline bool IsConst(ll id) const {return IsConst(GetObj(id));}
    inline bool IsConst0(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return IsNode(pObj) && ABC_NAMESPACE::Abc_NodeIsConst0(pObj);}
    inline bool IsConst0(ll id) const {return IsConst0(GetObj(id));}
    inline bool IsConst1(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return IsNode(pObj) && ABC_NAMESPACE::Abc_NodeIsConst1(pObj);}
    inline bool IsConst1(ll id) const {return IsConst1(GetObj(id));}
    inline bool IsInv(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return IsNode(pObj) && ABC_NAMESPACE::Abc_NodeIsInv(pObj);}
    inline bool IsInv(ll id) const {return IsInv(GetObj(id));}
    inline bool IsBuffer(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return IsNode(pObj) && ABC_NAMESPACE::Abc_NodeIsBuf(pObj);}
    inline bool IsBuffer(ll id) const {return IsBuffer(GetObj(id));}

    inline int GetFaninNum(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjFaninNum(pObj);}
    inline int GetFaninNum(int id) const {return GetFaninNum(GetObj(id));}
    inline ABC_NAMESPACE::Abc_Obj_t * GetFanin(ABC_NAMESPACE::Abc_Obj_t * pObj, int i) const {return ABC_NAMESPACE::Abc_ObjFanin(pObj, i);}
    inline ABC_NAMESPACE::Abc_Obj_t * GetFanin(int id, int i) const {return GetFanin(GetObj(id), i);}
    inline int GetFaninId(ABC_NAMESPACE::Abc_Obj_t * pObj, int i) const {return GetId(GetFanin(pObj, i));}
    inline int GetFaninId(int nodeId, int i) const {return GetFaninId(GetObj(nodeId), i);}

    inline ll GetFanoutNum(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_ObjFanoutNum(pObj);}
    inline ll GetFanoutNum(ll id) const {return GetFanoutNum(GetObj(id));}
    inline ABC_NAMESPACE::Abc_Obj_t * GetFanout(ABC_NAMESPACE::Abc_Obj_t * pObj, ll i) const {return ABC_NAMESPACE::Abc_ObjFanout(pObj, i);}
    inline ABC_NAMESPACE::Abc_Obj_t * GetFanout(ll id, ll i) const {return GetFanout(GetObj(id), i);}
    inline ll GetFanoutId(ABC_NAMESPACE::Abc_Obj_t * pObj, ll i) {return GetId(GetFanout(pObj, i));}
    inline ll GetFanoutId(ll id, ll i) {return GetFanoutId(GetObj(id), i);}
    inline std::vector <ABC_NAMESPACE::Abc_Obj_t *> GetFanoutsThatArePos(ABC_NAMESPACE::Abc_Obj_t * pObj) {
        std::vector <ABC_NAMESPACE::Abc_Obj_t *> pos;
        for (ll i = 0; i < GetFanoutNum(pObj); ++i) {
            auto fanout = GetFanout(pObj, i);
            if (IsObjPo(fanout))
                pos.emplace_back(fanout);
        }
        return pos;
    }
    inline std::vector <ABC_NAMESPACE::Abc_Obj_t *> GetFanoutsThatArePos(ll id) {return GetFanoutsThatArePos(GetObj(id));}
    inline bool IsPoDriver(ABC_NAMESPACE::Abc_Obj_t * pObj) const {
        for (ll i = 0; i < GetFanoutNum(pObj); ++i) {
            auto fanout = GetFanout(pObj, i);
            if (IsObjPo(fanout))
                return true;
        }
        return false;
    }
    inline bool IsPoDriver(ll id) const {return IsPoDriver(GetObj(id));}
    inline bool IsTheOnlyPoDriver(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return GetFanoutNum(pObj) == 1 && IsObjPo(GetFanout(pObj, 0));}
    inline bool IsTheOnlyPoDriver(ll id) const {return IsTheOnlyPoDriver(GetObj(id));}
    inline std::string GetName(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return std::string(ABC_NAMESPACE::Abc_ObjName(pObj));}
    inline std::string GetName(ll i) const {return GetName(GetObj(i));}
    inline std::string GetPiName(ll i) const {return std::string(ABC_NAMESPACE::Abc_ObjName(GetPi(i)));}
    inline std::string GetPoName(ll i) const {return std::string(ABC_NAMESPACE::Abc_ObjName(GetPo(i)));}
    inline char * GetSOP(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return (char *)(pObj->pData);}
    inline char * GetSOP(ll id) const {return GetSOP(GetObj(id));}

    inline ll GetLev() const {return ABC_NAMESPACE::Abc_NtkLevel(GetNet());}
    inline ll GetObjLev(ABC_NAMESPACE::Abc_Obj_t * pObj) const {
        if (IsObjPo(pObj)) {
            assert(GetFaninNum(pObj) == 1);
            return ABC_NAMESPACE::Abc_ObjLevel(GetFanin(pObj, 0)) + 1;
        }
        else
            return ABC_NAMESPACE::Abc_ObjLevel(pObj);
    }
    inline ll GetObjLev(ll i) const {return ABC_NAMESPACE::Abc_ObjLevel(GetObj(i));}

    inline double GetArrTime(ABC_NAMESPACE::Abc_Obj_t * pNode) const {
        if (static_cast <ABC_NAMESPACE::SC_Lib *> (GetAbcFame()->pLibScl) == nullptr)
            return static_cast <ABC_NAMESPACE::Abc_Time_t *> (pNode->pNtk->pManTime->vArrs->pArray[pNode->Id])->Rise;
        else
            return pNode->dTemp;
    }
    inline double GetArrTime(ll id) const {return GetArrTime(GetObj(id));}
    inline double GetGateDelay(ABC_NAMESPACE::Abc_Obj_t * pNode) const {return ABC_NAMESPACE::Mio_GateReadDelayMax(static_cast <ABC_NAMESPACE::Mio_Gate_t *> (pNode->pData));}
    inline double GetGateDelay(ll id) const {return GetGateDelay(GetObj(id));}
    inline double GetInvDelay() const {return ABC_NAMESPACE::Mio_LibraryReadDelayInvMax(static_cast <ABC_NAMESPACE::Mio_Library_t *> (GetNet()->pManFunc));}
    inline std::string GetGateName(ABC_NAMESPACE::Abc_Obj_t * pNode) const {
        assert(NetMan::GetNetType() == NET_TYPE::GATE);
        if (IsNode(pNode))
            return std::string(ABC_NAMESPACE::Mio_GateReadName(static_cast <ABC_NAMESPACE::Mio_Gate_t *> (pNode->pData)));
        else
            return std::string("");
    }

    inline ll GetNodeMffcSize(ll i) const {return GetNodeMffcSize(GetObj(i));}

    inline void SetNetNotTrav() const {ABC_NAMESPACE::Abc_NtkIncrementTravId(GetNet());}
    inline bool GetObjTrav(ABC_NAMESPACE::Abc_Obj_t * pObj) const {return ABC_NAMESPACE::Abc_NodeIsTravIdCurrent(pObj);}
    inline void SetObjTrav(ABC_NAMESPACE::Abc_Obj_t * pObj) const {ABC_NAMESPACE::Abc_NodeSetTravIdCurrent(pObj);}

    inline void Replace(ABC_NAMESPACE::Abc_Obj_t * pTS, ABC_NAMESPACE::Abc_Obj_t * pSS) {ABC_NAMESPACE::Abc_ObjReplace(pTS, pSS);}
    inline void Replace(ll tsId, ll ssId) {Replace(GetObj(tsId), GetObj(ssId));}
    inline void TransfFanout(ABC_NAMESPACE::Abc_Obj_t * pTS, ABC_NAMESPACE::Abc_Obj_t * pSS) {ABC_NAMESPACE::Abc_ObjTransferFanout(pTS, pSS);}
    inline void TransfFanout(int tsId, int ssId) {TransfFanout(GetObj(tsId), GetObj(ssId));}
    inline void DelObj(ABC_NAMESPACE::Abc_Obj_t * pObj) {ABC_NAMESPACE::Abc_NtkDeleteObj(pObj);}
    inline void DelObj(ll id) {DelObj(GetObj(id));}
    inline void DelObjRec(ABC_NAMESPACE::Abc_Obj_t * pObj) {ABC_NAMESPACE::Abc_NtkDeleteObj_rec(pObj, 1);}
    inline void DelObjRec(ll id) {DelObjRec(GetObj(id));}
    inline ABC_NAMESPACE::Abc_Obj_t * CreateInv(ABC_NAMESPACE::Abc_Obj_t * pFanin) {assert(pFanin->pNtk == GetNet()); return Abc_NtkCreateNodeInv(GetNet(), pFanin);}
    inline ll CreateInv(ll faninId) {return GetId(CreateInv(GetObj(faninId)));}

    inline void PrintObj(ll id, bool showFunct = false) const {PrintObj(GetObj(id), showFunct);}
    inline void PrintObjBas(ll id, std::string && endWith = "") const {PrintObjBas(GetObj(id), std::move(endWith));}

    inline bool CheckSCLNet() const {return AbcMan::CheckSCLNet(GetNet());}
};
using NetManPtr = std::shared_ptr<NetMan>;


void GlobStartAbc();
void GlobStopAbc();
void EvalNetw(NetMan & net, const std::string & outpPath, double err,  ll round);


static inline std::ostream & operator << (std::ostream & os, ABC_NAMESPACE::Abc_Obj_t * pObj) {
    assert(pObj != nullptr);
    os << ABC_NAMESPACE::Abc_ObjName(pObj) << "(" << ABC_NAMESPACE::Abc_ObjId(pObj) << ")";
    return os;
}


static inline void RenameAbcObj(ABC_NAMESPACE::Abc_Obj_t* pObj, const std::string& name) {
    auto pNameMan = pObj->pNtk->pManName;
    auto pEntry = ABC_NAMESPACE::Nm_ManTableLookupId(pNameMan, pObj->Id);
    if (pEntry != nullptr)
        ABC_NAMESPACE::Nm_ManDeleteIdName(pNameMan, pObj->Id);
    ABC_NAMESPACE::Abc_ObjAssignName(pObj, const_cast<char*>(name.c_str()), nullptr);
}
}