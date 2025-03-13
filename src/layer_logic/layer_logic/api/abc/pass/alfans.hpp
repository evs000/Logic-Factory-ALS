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
 * @brief Approximate logic resubstitution
 * @example
 *  alfans [options]
 */
void alfans(const std::string& accCirc, const std::string& standCell, bool enableFastErrEst, double thresholdER, double thresholdMEM, double T_init=20, double T_final=1, const std::string& outpPath="./tmp", const std::string& distrType="UNIF", int seed=0, int nFrame=102400, int nFrame4ResubGen=64, int maxCandResub=100000, int nThread=4)
{
    // auto ntktype = lfLntINST->get_ntktype_curr();
    // assert(ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG ||
    //        ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_AIG ||
    //        ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_SOP);
    // if (ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG &&
    //     ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_AIG &&
    //     ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_SOP)
    // {
    //     std::cerr << "Error: The current network is not a valid logic network." << std::endl;
    //     return;
    // }

    // auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>();
    int argc = 1; // command name

    if (!accCirc.empty()) argc += 2;
    if (!standCell.empty()) argc += 2;
    if (!outpPath.empty()) argc += 2;
    if (!distrType.empty()) argc += 2;
    if (seed >= 0) argc += 2;
    if (thresholdER >= 0.0) argc += 2;
    if (thresholdMEM >= 0.0) argc += 2;
    if (T_init >= 0.0) argc += 2;
    if (T_final >= 0.0) argc += 2;
    if (nFrame >= 0) argc += 2;
    if (nFrame4ResubGen >= 0) argc += 2;
    if (maxCandResub >= 0) argc += 2;
    if (nThread >= 0) argc += 2;
    if (enableFastErrEst) argc += 2;

    char** argv = ABC_ALLOC(char*, argc + 1);
    int pos = 0;
    argv[pos++] = babc::Extra_UtilStrsav("Alfans");

    if (!accCirc.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("--accCirc");
        argv[pos++] = babc::Extra_UtilStrsav(accCirc.c_str());
    }
    if (!standCell.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("--standCell");
        argv[pos++] = babc::Extra_UtilStrsav(standCell.c_str());
    }
    if (!outpPath.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("--outpPath");
        argv[pos++] = babc::Extra_UtilStrsav(outpPath.c_str());
    }
    if (!distrType.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("--distrType");
        argv[pos++] = babc::Extra_UtilStrsav(distrType.c_str());
    }
    if (seed >= 0) {
        argv[pos++] = babc::Extra_UtilStrsav("--seed");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(seed).c_str());
    }
    if (thresholdER >= 0.0) {
        argv[pos++] = babc::Extra_UtilStrsav("--thresholdER");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(thresholdER).c_str());
    }
    if (thresholdMEM >= 0.0) {
        argv[pos++] = babc::Extra_UtilStrsav("--thresholdMEM");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(thresholdMEM).c_str());
    }
    if (T_init >= 0.0) {
        argv[pos++] = babc::Extra_UtilStrsav("--T_init");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(T_init).c_str());
    }
    if (T_final >= 0.0) {
        argv[pos++] = babc::Extra_UtilStrsav("--T_final");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(T_final).c_str());
    }
    if (nFrame >= 0) {
        argv[pos++] = babc::Extra_UtilStrsav("--nFrame");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(nFrame).c_str());
    }
    if (nFrame4ResubGen >= 0) {
        argv[pos++] = babc::Extra_UtilStrsav("--nFrame4ResubGen");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(nFrame4ResubGen).c_str());
    }
    if (maxCandResub >= 0) {
        argv[pos++] = babc::Extra_UtilStrsav("--maxCandResub");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(maxCandResub).c_str());
    }
    if (nThread >= 0) {
        argv[pos++] = babc::Extra_UtilStrsav("--nThread");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(nThread).c_str());
    }
    if (enableFastErrEst) {
        argv[pos++] = babc::Extra_UtilStrsav("--enableFastErrEst");
        argv[pos++] = babc::Extra_UtilStrsav("1");
    }
    // std::cout<<"alfans!"<<std::endl;
    // for (int i = 0;i<pos;i++){
    //     std::cout<<argv<<std::endl;
    // }
    alfans::main(argc, argv);
}

} // namespace abc

} // namespace logic

} // end namespace lf
