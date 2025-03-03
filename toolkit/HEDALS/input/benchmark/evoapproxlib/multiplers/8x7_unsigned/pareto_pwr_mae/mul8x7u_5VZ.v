/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mae parameters
***/
// MAE% = 0.049 %
// MAE = 16 
// WCE% = 0.19 %
// WCE = 61 
// WCRE% = 1500.00 %
// EP% = 95.65 %
// MRE% = 1.43 %
// MSE = 416 
// PDK45_PWR = 0.259 mW
// PDK45_AREA = 481.5 um2
// PDK45_DELAY = 1.36 ns

module mul8x7u_5VZ (
    A,
    B,
    O
);

input [7:0] A;
input [6:0] B;
output [14:0] O;

wire sig_20,sig_21,sig_22,sig_26,sig_27,sig_28,sig_29,sig_30,sig_39,sig_40,sig_41,sig_42,sig_43,sig_44,sig_48,sig_49,sig_50,sig_51,sig_52,sig_68;
wire sig_69,sig_73,sig_74,sig_75,sig_76,sig_77,sig_78,sig_79,sig_80,sig_81,sig_82,sig_83,sig_84,sig_86,sig_87,sig_90,sig_91,sig_92,sig_93,sig_94;
wire sig_95,sig_106,sig_107,sig_111,sig_112,sig_113,sig_114,sig_115,sig_116,sig_117,sig_118,sig_119,sig_120,sig_121,sig_122,sig_123,sig_124,sig_125,sig_126,sig_127;
wire sig_128,sig_129,sig_130,sig_132,sig_133,sig_134,sig_135,sig_136,sig_137,sig_138,sig_144,sig_145,sig_149,sig_150,sig_151,sig_152,sig_153,sig_154,sig_155,sig_156;
wire sig_157,sig_158,sig_159,sig_160,sig_161,sig_162,sig_163,sig_164,sig_165,sig_166,sig_167,sig_168,sig_169,sig_170,sig_171,sig_172,sig_173,sig_174,sig_175,sig_176;
wire sig_177,sig_178,sig_179,sig_180,sig_181,sig_182,sig_183,sig_187,sig_188,sig_189,sig_190,sig_191,sig_192,sig_193,sig_194,sig_195,sig_196,sig_197,sig_198,sig_199;
wire sig_200,sig_201,sig_202,sig_203,sig_204,sig_205,sig_206,sig_207,sig_208,sig_209,sig_210,sig_211,sig_212,sig_213,sig_214,sig_215,sig_216,sig_217,sig_218,sig_219;
wire sig_220,sig_221,sig_222,sig_223,sig_224,sig_225,sig_226,sig_227,sig_228,sig_229,sig_230,sig_231,sig_232,sig_233,sig_234,sig_235,sig_236,sig_237,sig_238,sig_239;
wire sig_240,sig_241,sig_242,sig_243,sig_244,sig_245,sig_246,sig_247,sig_248,sig_249,sig_250,sig_251,sig_252,sig_253,sig_254,sig_255,sig_256,sig_257,sig_258,sig_259;
wire sig_260,sig_261,sig_262,sig_263,sig_264,sig_265,sig_266,sig_267,sig_268,sig_269,sig_270,sig_271,sig_272,sig_273,sig_274,sig_275,sig_276,sig_277,sig_278,sig_279;
wire sig_280,sig_281,sig_282,sig_283,sig_284,sig_285,sig_286,sig_287,sig_288,sig_289,sig_290,sig_291,sig_292,sig_293,sig_294,sig_295,sig_296,sig_297,sig_298,sig_301;
wire sig_305,sig_306,sig_309,sig_310,sig_311,sig_312,sig_313,sig_314,sig_315,sig_316,sig_319,sig_320;

assign sig_20 = A[5] & B[0];
assign sig_21 = A[6] & B[0];
assign sig_22 = A[7] & B[0];
assign sig_26 = A[0] & B[0];
assign sig_27 = A[4] & B[1];
assign sig_28 = A[5] & B[1];
assign sig_29 = A[6] & B[1];
assign sig_30 = A[7] & B[1];
assign sig_39 = sig_20 & sig_27;
assign sig_40 = sig_20 | sig_27;
assign sig_41 = sig_21 & sig_28;
assign sig_42 = sig_21 ^ sig_28;
assign sig_43 = sig_22 & sig_29;
assign sig_44 = sig_22 ^ sig_29;
assign sig_48 = A[3] & B[2];
assign sig_49 = A[4] & B[2];
assign sig_50 = A[5] & B[2];
assign sig_51 = A[6] & B[2];
assign sig_52 = A[7] & B[2];
assign sig_68 = sig_40 | sig_48;
assign sig_69 = sig_40 & sig_48;
assign sig_73 = sig_42 ^ sig_49;
assign sig_74 = sig_42 & sig_49;
assign sig_75 = sig_73 & sig_39;
assign sig_76 = sig_73 ^ sig_39;
assign sig_77 = sig_74 | sig_75;
assign sig_78 = sig_44 ^ sig_50;
assign sig_79 = sig_44 & sig_50;
assign sig_80 = sig_78 & sig_41;
assign sig_81 = sig_78 ^ sig_41;
assign sig_82 = sig_79 | sig_80;
assign sig_83 = sig_30 ^ sig_51;
assign sig_84 = sig_30 & sig_51;
assign sig_86 = sig_83 ^ sig_43;
assign sig_87 = sig_84 | sig_43;
assign sig_90 = A[2] & B[3];
assign sig_91 = A[3] & B[3];
assign sig_92 = A[4] & B[3];
assign sig_93 = A[5] & B[3];
assign sig_94 = A[6] & B[3];
assign sig_95 = A[7] & B[3];
assign sig_106 = sig_68 | sig_90;
assign sig_107 = sig_68 & sig_90;
assign sig_111 = sig_76 ^ sig_91;
assign sig_112 = sig_76 & sig_91;
assign sig_113 = sig_111 & sig_69;
assign sig_114 = sig_111 ^ sig_69;
assign sig_115 = sig_112 | sig_113;
assign sig_116 = sig_81 ^ sig_92;
assign sig_117 = sig_81 & sig_92;
assign sig_118 = sig_116 & sig_77;
assign sig_119 = sig_116 ^ sig_77;
assign sig_120 = sig_117 | sig_118;
assign sig_121 = sig_86 ^ sig_93;
assign sig_122 = sig_86 & sig_93;
assign sig_123 = sig_121 & sig_82;
assign sig_124 = sig_121 ^ sig_82;
assign sig_125 = sig_122 | sig_123;
assign sig_126 = sig_52 ^ sig_94;
assign sig_127 = sig_52 & sig_94;
assign sig_128 = sig_126 & sig_87;
assign sig_129 = sig_126 ^ sig_87;
assign sig_130 = sig_127 | sig_128;
assign sig_132 = A[1] & B[4];
assign sig_133 = A[2] & B[4];
assign sig_134 = A[3] & B[4];
assign sig_135 = A[4] & B[4];
assign sig_136 = A[5] & B[4];
assign sig_137 = A[6] & B[4];
assign sig_138 = A[7] & B[4];
assign sig_144 = sig_106 | sig_132;
assign sig_145 = sig_106 & sig_132;
assign sig_149 = sig_114 ^ sig_133;
assign sig_150 = sig_114 & sig_133;
assign sig_151 = sig_149 & sig_107;
assign sig_152 = sig_149 ^ sig_107;
assign sig_153 = sig_150 | sig_151;
assign sig_154 = sig_119 ^ sig_134;
assign sig_155 = sig_119 & sig_134;
assign sig_156 = sig_154 & sig_115;
assign sig_157 = sig_154 ^ sig_115;
assign sig_158 = sig_155 | sig_156;
assign sig_159 = sig_124 ^ sig_135;
assign sig_160 = sig_124 & sig_135;
assign sig_161 = sig_159 & sig_120;
assign sig_162 = sig_159 ^ sig_120;
assign sig_163 = sig_160 | sig_161;
assign sig_164 = sig_129 ^ sig_136;
assign sig_165 = sig_129 & sig_136;
assign sig_166 = sig_164 & sig_125;
assign sig_167 = sig_164 ^ sig_125;
assign sig_168 = sig_165 | sig_166;
assign sig_169 = sig_95 ^ sig_137;
assign sig_170 = sig_95 & sig_137;
assign sig_171 = sig_169 & sig_130;
assign sig_172 = sig_169 ^ sig_130;
assign sig_173 = sig_170 | sig_171;
assign sig_174 = A[0] & B[5];
assign sig_175 = A[1] & B[5];
assign sig_176 = A[2] & B[5];
assign sig_177 = A[3] & B[5];
assign sig_178 = A[4] & B[5];
assign sig_179 = A[5] & B[5];
assign sig_180 = A[6] & B[5];
assign sig_181 = A[7] & B[5];
assign sig_182 = sig_144 ^ sig_174;
assign sig_183 = sig_144 & sig_174;
assign sig_187 = sig_152 ^ sig_175;
assign sig_188 = sig_152 & sig_175;
assign sig_189 = sig_187 & sig_145;
assign sig_190 = sig_187 ^ sig_145;
assign sig_191 = sig_188 | sig_189;
assign sig_192 = sig_157 ^ sig_176;
assign sig_193 = sig_157 & sig_176;
assign sig_194 = sig_192 & sig_153;
assign sig_195 = sig_192 ^ sig_153;
assign sig_196 = sig_193 | sig_194;
assign sig_197 = sig_162 ^ sig_177;
assign sig_198 = sig_162 & sig_177;
assign sig_199 = sig_197 & sig_158;
assign sig_200 = sig_197 ^ sig_158;
assign sig_201 = sig_198 | sig_199;
assign sig_202 = sig_167 ^ sig_178;
assign sig_203 = sig_167 & sig_178;
assign sig_204 = sig_202 & sig_163;
assign sig_205 = sig_202 ^ sig_163;
assign sig_206 = sig_203 | sig_204;
assign sig_207 = sig_172 ^ sig_179;
assign sig_208 = sig_172 & sig_179;
assign sig_209 = sig_207 & sig_168;
assign sig_210 = sig_207 ^ sig_168;
assign sig_211 = sig_208 | sig_209;
assign sig_212 = sig_138 ^ sig_180;
assign sig_213 = sig_138 & sig_180;
assign sig_214 = sig_212 & sig_173;
assign sig_215 = sig_212 ^ sig_173;
assign sig_216 = sig_213 | sig_214;
assign sig_217 = A[0] & B[6];
assign sig_218 = A[1] & B[6];
assign sig_219 = A[2] & B[6];
assign sig_220 = A[3] & B[6];
assign sig_221 = A[4] & B[6];
assign sig_222 = A[5] & B[6];
assign sig_223 = A[6] & B[6];
assign sig_224 = A[7] & B[6];
assign sig_225 = sig_190 ^ sig_217;
assign sig_226 = sig_190 & sig_217;
assign sig_227 = sig_225 & sig_183;
assign sig_228 = sig_225 ^ sig_183;
assign sig_229 = sig_226 | sig_227;
assign sig_230 = sig_195 ^ sig_218;
assign sig_231 = sig_195 & sig_218;
assign sig_232 = sig_230 & sig_191;
assign sig_233 = sig_230 ^ sig_191;
assign sig_234 = sig_231 | sig_232;
assign sig_235 = sig_200 ^ sig_219;
assign sig_236 = sig_200 & sig_219;
assign sig_237 = sig_235 & sig_196;
assign sig_238 = sig_235 ^ sig_196;
assign sig_239 = sig_236 | sig_237;
assign sig_240 = sig_205 ^ sig_220;
assign sig_241 = sig_205 & sig_220;
assign sig_242 = sig_240 & sig_201;
assign sig_243 = sig_240 ^ sig_201;
assign sig_244 = sig_241 | sig_242;
assign sig_245 = sig_210 ^ sig_221;
assign sig_246 = sig_210 & sig_221;
assign sig_247 = sig_245 & sig_206;
assign sig_248 = sig_245 ^ sig_206;
assign sig_249 = sig_246 | sig_247;
assign sig_250 = sig_215 ^ sig_222;
assign sig_251 = sig_215 & sig_222;
assign sig_252 = sig_250 & sig_211;
assign sig_253 = sig_250 ^ sig_211;
assign sig_254 = sig_251 | sig_252;
assign sig_255 = sig_181 ^ sig_223;
assign sig_256 = sig_181 & sig_223;
assign sig_257 = sig_255 & sig_216;
assign sig_258 = sig_255 ^ sig_216;
assign sig_259 = sig_256 | sig_257;
assign sig_260 = sig_233 & sig_229;
assign sig_261 = sig_233 ^ sig_229;
assign sig_262 = sig_238 & sig_234;
assign sig_263 = sig_238 ^ sig_234;
assign sig_264 = sig_243 & sig_239;
assign sig_265 = sig_243 ^ sig_239;
assign sig_266 = sig_248 & sig_244;
assign sig_267 = sig_248 ^ sig_244;
assign sig_268 = sig_253 & sig_249;
assign sig_269 = sig_253 ^ sig_249;
assign sig_270 = sig_258 & sig_254;
assign sig_271 = sig_258 ^ sig_254;
assign sig_272 = sig_224 & sig_259;
assign sig_273 = sig_224 ^ sig_259;
assign sig_274 = sig_263 ^ sig_260;
assign sig_275 = sig_263 & sig_260;
assign sig_276 = sig_265 ^ sig_262;
assign sig_277 = sig_265 & sig_262;
assign sig_278 = sig_276 & sig_275;
assign sig_279 = sig_276 ^ sig_275;
assign sig_280 = sig_277 | sig_278;
assign sig_281 = sig_267 ^ sig_264;
assign sig_282 = sig_267 & sig_264;
assign sig_283 = sig_281 & sig_280;
assign sig_284 = sig_281 ^ sig_280;
assign sig_285 = sig_282 | sig_283;
assign sig_286 = sig_269 ^ sig_266;
assign sig_287 = sig_269 & sig_266;
assign sig_288 = sig_286 & sig_285;
assign sig_289 = sig_286 ^ sig_285;
assign sig_290 = sig_287 | sig_288;
assign sig_291 = sig_271 ^ sig_268;
assign sig_292 = sig_271 & sig_268;
assign sig_293 = sig_273 ^ sig_270;
assign sig_294 = sig_273 & sig_270;
assign sig_295 = sig_293 & sig_292;
assign sig_296 = sig_293 ^ sig_292;
assign sig_297 = sig_294 | sig_295;
assign sig_298 = sig_272 | sig_297;
assign sig_301 = ~sig_271;
assign sig_305 = sig_273 & sig_271;
assign sig_306 = sig_293 ^ sig_271;
assign sig_309 = ~sig_290;
assign sig_310 = sig_291 & sig_309;
assign sig_311 = sig_301 & sig_290;
assign sig_312 = sig_310 | sig_311;
assign sig_313 = ~sig_290;
assign sig_314 = sig_296 & sig_313;
assign sig_315 = sig_306 & sig_290;
assign sig_316 = sig_314 | sig_315;
assign sig_319 = sig_305 & sig_290;
assign sig_320 = sig_298 | sig_319;

assign O[14] = sig_320;
assign O[13] = sig_316;
assign O[12] = sig_312;
assign O[11] = sig_289;
assign O[10] = sig_284;
assign O[9] = sig_279;
assign O[8] = sig_274;
assign O[7] = sig_261;
assign O[6] = sig_228;
assign O[5] = sig_182;
assign O[4] = sig_26;
assign O[3] = sig_144;
assign O[2] = sig_178;
assign O[1] = sig_162;
assign O[0] = sig_195;

endmodule


