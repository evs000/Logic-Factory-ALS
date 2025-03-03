/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. MRAZEK. Optimization of BDD-based Approximation Error Metrics Calculations. In: IEEE Computer Society Annual Symposium on VLSI (ISVLSI '22). Paphos: Institute of Electrical and Electronics Engineers, 2022, pp. 86-91. ISBN 978-1-6654-6605-9. 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and ep parameters
***/
// MAE% = 0.39 %
// MAE = 2.0 
// WCE% = 1.56 %
// WCE = 8.0 
// WCRE% = 66.67 %
// EP% = 46.88 %
// MRE% = 1.04 %
// MSE = 10 
// PDK45_PWR = 0.023 mW
// PDK45_AREA = 65.7 um2
// PDK45_DELAY = 0.39 ns


module add8u_0NH(A, B, O);
  input [7:0] A, B;
  output [8:0] O;
  wire sig_17, sig_18, sig_19, sig_22, sig_29, sig_32;
  wire sig_33, sig_34, sig_35, sig_37, sig_38, sig_39;
  wire sig_40, sig_42, sig_43, sig_44, sig_45, sig_47;
  wire sig_48, sig_49, sig_50;
  assign sig_17 = A[0] & B[0];
  assign sig_18 = A[1] ^ B[1];
  assign sig_19 = A[1] & B[1];
  assign O[1] = sig_18 | sig_17;
  assign sig_22 = sig_19 | B[2];
  assign O[3] = A[3] ^ B[3];
  assign O[2] = A[2] | sig_22;
  assign sig_29 = A[3] & B[3];
  assign O[0] = A[0] ^ B[0];
  assign sig_32 = sig_29;
  assign sig_33 = A[4] ^ B[4];
  assign sig_34 = A[4] & B[4];
  assign sig_35 = sig_33 & sig_32;
  assign O[4] = sig_33 ^ sig_32;
  assign sig_37 = sig_34 | sig_35;
  assign sig_38 = A[5] ^ B[5];
  assign sig_39 = A[5] & B[5];
  assign sig_40 = sig_38 & sig_37;
  assign O[5] = sig_38 ^ sig_37;
  assign sig_42 = sig_39 | sig_40;
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
endmodule

