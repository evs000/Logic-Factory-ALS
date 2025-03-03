#pragma once

#include "my_abc.h"

namespace vacsem{

void My_NtkDarToCnf(ABC_NAMESPACE::Abc_Ntk_t * pNtk, char * pFileName, int fFastAlgo, int fChangePol, int fVerbose);
NetMan BuildMit(NetMan& accNet, NetMan& appNet, NetMan& mitNet);
void MiterToCnf(NetMan& mit, std::string outp, int iOutp = -1);
}