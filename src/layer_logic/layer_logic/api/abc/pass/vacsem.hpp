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
void circuit2cnf(const std::string& type = "ER", const std::string& exactCirc = "./toolkit/VACSEM/Circuit2Cnf/input/mult15/mult15.blif", const std::string& approxCirc = "./toolkit/VACSEM/Circuit2Cnf/input/mult15/1_mult15_err_1.52588e-05_size_1780_depth_39.blif", const std::string& deviationCirc = "./toolkit/VACSEM/Circuit2Cnf/input/deviation-function/width_30_absolute_error.blif", const std::string& outputCnf = "./tmp/test.cnf")
{
    int argc = 1; // command name

    if (!type.empty()) argc += 2;
    if (!exactCirc.empty()) argc += 2;
    if (!approxCirc.empty()) argc += 2;
    if (!deviationCirc.empty()) argc += 2;
    if (!outputCnf.empty()) argc += 2;

    char** argv = ABC_ALLOC(char*, argc + 1);
    int pos = 0;
    argv[pos++] = babc::Extra_UtilStrsav("Circuit2Cnf");

    if (!type.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("-t");
        argv[pos++] = babc::Extra_UtilStrsav(type.c_str());
    }
    if (!exactCirc.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("-e");
        argv[pos++] = babc::Extra_UtilStrsav(exactCirc.c_str());
    }
    if (!approxCirc.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("-a");
        argv[pos++] = babc::Extra_UtilStrsav(approxCirc.c_str());
    }
    if (!deviationCirc.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("-d");
        argv[pos++] = babc::Extra_UtilStrsav(deviationCirc.c_str());
    }
    if (!outputCnf.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("-o");
        argv[pos++] = babc::Extra_UtilStrsav(outputCnf.c_str());
    }
    
    vacsem::c2c_main(argc, argv);
}

/**
 * @brief Run SimSharpSat with specified options.
 *
 */
void simSharpSat(
    bool noCC,
    bool noPP,
    bool quiet,
    bool verbose,
    bool noPCC,
    bool noCSVSADS,
    bool noPMC,
    bool useEDR,
    int timeBound,
    int LSO,
    int randomSeed,
    int hashrange,
    double delta,
    const std::string& polarity,
    int cacheSize,
    int maxdec,
    int minconflicts,
    const std::string& inputFile = "./tmp/test.cnf"
) {
    int argc = 1; // command name
    
    if (noCC)        argc += 1;
    if (noPP)        argc += 1;
    if (quiet)       argc += 1;
    if (verbose)     argc += 1;
    if (noPCC)       argc += 1;
    if (noCSVSADS)   argc += 1;
    if (noPMC)       argc += 1;
    if (useEDR)      argc += 1;
    
    if (timeBound > 0)       argc += 2;
    if (LSO > 0)             argc += 2;
    if (randomSeed >= 0)     argc += 2;
    if (hashrange > 0)       argc += 2;
    if (delta >= 0.0)        argc += 2;
    if (!polarity.empty())   argc += 2;
    if (cacheSize > 0)       argc += 2;
    if (maxdec > 0)          argc += 3;
    if (!inputFile.empty())  argc += 1;
    
    // Allocate argv array
    char** argv = ABC_ALLOC(char*, argc + 1);
    int pos = 0;
    
    argv[pos++] = babc::Extra_UtilStrsav("sim_sharp_sat");
    
    if (noCC)        { argv[pos++] = babc::Extra_UtilStrsav("-noCC"); }
    if (noPP)        { argv[pos++] = babc::Extra_UtilStrsav("-noPP"); }
    if (quiet)       { argv[pos++] = babc::Extra_UtilStrsav("-q"); }
    if (verbose)     { argv[pos++] = babc::Extra_UtilStrsav("-v"); }
    if (noPCC)       { argv[pos++] = babc::Extra_UtilStrsav("-noPCC"); }
    if (noCSVSADS)   { argv[pos++] = babc::Extra_UtilStrsav("-noCSVSADS"); }
    if (noPMC)       { argv[pos++] = babc::Extra_UtilStrsav("-noPMC"); }
    if (useEDR)      { argv[pos++] = babc::Extra_UtilStrsav("-EDR"); }
    
    if (timeBound > 0) { 
        argv[pos++] = babc::Extra_UtilStrsav("-t");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(timeBound).c_str());
    }
    if (LSO > 0) {
        argv[pos++] = babc::Extra_UtilStrsav("-LSO");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(LSO).c_str());
    }
    if (randomSeed >= 0) {
        argv[pos++] = babc::Extra_UtilStrsav("-seed");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(randomSeed).c_str());
    }
    if (hashrange > 0) {
        argv[pos++] = babc::Extra_UtilStrsav("-m");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(hashrange).c_str());
    }
    if (delta >= 0.0) {
        argv[pos++] = babc::Extra_UtilStrsav("-delta");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(delta).c_str());
    }
    if (!polarity.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav("-pol");
        argv[pos++] = babc::Extra_UtilStrsav(polarity.c_str());
    }
    if (cacheSize > 0) {
        argv[pos++] = babc::Extra_UtilStrsav("-cs");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(cacheSize).c_str());
    }
    if (maxdec > 0) {
        argv[pos++] = babc::Extra_UtilStrsav("-maxdec");
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(maxdec).c_str());
        argv[pos++] = babc::Extra_UtilStrsav(std::to_string(minconflicts).c_str());
    }
    if (!inputFile.empty()) {
        argv[pos++] = babc::Extra_UtilStrsav(inputFile.c_str());
    }
    sim_sharp_sat_main(argc, argv);
}

} // namespace abc

} // namespace logic

} // namespace lf
