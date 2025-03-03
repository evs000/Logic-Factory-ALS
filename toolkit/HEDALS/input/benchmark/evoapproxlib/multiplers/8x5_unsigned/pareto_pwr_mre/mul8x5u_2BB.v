/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mre parameters
***/
// MAE% = 0.0031 %
// MAE = 0.25 
// WCE% = 0.012 %
// WCE = 1.0 
// WCRE% = 100.00 %
// EP% = 25.00 %
// MRE% = 0.10 %
// MSE = 0.25 
// PDK45_PWR = 0.192 mW
// PDK45_AREA = 413.5 um2
// PDK45_DELAY = 1.37 ns

module mul8x5u_2BB (
    A,
    B,
    O
);

input [7:0] A;
input [4:0] B;
output [12:0] O;

wire sig_14,sig_15,sig_16,sig_17,sig_18,sig_19,sig_20,sig_21,sig_22,sig_23,sig_24,sig_25,sig_26,sig_27,sig_28,sig_29,sig_30,sig_31,sig_32,sig_33;
wire sig_34,sig_35,sig_36,sig_37,sig_38,sig_39,sig_40,sig_41,sig_42,sig_43,sig_44,sig_45,sig_46,sig_47,sig_48,sig_49,sig_50,sig_51,sig_52,sig_53;
wire sig_54,sig_55,sig_56,sig_57,sig_58,sig_59,sig_60,sig_61,sig_62,sig_63,sig_64,sig_65,sig_66,sig_67,sig_68,sig_69,sig_70,sig_71,sig_72,sig_73;
wire sig_74,sig_75,sig_76,sig_77,sig_78,sig_79,sig_80,sig_81,sig_82,sig_83,sig_84,sig_85,sig_86,sig_87,sig_88,sig_89,sig_90,sig_91,sig_92,sig_93;
wire sig_94,sig_95,sig_96,sig_97,sig_98,sig_99,sig_100,sig_101,sig_102,sig_103,sig_104,sig_105,sig_106,sig_107,sig_108,sig_109,sig_110,sig_111,sig_112,sig_113;
wire sig_114,sig_115,sig_116,sig_117,sig_118,sig_119,sig_120,sig_121,sig_122,sig_123,sig_124,sig_125,sig_126,sig_127,sig_128,sig_129,sig_130,sig_131,sig_132,sig_133;
wire sig_134,sig_135,sig_136,sig_137,sig_138,sig_139,sig_140,sig_141,sig_142,sig_143,sig_144,sig_145,sig_146,sig_147,sig_148,sig_149,sig_150,sig_151,sig_152,sig_153;
wire sig_154,sig_155,sig_156,sig_157,sig_158,sig_159,sig_160,sig_161,sig_162,sig_163,sig_164,sig_165,sig_166,sig_167,sig_168,sig_169,sig_170,sig_171,sig_172,sig_173;
wire sig_174,sig_175,sig_176,sig_177,sig_178,sig_179,sig_180,sig_181,sig_182,sig_183,sig_184,sig_185,sig_186,sig_187,sig_188,sig_189,sig_190,sig_191,sig_192,sig_193;
wire sig_194,sig_195,sig_196,sig_197;

assign sig_14 = A[1] & B[0];
assign sig_15 = A[2] & B[0];
assign sig_16 = A[3] & B[0];
assign sig_17 = A[4] & B[0];
assign sig_18 = A[5] & B[0];
assign sig_19 = A[6] & B[0];
assign sig_20 = A[7] & B[0];
assign sig_21 = A[0] & B[1];
assign sig_22 = A[1] & B[1];
assign sig_23 = A[2] & B[1];
assign sig_24 = A[3] & B[1];
assign sig_25 = A[4] & B[1];
assign sig_26 = A[5] & B[1];
assign sig_27 = A[6] & B[1];
assign sig_28 = A[7] & B[1];
assign sig_29 = sig_14 & sig_21;
assign sig_30 = sig_14 | sig_21;
assign sig_31 = sig_15 ^ sig_22;
assign sig_32 = sig_15 & sig_22;
assign sig_33 = sig_21 & sig_14;
assign sig_34 = sig_31 ^ sig_33;
assign sig_35 = sig_32 | sig_29;
assign sig_36 = sig_16 ^ sig_23;
assign sig_37 = sig_16 & sig_23;
assign sig_38 = sig_36 & sig_35;
assign sig_39 = sig_36 ^ sig_35;
assign sig_40 = sig_37 | sig_38;
assign sig_41 = sig_17 ^ sig_24;
assign sig_42 = sig_17 & sig_24;
assign sig_43 = sig_41 & sig_40;
assign sig_44 = sig_41 ^ sig_40;
assign sig_45 = sig_42 | sig_43;
assign sig_46 = sig_18 ^ sig_25;
assign sig_47 = sig_18 & sig_25;
assign sig_48 = sig_46 & sig_45;
assign sig_49 = sig_46 ^ sig_45;
assign sig_50 = sig_47 | sig_48;
assign sig_51 = sig_19 ^ sig_26;
assign sig_52 = sig_19 & sig_26;
assign sig_53 = sig_51 & sig_50;
assign sig_54 = sig_51 ^ sig_50;
assign sig_55 = sig_52 | sig_53;
assign sig_56 = sig_20 ^ sig_27;
assign sig_57 = sig_20 & sig_27;
assign sig_58 = sig_56 & sig_55;
assign sig_59 = sig_56 ^ sig_55;
assign sig_60 = sig_57 | sig_58;
assign sig_61 = sig_60 & sig_28;
assign sig_62 = sig_60 ^ sig_28;
assign sig_63 = A[0] & B[2];
assign sig_64 = A[1] & B[2];
assign sig_65 = A[2] & B[2];
assign sig_66 = A[3] & B[2];
assign sig_67 = A[4] & B[2];
assign sig_68 = A[5] & B[2];
assign sig_69 = A[6] & B[2];
assign sig_70 = A[7] & B[2];
assign sig_71 = sig_34 & sig_63;
assign sig_72 = sig_34 ^ sig_63;
assign sig_73 = sig_39 ^ sig_64;
assign sig_74 = sig_39 & sig_64;
assign sig_75 = sig_73 & sig_71;
assign sig_76 = sig_73 ^ sig_71;
assign sig_77 = sig_74 | sig_75;
assign sig_78 = sig_44 ^ sig_65;
assign sig_79 = sig_44 & sig_65;
assign sig_80 = sig_78 & sig_77;
assign sig_81 = sig_78 ^ sig_77;
assign sig_82 = sig_79 | sig_80;
assign sig_83 = sig_49 ^ sig_66;
assign sig_84 = sig_49 & sig_66;
assign sig_85 = sig_83 & sig_82;
assign sig_86 = sig_83 ^ sig_82;
assign sig_87 = sig_84 | sig_85;
assign sig_88 = sig_54 ^ sig_67;
assign sig_89 = sig_54 & sig_67;
assign sig_90 = sig_88 & sig_87;
assign sig_91 = sig_88 ^ sig_87;
assign sig_92 = sig_89 | sig_90;
assign sig_93 = sig_59 ^ sig_68;
assign sig_94 = sig_59 & sig_68;
assign sig_95 = sig_93 & sig_92;
assign sig_96 = sig_93 ^ sig_92;
assign sig_97 = sig_94 | sig_95;
assign sig_98 = sig_62 ^ sig_69;
assign sig_99 = sig_62 & sig_69;
assign sig_100 = sig_98 & sig_97;
assign sig_101 = sig_98 ^ sig_97;
assign sig_102 = sig_99 | sig_100;
assign sig_103 = sig_61 ^ sig_70;
assign sig_104 = sig_61 & B[2];
assign sig_105 = sig_103 & sig_102;
assign sig_106 = sig_103 ^ sig_102;
assign sig_107 = sig_104 | sig_105;
assign sig_108 = A[0] & B[3];
assign sig_109 = A[1] & B[3];
assign sig_110 = A[2] & B[3];
assign sig_111 = A[3] & B[3];
assign sig_112 = A[4] & B[3];
assign sig_113 = A[5] & B[3];
assign sig_114 = A[6] & B[3];
assign sig_115 = A[7] & B[3];
assign sig_116 = sig_76 & sig_108;
assign sig_117 = sig_76 ^ sig_108;
assign sig_118 = sig_81 ^ sig_109;
assign sig_119 = sig_81 & sig_109;
assign sig_120 = sig_118 & sig_116;
assign sig_121 = sig_118 ^ sig_116;
assign sig_122 = sig_119 | sig_120;
assign sig_123 = sig_86 ^ sig_110;
assign sig_124 = sig_86 & sig_110;
assign sig_125 = sig_123 & sig_122;
assign sig_126 = sig_123 ^ sig_122;
assign sig_127 = sig_124 | sig_125;
assign sig_128 = sig_91 ^ sig_111;
assign sig_129 = sig_91 & sig_111;
assign sig_130 = sig_128 & sig_127;
assign sig_131 = sig_128 ^ sig_127;
assign sig_132 = sig_129 | sig_130;
assign sig_133 = sig_96 ^ sig_112;
assign sig_134 = sig_96 & sig_112;
assign sig_135 = sig_133 & sig_132;
assign sig_136 = sig_133 ^ sig_132;
assign sig_137 = sig_134 | sig_135;
assign sig_138 = sig_101 ^ sig_113;
assign sig_139 = sig_101 & sig_113;
assign sig_140 = sig_138 & sig_137;
assign sig_141 = sig_138 ^ sig_137;
assign sig_142 = sig_139 | sig_140;
assign sig_143 = sig_106 ^ sig_114;
assign sig_144 = sig_106 & sig_114;
assign sig_145 = sig_143 & sig_142;
assign sig_146 = sig_143 ^ sig_142;
assign sig_147 = sig_144 | sig_145;
assign sig_148 = sig_107 ^ sig_115;
assign sig_149 = sig_107 & sig_115;
assign sig_150 = A[7] & sig_147;
assign sig_151 = sig_148 ^ sig_147;
assign sig_152 = sig_149 | sig_150;
assign sig_153 = A[0] & B[4];
assign sig_154 = A[1] & B[4];
assign sig_155 = A[2] & B[4];
assign sig_156 = A[3] & B[4];
assign sig_157 = A[4] & B[4];
assign sig_158 = A[5] & B[4];
assign sig_159 = A[6] & B[4];
assign sig_160 = A[7] & B[4];
assign sig_161 = sig_121 & sig_153;
assign sig_162 = sig_121 ^ sig_153;
assign sig_163 = sig_126 ^ sig_154;
assign sig_164 = sig_126 & sig_154;
assign sig_165 = sig_163 & sig_161;
assign sig_166 = sig_163 ^ sig_161;
assign sig_167 = sig_164 | sig_165;
assign sig_168 = sig_131 ^ sig_155;
assign sig_169 = sig_131 & sig_155;
assign sig_170 = sig_168 & sig_167;
assign sig_171 = sig_168 ^ sig_167;
assign sig_172 = sig_169 | sig_170;
assign sig_173 = sig_136 ^ sig_156;
assign sig_174 = sig_136 & sig_156;
assign sig_175 = sig_173 & sig_172;
assign sig_176 = sig_173 ^ sig_172;
assign sig_177 = sig_174 | sig_175;
assign sig_178 = sig_141 ^ sig_157;
assign sig_179 = sig_141 & sig_157;
assign sig_180 = sig_178 & sig_177;
assign sig_181 = sig_178 ^ sig_177;
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
assign O[7] = sig_176;
assign O[6] = sig_171;
assign O[5] = sig_166;
assign O[4] = sig_162;
assign O[3] = sig_117;
assign O[2] = sig_72;
assign O[1] = sig_30;
assign O[0] = 1'b0;

endmodule


