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
 * @brief Convert circuit to CNF
 * @example
 *  circuit2cnf [options]
 */
void vacsem(bool noCC, bool noPP, bool quiet, bool verbose, bool noPCC, bool noCSVSADS, bool noPMC, bool useEDR, int timeBound, int LSO, int randomSeed, int hashrange, double delta, const std::string& polarity, int cacheSize, int maxdec, int minconflicts, const std::string& type = "ER", const std::string& exactCirc = "./toolkit/VACSEM/Circuit2Cnf/input/mult15/mult15.blif", const std::string& approxCirc = "./toolkit/VACSEM/Circuit2Cnf/input/mult15/1_mult15_err_1.52588e-05_size_1780_depth_39.blif", const std::string& deviationCirc = "./toolkit/VACSEM/Circuit2Cnf/input/deviation-function/width_30_absolute_error.blif", const std::string& outputCnf = "./tmp/test.cnf")
{
    int argc1 = 1; // circuit2cnf command name
    int argc2 = 1; // sim_sharp_sat command name

    // circuit2cnf parameter
    if (!type.empty()) argc1 += 2;
    if (!exactCirc.empty()) argc1 += 2;
    if (!approxCirc.empty()) argc1 += 2;
    if (!deviationCirc.empty()) argc1 += 2;
    if (!outputCnf.empty()) argc1 += 2;

    // sim_sharp_sat parameter
    if (noCC)        argc2 += 1;
    if (noPP)        argc2 += 1;
    if (quiet)       argc2 += 1;
    if (verbose)     argc2 += 1;
    if (noPCC)       argc2 += 1;
    if (noCSVSADS)   argc2 += 1;
    if (noPMC)       argc2 += 1;
    if (useEDR)      argc2 += 1;
    
    if (timeBound > 0)       argc2 += 2;
    if (LSO > 0)             argc2 += 2;
    if (randomSeed >= 0)     argc2 += 2;
    if (hashrange > 0)       argc2 += 2;
    if (delta >= 0.0)        argc2 += 2;
    if (!polarity.empty())   argc2 += 2;
    if (cacheSize > 0)       argc2 += 2;
    if (maxdec > 0)          argc2 += 3;
    if (!outputCnf.empty())  argc2 += 1;

    char** argv1 = ABC_ALLOC(char*, argc1 + 1);
    char** argv2 = ABC_ALLOC(char*, argc2 + 1);
    
    // circuit2cnf argv
    int pos = 0;
    argv1[pos++] = babc::Extra_UtilStrsav("Circuit2Cnf");

    if (!type.empty()) {
        argv1[pos++] = babc::Extra_UtilStrsav("-t");
        argv1[pos++] = babc::Extra_UtilStrsav(type.c_str());
    }
    if (!exactCirc.empty()) {
        argv1[pos++] = babc::Extra_UtilStrsav("-e");
        argv1[pos++] = babc::Extra_UtilStrsav(exactCirc.c_str());
    }
    if (!approxCirc.empty()) {
        argv1[pos++] = babc::Extra_UtilStrsav("-a");
        argv1[pos++] = babc::Extra_UtilStrsav(approxCirc.c_str());
    }
    if (!deviationCirc.empty()) {
        argv1[pos++] = babc::Extra_UtilStrsav("-d");
        argv1[pos++] = babc::Extra_UtilStrsav(deviationCirc.c_str());
    }
    if (!outputCnf.empty()) {
        argv1[pos++] = babc::Extra_UtilStrsav("-o");
        argv1[pos++] = babc::Extra_UtilStrsav(outputCnf.c_str());
    }

    // sim_sharp_sat argv
    pos = 0;
    argv2[pos++] = babc::Extra_UtilStrsav("sim_sharp_sat");
    
    if (noCC)        { argv2[pos++] = babc::Extra_UtilStrsav("-noCC"); }
    if (noPP)        { argv2[pos++] = babc::Extra_UtilStrsav("-noPP"); }
    if (quiet)       { argv2[pos++] = babc::Extra_UtilStrsav("-q"); }
    if (verbose)     { argv2[pos++] = babc::Extra_UtilStrsav("-v"); }
    if (noPCC)       { argv2[pos++] = babc::Extra_UtilStrsav("-noPCC"); }
    if (noCSVSADS)   { argv2[pos++] = babc::Extra_UtilStrsav("-noCSVSADS"); }
    if (noPMC)       { argv2[pos++] = babc::Extra_UtilStrsav("-noPMC"); }
    if (useEDR)      { argv2[pos++] = babc::Extra_UtilStrsav("-EDR"); }
    
    if (timeBound > 0) { 
        argv2[pos++] = babc::Extra_UtilStrsav("-t");
        argv2[pos++] = babc::Extra_UtilStrsav(std::to_string(timeBound).c_str());
    }
    if (LSO > 0) {
        argv2[pos++] = babc::Extra_UtilStrsav("-LSO");
        argv2[pos++] = babc::Extra_UtilStrsav(std::to_string(LSO).c_str());
    }
    if (randomSeed >= 0) {
        argv2[pos++] = babc::Extra_UtilStrsav("-seed");
        argv2[pos++] = babc::Extra_UtilStrsav(std::to_string(randomSeed).c_str());
    }
    if (hashrange > 0) {
        argv2[pos++] = babc::Extra_UtilStrsav("-m");
        argv2[pos++] = babc::Extra_UtilStrsav(std::to_string(hashrange).c_str());
    }
    if (delta >= 0.0) {
        argv2[pos++] = babc::Extra_UtilStrsav("-delta");
        argv2[pos++] = babc::Extra_UtilStrsav(std::to_string(delta).c_str());
    }
    if (!polarity.empty()) {
        argv2[pos++] = babc::Extra_UtilStrsav("-pol");
        argv2[pos++] = babc::Extra_UtilStrsav(polarity.c_str());
    }
    if (cacheSize > 0) {
        argv2[pos++] = babc::Extra_UtilStrsav("-cs");
        argv2[pos++] = babc::Extra_UtilStrsav(std::to_string(cacheSize).c_str());
    }
    if (maxdec > 0) {
        argv2[pos++] = babc::Extra_UtilStrsav("-maxdec");
        argv2[pos++] = babc::Extra_UtilStrsav(std::to_string(maxdec).c_str());
        argv2[pos++] = babc::Extra_UtilStrsav(std::to_string(minconflicts).c_str());
    }
    if (!outputCnf.empty()) {
        argv2[pos++] = babc::Extra_UtilStrsav(outputCnf.c_str());
    }
    
    vacsem::c2c_main(argc1, argv1);
    std::cout << "------------------- finish converting to CNF form -------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "------------------- start sharp sat solving -------------------" << std::endl;
    sim_sharp_sat_main(argc2, argv2);
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

} // namespace abc

} // namespace logic

} // namespace lf
