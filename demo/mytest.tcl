start
# anchor -tool yosys
# read_aiger -file demo/b1_comb.aig
# write_aiger -file test_b1_comb.arch.aig

# arch2logic
anchor -tool abc
ntktype -tool abc -stat logic -type aig
# update -n

# strash
# balance
# rewrite
# hedals -i ./toolkit/HEDALS/input/benchmark/bacs/mult8.blif -l ./toolkit/HEDALS/input/standard-cell/nangate_45nm_typ.lib --lacType RAC -f 100032 --metrType MED -e 12 -m 0 -o ./tmp
# resubals --accCirc ./toolkit/ResubALS/input/benchmark/iscas/c880.blif --standCell ./toolkit/ResubALS/input/standard-cell/nangate_45nm_typ.lib --outpPath ./tmp/ --metrType ER --errUppBound 0.05 --nThread 4 --lacType RAC
# mecals -i ./toolkit/MECALS/input/benchmark/aig/mac.aig -m ./toolkit/MECALS/input/miter/width_8_wce_31.aig -l ./toolkit/MECALS//input/standard-cell/nangate_45nm_typ.lib -o ./tmp/ -p 1.0 --fSASIMI 1
circuit2cnf -t ER -e ./toolkit/VACSEM/Circuit2Cnf/input/mult15/mult15.blif -a ./toolkit/VACSEM/Circuit2Cnf/input/mult15/22_mult15_err_0.0944366_size_1696_depth_40.blif -o ./tmp/22_mult15_err_0.0944366.cnf
sim_sharp_sat -t 14400 -i ./tmp/22_mult15_err_0.0944366.cnf