/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mae parameters
***/
// MAE% = 0.95 %
// MAE = 78 
// WCE% = 4.00 %
// WCE = 328 
// WCRE% = 182.35 %
// EP% = 95.95 %
// MRE% = 15.33 %
// MSE = 9573 
// PDK45_PWR = 0.060 mW
// PDK45_AREA = 170.8 um2
// PDK45_DELAY = 0.78 ns

module mul8x5u_1EB (
    A,
    B,
    O
);

input [7:0] A;
input [4:0] B;
output [12:0] O;

wire sig_20,sig_53,sig_61,sig_62,sig_68,sig_69,sig_70,sig_79,sig_98,sig_100,sig_101,sig_102,sig_103,sig_104,sig_105,sig_106,sig_107,sig_112,sig_113,sig_114;
wire sig_115,sig_126,sig_129,sig_138,sig_139,sig_140,sig_141,sig_142,sig_143,sig_145,sig_146,sig_147,sig_148,sig_149,sig_150,sig_151,sig_152,sig_156,sig_157,sig_158;
wire sig_159,sig_160,sig_173,sig_174,sig_178,sig_179,sig_180,sig_181,sig_182,sig_183,sig_184,sig_185,sig_186,sig_187,sig_188,sig_189,sig_190,sig_191,sig_192,sig_193;
wire sig_194,sig_195,sig_196,sig_197;

assign sig_20 = B[1] & A[7];
assign sig_53 = A[6] & B[1];
assign sig_61 = sig_53 & A[7];
assign sig_62 = sig_53 ^ sig_20;
assign sig_68 = A[5] & B[2];
assign sig_69 = A[6] & B[2];
assign sig_70 = A[7] & B[2];
assign sig_79 = sig_69 & sig_62;
assign sig_98 = sig_62 ^ sig_69;
assign sig_100 = sig_98 & sig_68;
assign sig_101 = sig_98 ^ sig_68;
assign sig_102 = sig_79 | sig_100;
assign sig_103 = sig_61 ^ sig_70;
assign sig_104 = sig_61 & B[2];
assign sig_105 = A[7] & sig_102;
assign sig_106 = sig_103 ^ sig_102;
assign sig_107 = sig_104 | sig_105;
assign sig_112 = A[4] & B[3];
assign sig_113 = A[5] & B[3];
assign sig_114 = A[6] & B[3];
assign sig_115 = A[7] & B[3];
assign sig_126 = A[7] & B[0];
assign sig_129 = sig_114 & sig_106;
assign sig_138 = sig_101 ^ sig_113;
assign sig_139 = sig_101 & sig_113;
assign sig_140 = sig_138 & sig_112;
assign sig_141 = sig_138 ^ sig_112;
assign sig_142 = sig_139 | sig_140;
assign sig_143 = sig_106 ^ sig_114;
assign sig_145 = sig_143 & sig_142;
assign sig_146 = sig_143 ^ sig_142;
assign sig_147 = sig_129 | sig_145;
assign sig_148 = sig_107 ^ sig_115;
assign sig_149 = sig_107 & B[3];
assign sig_150 = A[7] & sig_147;
assign sig_151 = sig_148 ^ sig_147;
assign sig_152 = sig_149 | sig_150;
assign sig_156 = A[3] & B[4];
assign sig_157 = A[4] & B[4];
assign sig_158 = A[5] & B[4];
assign sig_159 = A[6] & B[4];
assign sig_160 = A[7] & B[4];
assign sig_173 = sig_126 | sig_156;
assign sig_174 = B[0] & sig_156;
assign sig_178 = sig_141 ^ sig_157;
assign sig_179 = sig_141 & sig_157;
assign sig_180 = sig_178 & sig_174;
assign sig_181 = sig_178 ^ sig_174;
assign sig_182 = sig_179 | sig_180;
assign sig_183 = sig_146 ^ sig_158;
assign sig_184 = sig_146 & sig_158;
assign sig_185 = sig_183 & sig_182;
assign sig_186 = sig_183 ^ sig_182;
assign sig_187 = sig_184 | sig_185;
assign sig_188 = sig_151 ^ sig_159;
assign sig_189 = sig_151 & sig_159;
assign sig_190 = sig_188 & sig_187;
assign sig_191 = sig_188 ^ sig_187;
assign sig_192 = sig_189 | sig_190;
assign sig_193 = sig_152 ^ sig_160;
assign sig_194 = sig_152 & B[4];
assign sig_195 = sig_160 & sig_192;
assign sig_196 = sig_193 ^ sig_192;
assign sig_197 = sig_194 | sig_195;

assign O[12] = sig_197;
assign O[11] = sig_196;
assign O[10] = sig_191;
assign O[9] = sig_186;
assign O[8] = sig_181;
assign O[7] = sig_173;
assign O[6] = 1'b0;
assign O[5] = sig_126;
assign O[4] = sig_191;
assign O[3] = sig_104;
assign O[2] = sig_107;
assign O[1] = sig_186;
assign O[0] = sig_70;

endmodule


