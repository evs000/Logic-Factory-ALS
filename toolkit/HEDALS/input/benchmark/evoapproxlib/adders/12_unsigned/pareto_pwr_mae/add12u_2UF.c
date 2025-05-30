/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, Z. Vasicek and R. Hrbacek, "Role of circuit representation in evolutionary design of energy-efficient approximate circuits" in IET Computers & Digital Techniques, vol. 12, no. 4, pp. 139-149, 7 2018. doi: 10.1049/iet-cdt.2017.0188 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mae parameters
***/
// MAE% = 0.00 %
// MAE = 0 
// WCE% = 0.00 %
// WCE = 0 
// WCRE% = 0.00 %
// EP% = 0.00 %
// MRE% = 0.00 %
// MSE = 0 
// PDK45_PWR = 0.052 mW
// PDK45_AREA = 106.1 um2
// PDK45_DELAY = 0.96 ns
#include <stdint.h>
#include <stdlib.h>

uint64_t add12u_2UF(uint64_t a, uint64_t b) {
  uint64_t o = 0;
  int n_415=0, n_414=0, n_36=0, n_349=0, n_42=0, n_37=0, n_314=0, n_315=0, n_23=0, n_22=0;
  int n_21=0, n_20=0, n_27=0, n_26=0, n_25=0, n_24=0, n_248=0, n_29=0, n_28=0, n_48=0;
  int n_249=0, n_81=0, n_80=0, n_149=0, n_148=0, n_67=0, n_66=0, n_214=0, n_129=0, n_128=0;
  int n_39=0, n_38=0, n_102=0, n_380=0, n_381=0, n_181=0, n_180=0, n_8=0, n_9=0, n_115=0;
  int n_4=0, n_5=0, n_6=0, n_7=0, n_0=0, n_1=0, n_2=0, n_3=0, n_30=0, n_31=0;
  int n_32=0, n_33=0, n_34=0, n_35=0, n_18=0, n_19=0, n_16=0, n_17=0, n_14=0, n_15=0;
  int n_12=0, n_13=0, n_10=0, n_11=0, n_114=0, n_45=0, n_58=0, n_59=0, n_44=0, n_43=0;
  int n_47=0, n_348=0, n_280=0, n_215=0, n_46=0, n_281=0, n_41=0, n_40=0;
  n_0 = (a >> 0) & 0x1;
  n_1 = (a >> 0) & 0x1;
  n_2 = (a >> 1) & 0x1;
  n_3 = (a >> 1) & 0x1;
  n_4 = (a >> 2) & 0x1;
  n_5 = (a >> 2) & 0x1;
  n_6 = (a >> 3) & 0x1;
  n_7 = (a >> 3) & 0x1;
  n_8 = (a >> 4) & 0x1;
  n_9 = (a >> 4) & 0x1;
  n_10 = (a >> 5) & 0x1;
  n_11 = (a >> 5) & 0x1;
  n_12 = (a >> 6) & 0x1;
  n_13 = (a >> 6) & 0x1;
  n_14 = (a >> 7) & 0x1;
  n_15 = (a >> 7) & 0x1;
  n_16 = (a >> 8) & 0x1;
  n_17 = (a >> 8) & 0x1;
  n_18 = (a >> 9) & 0x1;
  n_19 = (a >> 9) & 0x1;
  n_20 = (a >> 10) & 0x1;
  n_21 = (a >> 10) & 0x1;
  n_22 = (a >> 11) & 0x1;
  n_23 = (a >> 11) & 0x1;
  n_24 = (b >> 0) & 0x1;
  n_25 = (b >> 0) & 0x1;
  n_26 = (b >> 1) & 0x1;
  n_27 = (b >> 1) & 0x1;
  n_28 = (b >> 2) & 0x1;
  n_29 = (b >> 2) & 0x1;
  n_30 = (b >> 3) & 0x1;
  n_31 = (b >> 3) & 0x1;
  n_32 = (b >> 4) & 0x1;
  n_33 = (b >> 4) & 0x1;
  n_34 = (b >> 5) & 0x1;
  n_35 = (b >> 5) & 0x1;
  n_36 = (b >> 6) & 0x1;
  n_37 = (b >> 6) & 0x1;
  n_38 = (b >> 7) & 0x1;
  n_39 = (b >> 7) & 0x1;
  n_40 = (b >> 8) & 0x1;
  n_41 = (b >> 8) & 0x1;
  n_42 = (b >> 9) & 0x1;
  n_43 = (b >> 9) & 0x1;
  n_44 = (b >> 10) & 0x1;
  n_45 = (b >> 10) & 0x1;
  n_46 = (b >> 11) & 0x1;
  n_47 = (b >> 11) & 0x1;
  n_48 = n_0 ^ n_24;
  n_58 = n_0 & n_24;
  n_59 = n_58;
  n_66 = n_59;
  n_67 = n_66;
  n_80 = n_2 ^ n_26 ^n_67;
  n_81 = (n_2 & n_26) | (n_26 & n_67) | (n_2 & n_67);
  n_102 = n_81;
  n_114 = n_4 ^ n_28 ^n_102;
  n_115 = (n_4 & n_28) | (n_28 & n_102) | (n_4 & n_102);
  n_128 = n_115;
  n_129 = n_128;
  n_148 = n_6 ^ n_30 ^n_129;
  n_149 = (n_6 & n_30) | (n_30 & n_129) | (n_6 & n_129);
  n_180 = n_8 ^ n_32 ^n_149;
  n_181 = (n_8 & n_32) | (n_32 & n_149) | (n_8 & n_149);
  n_214 = n_10 ^ n_34 ^n_181;
  n_215 = (n_10 & n_34) | (n_34 & n_181) | (n_10 & n_181);
  n_248 = n_12 ^ n_36 ^n_215;
  n_249 = (n_12 & n_36) | (n_36 & n_215) | (n_12 & n_215);
  n_280 = n_14 ^ n_38 ^n_249;
  n_281 = (n_14 & n_38) | (n_38 & n_249) | (n_14 & n_249);
  n_314 = n_16 ^ n_40 ^n_281;
  n_315 = (n_16 & n_40) | (n_40 & n_281) | (n_16 & n_281);
  n_348 = n_18 ^ n_42 ^n_315;
  n_349 = (n_18 & n_42) | (n_42 & n_315) | (n_18 & n_315);
  n_380 = n_20 ^ n_44 ^n_349;
  n_381 = (n_20 & n_44) | (n_44 & n_349) | (n_20 & n_349);
  n_414 = n_22 ^ n_46 ^n_381;
  n_415 = (n_22 & n_46) | (n_46 & n_381) | (n_22 & n_381);
  o |= (n_48 & 0x01) << 0;
  o |= (n_80 & 0x01) << 1;
  o |= (n_114 & 0x01) << 2;
  o |= (n_148 & 0x01) << 3;
  o |= (n_180 & 0x01) << 4;
  o |= (n_214 & 0x01) << 5;
  o |= (n_248 & 0x01) << 6;
  o |= (n_280 & 0x01) << 7;
  o |= (n_314 & 0x01) << 8;
  o |= (n_348 & 0x01) << 9;
  o |= (n_380 & 0x01) << 10;
  o |= (n_414 & 0x01) << 11;
  o |= (n_415 & 0x01) << 12;
  return o;
}
