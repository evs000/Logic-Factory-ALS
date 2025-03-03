/*
 * basic_types.h
 *
 *  Created on: Jun 24, 2012
 *      Author: Marc Thurley
 */

#ifndef SOLVER_CONFIG_H_
#define SOLVER_CONFIG_H_

#include <set>

enum polarity_type {
    polar_false, polar_true, polar_default, polaritycache
};


struct SolverConfiguration {


  // TODO component caching cannot be deactivated for now!
  bool perform_non_chron_back_track = true;
  bool perform_component_caching = true;
  // Chang's modification: disable IBCP
  bool perform_failed_lit_test = false;
  // Chang's modification: disable pre-processing
  bool perform_pre_processing = true;
  bool perform_pcc = true;
  bool use_csvsads = true;
  bool use_edr = false;
  bool use_lso = true;
  bool verbose = false;
  // Chang's modification: disable projected model counting
  bool perform_projectedmodelcounting = false;
  // quiet = true will override verbose;
  bool quiet = false;
  bool maxdecterminate = false;
  // Chang's modification: enable simulation
  // bool enable_simulation = false;

  unsigned long time_bound_seconds = 100000;
  unsigned long randomseed = 1000;
  
  unsigned hashrange = 1;
  unsigned lsoafterdecisions = 5000;
  unsigned maxdec = 5000000;
  unsigned minconflicts_ = 500;
  // Chang's modification: maximum PI id
  int maxPI = 0;
  int nIsolatedPIs = 0;

  float delta = 0.05;
  float csvsads_param = 0.9;

  polarity_type polarity_config = polaritycache;

};

#endif /* SOLVER_CONFIG_H_ */
