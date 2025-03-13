#include "cmdline.hpp"
#include "header.h"
#include "my_abc.h"
#include "als.h"

namespace alfans {
using namespace ABC_NAMESPACE;
using namespace boost;
using namespace cmdline;
using namespace std;


parser CommPars(int argc, char * argv[]) {
    parser option;
    option.add<string>("accCirc", '\0', "path to accurate circuit", true);
    option.add<string>("standCell", '\0', "path to standard cell library", false, "./input/standard-cell/nangate_45nm_typ.lib");
    option.add<string>("outpPath", '\0', "path to approximate circuits", false, "tmp");
    option.add<double>("thresholdER", '\0', "threshold of ER", false, 0.15);
    option.add<double>("thresholdMEM", '\0', "threshold of MEM", false, 10);
    option.add<double>("T_init", '\0', "the initial value of control parameter similar to the temperature in simulated annealing (recommend <= 30)", false, 20);
    option.add<double>("T_final", '\0', "the final stopping threshold of control parameter similar to the temperature in simulated annealing (recommend Ti/Tf in [10, 20])", false, 1);
    option.add<string>("distrType", '\0', "error distribution type: UNIF, ENUM", false, "UNIF");
    option.add<unsigned>("seed", '\0', "seed for randomness", false, 0);
    // option.add<double>("errUppBound", '\0', "error upper bound", false, 0.15);
    option.add<int>("nFrame", '\0', "#Monte Carlo samples, nFrame should be an integer multiple of 64", false, 102400);
    option.add<int>("nFrame4ResubGen", '\0', "#patterns for AppResub Generation", false, 64);
    option.add<int>("maxCandResub", '\0', "max #candidate AppResubs", false, 100000);
    option.add<int>("nThread", '\0', "number of threads", false, 4);
    // option.add <int> ("maxLevelDiff", '\0', "maximum level difference, affecting the number of 2-resubs", false, 8);
    option.add("enableFastErrEst", '\0', "when this option is enabled, the program performs faster approximate error estimation;\n\t\t\t\totherwise, the program performs slower accurate error estimation");
    // option.add("enableMeasureMode", '\0', "when this option is enabled, the program measures the quality of the circuit specified by `appCirc' option;\n\t\t\t\totherwise, the program performs approximate logic synthesis");
    // option.add <string> ("appCirc", '\0', "path to approximate circuit,\n\t\t\t\tthis option is only used in the case when the `enableMeasureMode' option is active ", false, "");
    option.parse_check(argc, argv);
    return option;
}


void ConfigureOptions(ALSOpt & alsOpt, string & accCirc, string & distrType) {
    // load standard cell
    AbcMan abcMan;
    if (alsOpt.standCellPath != "")
        abcMan.ReadStandCell(alsOpt.standCellPath);
    abcMan.ReadNet(accCirc, false);
    alsOpt.pNtk = abcMan.GetNet();
    
    // fix output path
    FixPath(alsOpt.outpPath);
    CreatePath(alsOpt.outpPath);

    // configure random seed
    if (alsOpt.sourceSeed == 0) {
        random::mt19937 rng(time(0));
        boost::uniform_int <> unif(INT_MIN, INT_MAX);
        alsOpt.sourceSeed = static_cast <unsigned> (unif(rng));
    }

    // configure LAC type
    alsOpt.lacType = LAC_TYPE::RESUB;

    // configure input distribution type
    if (distrType == "UNIF")
        alsOpt.distrType = DISTR_TYPE::UNIF;
    else if (distrType == "ENUM") {
        alsOpt.distrType = DISTR_TYPE::ENUM;
        assert(Abc_NtkPiNum(abcMan.GetNet()) < 20);
        alsOpt.nFrame = 1ll << Abc_NtkPiNum(abcMan.GetNet());
        cout << "nFrame for enumeration = " << alsOpt.nFrame << endl;
    }
    else
        assert(0);
}

void ALS(ALSOpt & alsOpt) {
    alsOpt.Print();
    ALSMan alsMan(alsOpt);
    alsMan.Run();
}


int main(int argc, char * argv[]) {
    // start abc engine
    GlobStartAbc();

    // parse options
    parser option = CommPars(argc, argv);
    ALSOpt alsOpt;
    string accCirc = option.get <string> ("accCirc");
    alsOpt.standCellPath = option.get <string> ("standCell");
    alsOpt.outpPath = option.get <string> ("outpPath");
    alsOpt.thresholdER = option.get <double> ("thresholdER");
    alsOpt.thresholdMEM = option.get <double> ("thresholdMEM");
    alsOpt.Ti = option.get <double> ("T_init");
    alsOpt.Tf = option.get <double> ("T_final");
    string distrType = option.get <string> ("distrType");
    alsOpt.sourceSeed = option.get <unsigned> ("seed");
    alsOpt.nFrame = option.get <int> ("nFrame");    
    alsOpt.nFrame4ResubGen = option.get <int> ("nFrame4ResubGen");
    alsOpt.maxCandResub = option.get <int> ("maxCandResub");
    alsOpt.nThread = option.get <int> ("nThread");
    alsOpt.enableFastErrEst = option.exist("enableFastErrEst");
    // bool enableMeasureMode = option.exist("enableMeasureMode");
    // string appCirc = option.get <string> ("appCirc");
    
    // configure options
    ConfigureOptions(alsOpt, accCirc, distrType);

    ALS(alsOpt);

    // stop abc engine
    GlobStopAbc();
    return 0;
}
}