/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mae parameters
***/
// MAE% = 7.50 %
// MAE = 77 
// WCE% = 25.39 %
// WCE = 260 
// WCRE% = 137.50 %
// EP% = 74.71 %
// MRE% = 60.33 %
// MSE = 10903 
// PDK45_PWR = 0.0006 mW
// PDK45_AREA = 4.7 um2
// PDK45_DELAY = 0.04 ns

module mul8x2u_0H8 (
    A,
    B,
    O
);

input [7:0] A;
input [1:0] B;
output [9:0] O;

wire sig_17,sig_25;

assign sig_17 = A[6] & B[0];
assign sig_25 = A[7] & B[1];

assign O[9] = 1'b0;
assign O[8] = sig_25;
assign O[7] = sig_17;
assign O[6] = sig_25;
assign O[5] = sig_25;
assign O[4] = sig_17;
assign O[3] = sig_17;
assign O[2] = 1'b0;
assign O[1] = 1'b0;
assign O[0] = sig_25;

endmodule


