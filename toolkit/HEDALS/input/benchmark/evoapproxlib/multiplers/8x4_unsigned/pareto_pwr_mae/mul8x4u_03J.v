/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mae parameters
***/
// MAE% = 1.10 %
// MAE = 45 
// WCE% = 4.00 %
// WCE = 164 
// WCRE% = 150.00 %
// EP% = 92.21 %
// MRE% = 15.94 %
// MSE = 3227 
// PDK45_PWR = 0.047 mW
// PDK45_AREA = 122.0 um2
// PDK45_DELAY = 0.60 ns

module mul8x4u_03J (
    A,
    B,
    O
);

input [7:0] A;
input [3:0] B;
output [11:0] O;

wire sig_19,sig_25,sig_26,sig_40,sig_54,sig_55,sig_56,sig_61,sig_66,sig_67,sig_68,sig_69,sig_75,sig_92,sig_93,sig_94,sig_95,sig_96,sig_97,sig_98;
wire sig_99,sig_100,sig_101,sig_102,sig_104,sig_105,sig_106,sig_110,sig_111,sig_112,sig_113,sig_114,sig_132,sig_133,sig_134,sig_135,sig_136,sig_137,sig_138,sig_139;
wire sig_140,sig_141,sig_142,sig_143,sig_144,sig_145,sig_146,sig_147,sig_148,sig_149,sig_150,sig_151;

assign sig_19 = A[7] & B[0];
assign sig_25 = A[5] & B[0];
assign sig_26 = A[6] & B[1];
assign sig_40 = B[1] & A[7];
assign sig_54 = sig_26 | sig_19;
assign sig_55 = sig_19 & A[6];
assign sig_56 = sig_55 & B[1];
assign sig_61 = sig_56 ^ sig_40;
assign sig_66 = A[4] & B[2];
assign sig_67 = A[5] & B[2];
assign sig_68 = A[6] & B[2];
assign sig_69 = A[7] & B[2];
assign sig_75 = B[2] & sig_56;
assign sig_92 = sig_54 ^ sig_67;
assign sig_93 = sig_54 & sig_67;
assign sig_94 = sig_92 & sig_66;
assign sig_95 = sig_92 ^ sig_66;
assign sig_96 = sig_93 | sig_94;
assign sig_97 = sig_61 ^ sig_68;
assign sig_98 = sig_61 & sig_68;
assign sig_99 = sig_97 & sig_96;
assign sig_100 = sig_97 ^ sig_96;
assign sig_101 = sig_98 | sig_99;
assign sig_102 = sig_56 ^ sig_69;
assign sig_104 = A[7] & sig_101;
assign sig_105 = sig_102 ^ sig_101;
assign sig_106 = sig_75 | sig_104;
assign sig_110 = A[3] & B[3];
assign sig_111 = A[4] & B[3];
assign sig_112 = A[5] & B[3];
assign sig_113 = A[6] & B[3];
assign sig_114 = A[7] & B[3];
assign sig_132 = sig_95 ^ sig_111;
assign sig_133 = sig_95 & sig_111;
assign sig_134 = sig_132 & sig_110;
assign sig_135 = sig_132 ^ sig_110;
assign sig_136 = sig_133 | sig_134;
assign sig_137 = sig_100 ^ sig_112;
assign sig_138 = sig_100 & sig_112;
assign sig_139 = sig_137 & sig_136;
assign sig_140 = sig_137 ^ sig_136;
assign sig_141 = sig_138 | sig_139;
assign sig_142 = sig_105 ^ sig_113;
assign sig_143 = sig_105 & sig_113;
assign sig_144 = sig_142 & sig_141;
assign sig_145 = sig_142 ^ sig_141;
assign sig_146 = sig_143 | sig_144;
assign sig_147 = sig_106 ^ sig_114;
assign sig_148 = sig_106 & B[3];
assign sig_149 = A[7] & sig_146;
assign sig_150 = sig_147 ^ sig_146;
assign sig_151 = sig_148 | sig_149;

assign O[11] = sig_151;
assign O[10] = sig_150;
assign O[9] = sig_145;
assign O[8] = sig_140;
assign O[7] = sig_135;
assign O[6] = sig_25;
assign O[5] = sig_26;
assign O[4] = sig_25;
assign O[3] = sig_112;
assign O[2] = 1'b0;
assign O[1] = 1'b0;
assign O[0] = sig_26;

endmodule


