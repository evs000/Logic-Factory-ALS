/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, Z. Vasicek and R. Hrbacek, "Role of circuit representation in evolutionary design of energy-efficient approximate circuits" in IET Computers & Digital Techniques, vol. 12, no. 4, pp. 139-149, 7 2018. doi: 10.1049/iet-cdt.2017.0188 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and wce parameters
***/
// MAE% = 0.012 %
// MAE = 1.0 
// WCE% = 0.024 %
// WCE = 2.0 
// WCRE% = 100.00 %
// EP% = 75.00 %
// MRE% = 0.034 %
// MSE = 1.5 
// PDK45_PWR = 0.045 mW
// PDK45_AREA = 91.5 um2
// PDK45_DELAY = 0.84 ns
#include <stdint.h>
#include <stdlib.h>

uint64_t add12u_4NT(uint64_t a, uint64_t b) {
  uint64_t o = 0;
  int n_78=0, n_410=0, n_254=0, n_796=0, n_547=0, n_318=0, n_702=0, n_45=0, n_44=0, n_47=0;
  int n_46=0, n_41=0, n_40=0, n_43=0, n_42=0, n_49=0, n_48=0, n_380=0, n_826=0, n_141=0;
  int n_140=0, n_670=0, n_462=0, n_816=0, n_774=0, n_775=0, n_400=0, n_244=0, n_712=0, n_546=0;
  int n_30=0, n_31=0, n_32=0, n_33=0, n_34=0, n_35=0, n_36=0, n_37=0, n_38=0, n_39=0;
  int n_817=0, n_79=0, n_785=0, n_390=0, n_784=0, n_150=0, n_151=0, n_660=0, n_433=0, n_432=0;
  int n_235=0, n_234=0, n_23=0, n_22=0, n_21=0, n_20=0, n_27=0, n_26=0, n_25=0, n_24=0;
  int n_29=0, n_28=0, n_806=0, n_807=0, n_556=0, n_557=0, n_484=0, n_121=0, n_120=0, n_650=0;
  int n_836=0, n_348=0, n_224=0, n_423=0, n_307=0, n_18=0, n_19=0, n_16=0, n_17=0, n_14=0;
  int n_15=0, n_12=0, n_13=0, n_10=0, n_11=0, n_90=0, n_91=0, n_98=0, n_99=0, n_306=0;
  int n_338=0, n_130=0, n_131=0, n_628=0, n_827=0, n_452=0, n_192=0, n_588=0, n_89=0, n_88=0;
  int n_536=0, n_732=0, n_733=0, n_442=0, n_693=0, n_692=0, n_110=0, n_111=0, n_296=0, n_214=0;
  int n_745=0, n_744=0, n_504=0, n_276=0, n_567=0, n_566=0, n_370=0, n_680=0, n_163=0, n_162=0;
  int n_69=0, n_68=0, n_286=0, n_287=0, n_202=0, n_754=0, n_755=0, n_514=0, n_515=0, n_266=0;
  int n_8=0, n_9=0, n_4=0, n_5=0, n_6=0, n_7=0, n_0=0, n_1=0, n_2=0, n_3=0;
  int n_640=0, n_172=0, n_173=0, n_58=0, n_59=0, n_797=0, n_422=0, n_765=0, n_764=0, n_608=0;
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
  n_48 = n_0 & n_24;
  n_49 = n_48;
  n_58 = n_2;
  n_59 = n_58;
  n_68 = n_4 ^ n_28;
  n_69 = n_4 & n_28;
  n_78 = n_6 ^ n_30;
  n_79 = n_6 & n_30;
  n_88 = n_8 ^ n_32;
  n_89 = n_8 & n_32;
  n_90 = n_49;
  n_91 = n_90;
  n_98 = n_10 ^ n_34;
  n_99 = n_10 & n_34;
  n_110 = n_12 ^ n_36;
  n_111 = n_12 & n_36;
  n_120 = n_14 ^ n_38;
  n_121 = n_14 & n_38;
  n_130 = n_16 ^ n_40;
  n_131 = n_16 & n_40;
  n_140 = n_18 ^ n_42;
  n_141 = n_18 & n_42;
  n_150 = n_20 ^ n_44;
  n_151 = n_20 & n_44;
  n_162 = n_22 ^ n_46;
  n_163 = n_22 & n_46;
  n_172 = n_68 & n_2;
  n_173 = n_172;
  n_192 = n_69 | n_173;
  n_202 = n_88 & n_79;
  n_214 = n_88 & n_78;
  n_224 = n_89 | n_202;
  n_234 = n_110 & n_99;
  n_235 = n_234;
  n_244 = n_110 & n_98;
  n_254 = n_111 | n_235;
  n_266 = n_130 & n_121;
  n_276 = n_130 & n_120;
  n_286 = n_131 | n_266;
  n_287 = n_286;
  n_296 = n_150 & n_141;
  n_306 = n_150 & n_140;
  n_307 = n_306;
  n_318 = n_151 | n_296;
  n_338 = n_192;
  n_348 = n_214 & n_192;
  n_370 = n_224 | n_348;
  n_380 = n_244 & n_224;
  n_390 = n_244 & n_348;
  n_400 = n_254 | n_380;
  n_410 = n_276 & n_254;
  n_422 = n_276 & n_244;
  n_423 = n_422;
  n_432 = n_287 | n_410;
  n_433 = n_432;
  n_442 = n_307 & n_286;
  n_452 = n_306 & n_276;
  n_462 = n_318 | n_442;
  n_484 = n_370;
  n_504 = n_400 | n_390;
  n_514 = n_423 & n_370;
  n_515 = n_514;
  n_536 = n_433 | n_515;
  n_546 = n_452 & n_400;
  n_547 = n_546;
  n_556 = n_452 & n_390;
  n_557 = n_556;
  n_566 = n_462 | n_547;
  n_567 = n_566;
  n_588 = n_536;
  n_608 = n_567 | n_557;
  n_628 = n_59;
  n_640 = n_78 & n_338;
  n_650 = n_79 | n_640;
  n_660 = n_98 & n_484;
  n_670 = n_99 | n_660;
  n_680 = n_120 & n_504;
  n_692 = n_121 | n_680;
  n_693 = n_692;
  n_702 = n_140 & n_588;
  n_712 = n_141 | n_702;
  n_732 = n_68 ^ n_628;
  n_733 = n_68 & n_628;
  n_744 = n_78 ^ n_338;
  n_745 = n_78 & n_338;
  n_754 = n_88 ^ n_650;
  n_755 = n_88 & n_650;
  n_764 = n_98 ^ n_484;
  n_765 = n_98 & n_484;
  n_774 = n_110 ^ n_670;
  n_775 = n_110 & n_670;
  n_784 = n_120 ^ n_504;
  n_785 = n_120 & n_504;
  n_796 = n_130 ^ n_693;
  n_797 = n_130 & n_693;
  n_806 = n_140 ^ n_588;
  n_807 = n_140 & n_588;
  n_816 = n_150 ^ n_712;
  n_817 = n_150 & n_712;
  n_826 = n_162 ^ n_608;
  n_827 = n_162 & n_608;
  n_836 = n_163 | n_827;
  o |= (n_26 & 0x01) << 0;
  o |= (n_91 & 0x01) << 1;
  o |= (n_732 & 0x01) << 2;
  o |= (n_744 & 0x01) << 3;
  o |= (n_754 & 0x01) << 4;
  o |= (n_764 & 0x01) << 5;
  o |= (n_774 & 0x01) << 6;
  o |= (n_784 & 0x01) << 7;
  o |= (n_796 & 0x01) << 8;
  o |= (n_806 & 0x01) << 9;
  o |= (n_816 & 0x01) << 10;
  o |= (n_826 & 0x01) << 11;
  o |= (n_836 & 0x01) << 12;
  return o;
}
