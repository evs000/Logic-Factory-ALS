/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. MRAZEK. Optimization of BDD-based Approximation Error Metrics Calculations. In: IEEE Computer Society Annual Symposium on VLSI (ISVLSI '22). Paphos: Institute of Electrical and Electronics Engineers, 2022, pp. 86-91. ISBN 978-1-6654-6605-9. 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mre parameters
***/
// MAE% = 1.64 %
// MAE = 8.4 
// WCE% = 6.05 %
// WCE = 31 
// WCRE% = 800.00 %
// EP% = 89.45 %
// MRE% = 4.28 %
// MSE = 123 
// PDK45_PWR = 0.011 mW
// PDK45_AREA = 32.9 um2
// PDK45_DELAY = 0.24 ns


module add8u_108(A, B, O);
  input [7:0] A, B;
  output [8:0] O;
  wire sig_39, sig_42, sig_43, sig_44, sig_45, sig_47;
  wire sig_48, sig_49, sig_50;
  assign O[0] = A[0] | B[0];
  assign O[4] = B[4] | A[4];
  assign O[2] = B[2] | A[2];
  assign O[3] = 1'b1;
  assign sig_39 = A[5] & B[5];
  assign O[5] = B[5] ^ A[5];
  assign sig_42 = sig_39;
  assign sig_43 = A[6] ^ B[6];
  assign sig_44 = A[6] & B[6];
  assign sig_45 = sig_43 & sig_42;
  assign O[6] = sig_43 ^ sig_42;
  assign sig_47 = sig_44 | sig_45;
  assign sig_48 = A[7] ^ B[7];
  assign sig_49 = A[7] & B[7];
  assign sig_50 = sig_48 & sig_47;
  assign O[7] = sig_48 ^ sig_47;
  assign O[8] = sig_49 | sig_50;
  assign O[1] = B[1];
endmodule

