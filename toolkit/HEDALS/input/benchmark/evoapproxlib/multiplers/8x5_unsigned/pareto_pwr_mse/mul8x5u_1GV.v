/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mse parameters
***/
// MAE% = 9.33 %
// MAE = 764 
// WCE% = 35.66 %
// WCE = 2921 
// WCRE% = 300.00 %
// EP% = 96.50 %
// MRE% = 68.64 %
// MSE = 959094 
// PDK45_PWR = 0.0006 mW
// PDK45_AREA = 4.7 um2
// PDK45_DELAY = 0.04 ns

module mul8x5u_1GV (
    A,
    B,
    O
);

input [7:0] A;
input [4:0] B;
output [12:0] O;

wire sig_90,sig_93;

assign sig_90 = A[6] & B[3];
assign sig_93 = A[7] & B[4];

assign O[12] = sig_93;
assign O[11] = sig_90;
assign O[10] = 1'b0;
assign O[9] = 1'b0;
assign O[8] = 1'b0;
assign O[7] = 1'b0;
assign O[6] = 1'b0;
assign O[5] = 1'b0;
assign O[4] = 1'b0;
assign O[3] = 1'b0;
assign O[2] = 1'b0;
assign O[1] = 1'b0;
assign O[0] = 1'b0;

endmodule


