#pragma once


#include "header.h"
#include "my_abc.h"

namespace mecals{
class Simulator: public NetMan {
private:
    unsigned seed;
    int nFrame;
    std::vector < boost::dynamic_bitset <ull> > dat;
    std::vector < boost::dynamic_bitset <ull> > tempDat;

public:
    explicit Simulator(NetMan & net_man, unsigned _seed, int n_frame);
    // explicit Simulator(ABC_NAMESPACE::Abc_Ntk_t * p_ntk, unsigned _seed);
    // explicit Simulator(std::string & fileName, unsigned _seed);
    ~Simulator() = default;
    Simulator(const Simulator &) = delete;
    Simulator(Simulator &&) = delete;
    Simulator & operator = (const Simulator &) = delete;
    Simulator & operator = (Simulator &&) = delete;

    void InpUnif();
    void InpUnifFast();
    void InpEnum();
    void Sim();
    void UpdAigNode(ABC_NAMESPACE::Abc_Obj_t * pObj);
    void UpdSopNode(ABC_NAMESPACE::Abc_Obj_t * pObj);
    void UpdGateNode(ABC_NAMESPACE::Abc_Obj_t * pObj);
    void UpdStrashNode(ABC_NAMESPACE::Abc_Obj_t * pObj);
    void UpdSop(ABC_NAMESPACE::Abc_Obj_t * pObj, char * pSop);
    BigInt GetInput(int iPatt, int lsb, int msb) const;
    void PrintInpStream(int iPatt) const;
    BigInt GetOutput(int iPatt) const;
    int GetOutputFast(int iPatt) const;
    int GetTempOutputFast(int iPatt) const;
    void PrintOutpStream(int iPatt) const;
    double GetSignalProb(int objId) const;
    void PrintSignalProb() const;
    bool IsPIOSame(const Simulator & oth_smlt) const;
    double GetErrRate(const Simulator & oth_smlt, bool isCheck = false) const;
    double GetMeanErrDist(const Simulator & oth_smlt, bool isCheck = false) const;
    void CalcLocBoolDiff(ABC_NAMESPACE::Abc_Obj_t * pObj, std::list <ABC_NAMESPACE::Abc_Obj_t *> & disjCut, std::vector <ABC_NAMESPACE::Abc_Obj_t *> & cutNtk, std::vector < boost::dynamic_bitset <ull> > & bdCut2Node);
    void UpdSopNodeForBoolDiff(ABC_NAMESPACE::Abc_Obj_t * pObj);
    void UpdGateNodeForBoolDiff(ABC_NAMESPACE::Abc_Obj_t * pObj);
    void UpdSopForBoolDiff(ABC_NAMESPACE::Abc_Obj_t * pObj, char * pSop);

    inline int GetFrameNumb() {return nFrame;}
    inline boost::dynamic_bitset <ull> * GetDat(ABC_NAMESPACE::Abc_Obj_t * pObj) {return &dat[GetId(pObj)];}
    inline boost::dynamic_bitset <ull> * GetDat(int id) {return &dat[id];}
    inline boost::dynamic_bitset <ull> * GetTempDat(ABC_NAMESPACE::Abc_Obj_t * pObj) {return &tempDat[GetId(pObj)];}
    inline boost::dynamic_bitset <ull> * GetTempDat(int id) {return &tempDat[id];}
    inline void SetTempDat(int id, boost::dynamic_bitset <ull> & newDat) {tempDat[id] = newDat;}
    inline void SetTempDat(int id, boost::dynamic_bitset <ull> && newDat) {tempDat[id] = newDat;}
};

bool IsPIOSame(Simulator & smlt0, Simulator & smlt1);
bool IsPIOSame(NetMan & net0, NetMan & net1);
}