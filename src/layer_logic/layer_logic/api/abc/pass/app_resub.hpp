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
 *  app_resub [options]
 */
void app_resub(const std::string& accCirc, const std::string& standCell, bool enableFastErrEst, bool enableMeasureMode, const std::string& appCirc, const std::string& lacType="APPRESUB", const std::string& outpPath="./tmp", const std::string& metrType="NMED", const std::string& distrType="UNIF", int seed=0, double errUppBound=0.15, int nFrame=102400, int nFrame4ResubGen=64, int maxCandResub=100000, int nThread=4)
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
    if (!metrType.empty()) argc += 2;
    if (!distrType.empty()) argc += 2;
    if (!lacType.empty()) argc += 2;
    if (seed >= 0) argc += 2;
    if (errUppBound >= 0.0) argc += 2;
    if (nFrame >= 0) argc += 2;
    if (nFrame4ResubGen >= 0) argc += 2;
    if (maxCandResub >= 0) argc += 2;
    if (nThread >= 0) argc += 2;
    if (enableFastErrEst) argc += 2;
    if (enableMeasureMode) argc += 2;
    if (!appCirc.empty()) argc += 2;

    char** argv = ABC_ALLOC(char*, argc + 1);
    int pos = 0;
    argv[pos++] = babc::Extra_UtilStrsav("AppResub");

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
    if (!metrType.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("--metrType");
        argv[pos++] = babc::Extra_UtilStrsav(metrType.c_str());
    }
    if (!lacType.empty()){
        argv[pos++] = babc::Extra_UtilStrsav("--lacType");
        argv[pos++] = babc::Extra_UtilStrsav(lacType.c_str());
    }
    if (!distrType.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("--distrType");
        argv[pos++] = babc::Extra_UtilStrsav(distrType.c_str());
    }
    if (seed >= 0) {
        argv[pos++] = babc::Extra_UtilStrsav("--seed");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(seed).c_str());
    }
    if (errUppBound >= 0.0) {
        argv[pos++] = babc::Extra_UtilStrsav("--errUppBound");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(errUppBound).c_str());
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
    if (enableMeasureMode) {
        argv[pos++] = babc::Extra_UtilStrsav("--enableMeasureMode");
        argv[pos++] = babc::Extra_UtilStrsav("1");
    }
    if (!appCirc.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("--appCirc");
        argv[pos++] = babc::Extra_UtilStrsav(appCirc.c_str());
    }
    printf("app resub");
    resubals::app_resub_main(argc, argv);
}

} // namespace abc

} // namespace logic

} // end namespace lf
