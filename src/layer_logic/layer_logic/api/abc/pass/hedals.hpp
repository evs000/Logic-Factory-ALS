#pragma once

#include "layer_logic/logic_manager.hpp"
#include "layer_logic/api/abc/frame.hpp"
#include "utility/string.hpp"
#include "utility/util.hpp"

#include <cstdio>
#include <string>

namespace lf
{

namespace logic
{

namespace abc
{

/**
 * @brief delay-driven approximate logic synthesis
 * @example
 *  hedals [options]
 *  options: 
 * @note
 */
void hedals(const std::string& accPath, const std::string& appPath, const std::string& stdCellPath, const std::string& outpPath, const std::string& lacType = "CONST", const std::string& metrType = "ER", const std::string& distrType = "UNIF", const std::string& mapType = "SCL", int sourceSeed = 0, int nFrame = 100032, int mode = 0, int usePostProc = 0, int cutSizeLim = 16, double errUppBound = 0.15)
{
  // auto ntktype = lfLntINST->get_ntktype_curr();
  // assert( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG || ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_AIG || ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_SOP);
  // if ( ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG && ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_AIG && ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_SOP)
  // {
  //   std::cerr << "Error: The current network is not a strash aig network." << std::endl;
  //   return;
  // }

  // auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr
  int argc = 1; // command name

  if (!accPath.empty())
    argc+=2;
  if (!appPath.empty())
    argc+=2;
  if (!stdCellPath.empty())
    argc+=2;
  if (!outpPath.empty())
    argc+=2;
  if (!lacType.empty())
    argc+=2;
  if (!metrType.empty())
    argc+=2;
  if (!distrType.empty())
    argc+=2;
  if (!mapType.empty())
    argc+=2;
  if (sourceSeed >= 0)
    argc+=2;
  if (nFrame >= 0)
    argc+=2;
  if (mode == 0 || mode == 1)
    argc+=2;
  if (usePostProc == 0 || usePostProc == 1)
    argc+=2;
  if (cutSizeLim >= 0)
    argc+=2;
  if (errUppBound >= 0.0f)
    argc+=2;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "hedals" );
  if (!accPath.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("-i");
    argv[pos++] = babc::Extra_UtilStrsav((accPath).c_str());
  }
  if (!appPath.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("--appPath");
    argv[pos++] = babc::Extra_UtilStrsav((appPath).c_str());
  }
  if (!stdCellPath.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("-l");
    argv[pos++] = babc::Extra_UtilStrsav((stdCellPath).c_str());
  }
  if (!outpPath.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("-o");
    argv[pos++] = babc::Extra_UtilStrsav((outpPath).c_str());
  }
  if (!lacType.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("--lacType");
    argv[pos++] = babc::Extra_UtilStrsav((lacType).c_str());
  }
  if (!metrType.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("--metrType");
    argv[pos++] = babc::Extra_UtilStrsav((metrType).c_str());
  }
  if (!distrType.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("--distrType");
    argv[pos++] = babc::Extra_UtilStrsav((distrType).c_str());
  }
  if (!mapType.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("--mapType");
    argv[pos++] = babc::Extra_UtilStrsav((mapType).c_str());
  }
  if (sourceSeed >= 0){
    argv[pos++] = babc::Extra_UtilStrsav("-s");
    argv[pos++] = babc::Extra_UtilStrsav(std::string(std::to_string(sourceSeed)).c_str());
  }
  if (nFrame >= 0){
    argv[pos++] = babc::Extra_UtilStrsav("-f");
    argv[pos++] = babc::Extra_UtilStrsav(std::string(std::to_string(nFrame)).c_str());
  }
  if (mode == 0 || mode == 1){
    argv[pos++] = babc::Extra_UtilStrsav("-m");
    argv[pos++] = babc::Extra_UtilStrsav(std::string(std::to_string(mode)).c_str());
  }
  if (usePostProc == 0 || usePostProc == 1){
    argv[pos++] = babc::Extra_UtilStrsav("--usePostProc");
    argv[pos++] = babc::Extra_UtilStrsav(std::string(std::to_string(usePostProc)).c_str());
  }
  if (cutSizeLim >= 0){
    argv[pos++] = babc::Extra_UtilStrsav("--cutSizeLim");
    argv[pos++] = babc::Extra_UtilStrsav(std::string(std::to_string(cutSizeLim)).c_str());
  }
  if (errUppBound >= 0.0f){
    argv[pos++] = babc::Extra_UtilStrsav("-e");
    argv[pos++] = babc::Extra_UtilStrsav(std::string(std::to_string(errUppBound)).c_str());
  }
    
  hedals::hedals_main(argc, argv);
  // hedals_main( argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf