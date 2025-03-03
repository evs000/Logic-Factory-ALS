/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mse parameters
***/
// MAE% = 6.41 %
// MAE = 8.2 
// WCE% = 14.06 %
// WCE = 18 
// WCRE% = 1500.00 %
// EP% = 97.20 %
// MRE% = 39.40 %
// MSE = 89 
// PDK45_PWR = 0.017 mW
// PDK45_AREA = 38.0 um2
// PDK45_DELAY = 0.35 ns

module add8s_7QB (
    A,
    B,
    O
);

input [7:0] A;
input [7:0] B;
output [7:0] O;

wire sig_22,sig_24,sig_25,sig_26,sig_27,sig_28,sig_29,sig_30,sig_34,sig_36,sig_37,sig_38,sig_39,sig_42,sig_44,sig_53,sig_54,sig_58,sig_59,sig_60;
wire sig_61;

assign sig_22 = A[7] & B[7];
assign sig_24 = A[4] & B[4];
assign sig_25 = A[4] ^ B[4];
assign sig_26 = A[5] & B[5];
assign sig_27 = A[5] ^ B[5];
assign sig_28 = A[6] & B[6];
assign sig_29 = A[6] ^ B[6];
assign sig_30 = A[7] ^ B[7];
assign sig_34 = sig_25 & sig_22;
assign sig_36 = sig_24 | sig_34;
assign sig_37 = sig_29 & sig_26;
assign sig_38 = sig_29 & sig_27;
assign sig_39 = sig_28 | sig_37;
assign sig_42 = sig_38 & sig_36;
assign sig_44 = sig_39 | sig_42;
assign sig_53 = sig_27 & sig_36;
assign sig_54 = sig_26 | sig_53;
assign sig_58 = sig_25 ^ sig_22;
assign sig_59 = sig_27 ^ sig_36;
assign sig_60 = sig_29 ^ sig_54;
assign sig_61 = sig_30 ^ sig_44;

assign O[7] = sig_61;
assign O[6] = sig_60;
assign O[5] = sig_59;
assign O[4] = sig_58;
assign O[3] = A[3];
assign O[2] = B[2];
assign O[1] = sig_61;
assign O[0] = 1'b0;

endmodule


