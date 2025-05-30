/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, Z. Vasicek and R. Hrbacek, "Role of circuit representation in evolutionary design of energy-efficient approximate circuits" in IET Computers & Digital Techniques, vol. 12, no. 4, pp. 139-149, 7 2018. doi: 10.1049/iet-cdt.2017.0188 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mre parameters
***/
// MAE% = 0.0061 %
// MAE = 0.5 
// WCE% = 0.012 %
// WCE = 1.0 
// WCRE% = 50.00 %
// EP% = 50.00 %
// MRE% = 0.017 %
// MSE = 0.5 
// PDK45_PWR = 0.047 mW
// PDK45_AREA = 97.1 um2
// PDK45_DELAY = 0.88 ns
#include <stdint.h>
#include <stdlib.h>

uint64_t add12u_39N(uint64_t a, uint64_t b) {
  uint64_t o = 0;
  int n_415=0, n_410=0, n_255=0, n_312=0, n_259=0, n_419=0, n_317=0, n_46=0, n_41=0, n_384=0;
  int n_148=0, n_388=0, n_406=0, n_68=0, n_401=0, n_246=0, n_241=0, n_32=0, n_37=0, n_397=0;
  int n_392=0, n_299=0, n_152=0, n_157=0, n_237=0, n_23=0, n_22=0, n_21=0, n_20=0, n_24=0;
  int n_28=0, n_126=0, n_121=0, n_344=0, n_228=0, n_184=0, n_188=0, n_348=0, n_224=0, n_2=0;
  int n_18=0, n_19=0, n_16=0, n_17=0, n_14=0, n_15=0, n_12=0, n_13=0, n_10=0, n_11=0;
  int n_95=0, n_90=0, n_99=0, n_330=0, n_335=0, n_139=0, n_339=0, n_135=0, n_357=0, n_352=0;
  int n_197=0, n_81=0, n_86=0, n_108=0, n_104=0, n_361=0, n_366=0, n_117=0, n_112=0, n_295=0;
  int n_77=0, n_72=0, n_290=0, n_215=0, n_219=0, n_277=0, n_379=0, n_272=0, n_375=0, n_370=0;
  int n_161=0, n_166=0, n_281=0, n_64=0, n_201=0, n_206=0, n_264=0, n_8=0, n_9=0, n_4=0;
  int n_5=0, n_6=0, n_7=0, n_0=0, n_1=0, n_268=0, n_3=0, n_59=0, n_175=0, n_52=0;
  int n_50=0, n_179=0, n_55=0;
  n_0 = (a >> 0) & 0x1;
  n_1 = (a >> 1) & 0x1;
  n_2 = (a >> 2) & 0x1;
  n_3 = (a >> 3) & 0x1;
  n_4 = (a >> 4) & 0x1;
  n_5 = (a >> 5) & 0x1;
  n_6 = (a >> 6) & 0x1;
  n_7 = (a >> 7) & 0x1;
  n_8 = (a >> 8) & 0x1;
  n_9 = (a >> 9) & 0x1;
  n_10 = (a >> 10) & 0x1;
  n_11 = (a >> 11) & 0x1;
  n_12 = (b >> 0) & 0x1;
  n_13 = (b >> 1) & 0x1;
  n_14 = (b >> 2) & 0x1;
  n_15 = (b >> 3) & 0x1;
  n_16 = (b >> 4) & 0x1;
  n_17 = (b >> 5) & 0x1;
  n_18 = (b >> 6) & 0x1;
  n_19 = (b >> 7) & 0x1;
  n_20 = (b >> 8) & 0x1;
  n_21 = (b >> 9) & 0x1;
  n_22 = (b >> 10) & 0x1;
  n_23 = (b >> 11) & 0x1;
  n_24 = ~(n_11 | n_21);
  n_28 = n_24 & n_21;
  n_32 = n_1 ^ n_13;
  n_37 = n_1 & n_13;
  n_41 = n_2 ^ n_14;
  n_46 = n_2 & n_14;
  n_50 = n_3 ^ n_15;
  n_52 = ~(n_6 & n_28);
  n_55 = n_3 & n_15;
  n_59 = n_4 ^ n_16;
  n_64 = n_4 & n_16;
  n_68 = n_5 ^ n_17;
  n_72 = n_5 & n_17;
  n_77 = n_6 ^ n_18;
  n_81 = n_6 & n_18;
  n_86 = n_7 ^ n_19;
  n_90 = n_7 & n_19;
  n_95 = n_8 ^ n_20;
  n_99 = n_8 & n_20;
  n_104 = n_9 ^ n_21;
  n_108 = n_9 & n_21;
  n_112 = n_10 ^ n_22;
  n_117 = n_10 & n_22;
  n_121 = n_11 ^ n_23;
  n_126 = n_11 & n_23;
  n_135 = n_28 | n_37;
  n_139 = n_2 & n_50;
  n_148 = n_13 & n_50;
  n_152 = n_14 & n_139;
  n_157 = n_152 | n_55;
  n_161 = n_157 & n_59;
  n_166 = n_161 | n_64;
  n_175 = n_13 & n_59;
  n_179 = n_72 & n_77;
  n_184 = n_179 | n_81;
  n_188 = n_68 & n_77;
  n_197 = n_179 | n_81;
  n_201 = n_197 & n_86;
  n_206 = n_201 | n_90;
  n_215 = n_188 & n_86;
  n_219 = n_99 & n_104;
  n_224 = n_219 | n_108;
  n_228 = n_95 & n_104;
  n_237 = n_224;
  n_241 = n_237 & n_112;
  n_246 = n_241 | n_117;
  n_255 = n_52 & n_112;
  n_259 = n_37 & n_41;
  n_264 = n_259 | n_46;
  n_268 = n_259 & n_148;
  n_272 = n_268 | n_157;
  n_277 = n_268 & n_175;
  n_281 = n_277 | n_166;
  n_290 = n_277 | n_166;
  n_295 = n_290 & n_68;
  n_299 = n_295 | n_72;
  n_312 = n_295 & n_188;
  n_317 = n_312 | n_184;
  n_330 = n_312 & n_215;
  n_335 = n_330 | n_206;
  n_339 = n_335 & n_95;
  n_344 = n_339 | n_99;
  n_348 = n_335 & n_228;
  n_352 = n_348 | n_224;
  n_357 = n_348 & n_255;
  n_361 = n_357 | n_246;
  n_366 = n_32;
  n_370 = n_41 ^ n_135;
  n_375 = n_50 ^ n_264;
  n_379 = n_59 ^ n_272;
  n_384 = n_68 ^ n_281;
  n_388 = n_77 ^ n_299;
  n_392 = n_86 ^ n_317;
  n_397 = n_95 ^ n_335;
  n_401 = n_104 ^ n_344;
  n_406 = n_112 ^ n_352;
  n_410 = n_121 ^ n_361;
  n_415 = n_121 & n_361;
  n_419 = n_126 | n_415;
  o |= (n_52 & 0x01) << 0;
  o |= (n_366 & 0x01) << 1;
  o |= (n_370 & 0x01) << 2;
  o |= (n_375 & 0x01) << 3;
  o |= (n_379 & 0x01) << 4;
  o |= (n_384 & 0x01) << 5;
  o |= (n_388 & 0x01) << 6;
  o |= (n_392 & 0x01) << 7;
  o |= (n_397 & 0x01) << 8;
  o |= (n_401 & 0x01) << 9;
  o |= (n_406 & 0x01) << 10;
  o |= (n_410 & 0x01) << 11;
  o |= (n_419 & 0x01) << 12;
  return o;
}
