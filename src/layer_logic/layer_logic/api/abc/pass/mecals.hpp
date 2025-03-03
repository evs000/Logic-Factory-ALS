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
 * @brief MECALS: Maximum Error Constrained Approximate Logic Synthesis
 * @example
 *  mecals [options]
 *  options: 
 * @note
 */
void mecals(const std::string& accCirc, const std::string& mitCirc, const std::string& appCirc, const std::string& standCell = "toolkit/MECALS/input/standard-cell/mcnc.genlib", const std::string& outpPath = "tmp", int seed = 0, int nFrame = 8192, int fSASIMI = 1, double exactPBDPerc = 1.0)
{
  // auto ntktype = lfLntINST->get_ntktype_curr();
  // assert( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG || ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_AIG || ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_SOP);
  // if ( ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG && ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_AIG && ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_SOP)
  // {
  //   std::cerr << "Error: The current network is not a strash aig network." << std::endl;
  //   return;
  // }

  // auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>();
  int argc = 1; // command name

  if (!accCirc.empty()) argc+=2;
  if (!mitCirc.empty()) argc+=2;
  if (!appCirc.empty()) argc+=2;
  if (!standCell.empty()) argc+=2;
  if (!outpPath.empty()) argc+=2;
  if (seed >= 0) argc+=2;
  if (nFrame >= 0) argc+=2;
  if (fSASIMI == 0 || fSASIMI == 1) argc+=2;
  if (exactPBDPerc >= 0.0) argc+=2;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav("mecals");
  if (!accCirc.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("-i");
    argv[pos++] = babc::Extra_UtilStrsav((accCirc).c_str());
  }
  if (!mitCirc.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("-m");
    argv[pos++] = babc::Extra_UtilStrsav((mitCirc).c_str());
  }
  if (!appCirc.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("-a");
    argv[pos++] = babc::Extra_UtilStrsav((appCirc).c_str());
  }
  if (!standCell.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("-l");
    argv[pos++] = babc::Extra_UtilStrsav((standCell).c_str());
  }
  if (!outpPath.empty()){
    argv[pos++] = babc::Extra_UtilStrsav("-o");
    argv[pos++] = babc::Extra_UtilStrsav((outpPath).c_str());
  }
  if (seed >= 0){
    argv[pos++] = babc::Extra_UtilStrsav("-s");
    argv[pos++] = babc::Extra_UtilStrsav(std::to_string(seed).c_str());
  }
  if (nFrame >= 0){
    argv[pos++] = babc::Extra_UtilStrsav("-f");
    argv[pos++] = babc::Extra_UtilStrsav(std::to_string(nFrame).c_str());
  }
  if (fSASIMI == 0 || fSASIMI == 1){
    argv[pos++] = babc::Extra_UtilStrsav("--fSASIMI");
    argv[pos++] = babc::Extra_UtilStrsav(std::to_string(fSASIMI).c_str());
  }
  if (exactPBDPerc >= 0.0){
    argv[pos++] = babc::Extra_UtilStrsav("-p");
    argv[pos++] = babc::Extra_UtilStrsav(std::to_string(exactPBDPerc).c_str());
  }

  mecals::mecals_main(argc, argv);
}

} // namespace abc

} // namespace logic

} // end namespace lf
