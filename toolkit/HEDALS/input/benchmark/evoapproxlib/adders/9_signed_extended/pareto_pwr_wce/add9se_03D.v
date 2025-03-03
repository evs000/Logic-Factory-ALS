/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and wce parameters
***/
// MAE% = 6.13 %
// MAE = 31 
// WCE% = 12.50 %
// WCE = 64 
// WCRE% = 3400.00 %
// EP% = 99.92 %
// MRE% = 71.05 %
// MSE = 1160 
// PDK45_PWR = 0.011 mW
// PDK45_AREA = 30.0 um2
// PDK45_DELAY = 0.24 ns

module add9se_03D (
    A,
    B,
    O
);

input [8:0] A;
input [8:0] B;
output [9:0] O;

wire sig_45,sig_46,sig_50,sig_51,sig_52,sig_53,sig_54,sig_55,sig_56,sig_57,sig_58,sig_59,sig_60,sig_61;

assign sig_45 = A[6] ^ B[6];
assign sig_46 = A[6] & B[6];
assign sig_50 = A[7] ^ B[7];
assign sig_51 = A[7] & B[7];
assign sig_52 = sig_50 & sig_46;
assign sig_53 = sig_50 ^ sig_46;
assign sig_54 = sig_51 | sig_52;
assign sig_55 = A[8] ^ B[8];
assign sig_56 = A[8] & B[8];
assign sig_57 = sig_55 & sig_54;
assign sig_58 = sig_55 ^ sig_54;
assign sig_59 = sig_56 | sig_57;
assign sig_60 = A[8] ^ B[8];
assign sig_61 = sig_60 ^ sig_59;

assign O[9] = sig_61;
assign O[8] = sig_58;
assign O[7] = sig_53;
assign O[6] = sig_45;
assign O[5] = A[5];
assign O[4] = B[5];
assign O[3] = B[5];
assign O[2] = B[5];
assign O[1] = B[5];
assign O[0] = sig_61;

endmodule


