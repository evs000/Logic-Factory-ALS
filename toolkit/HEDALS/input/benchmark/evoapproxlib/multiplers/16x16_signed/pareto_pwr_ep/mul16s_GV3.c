/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, Z. Vasicek, L. Sekanina, H. Jiang and J. Han, "Scalable Construction of Approximate Multipliers With Formally Guaranteed Worst Case Error" in IEEE Transactions on Very Large Scale Integration (VLSI) Systems, vol. 26, no. 11, pp. 2572-2576, Nov. 2018. doi: 10.1109/TVLSI.2018.2856362 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and ep parameters
***/
// MAE% = 0.012 %
// MAE = 516096 
// WCE% = 0.048 %
// WCE = 2064384 
// WCRE% = 6300.00 %
// EP% = 98.44 %
// MRE% = 1.06 %
// MSE = 47727.824e7 
// PDK45_PWR = 1.396 mW
// PDK45_AREA = 1932.6 um2
// PDK45_DELAY = 2.57 ns
#include <stdint.h>
#include <stdlib.h>

int32_t mul16s_GV3(int16_t A, int16_t B)
{
  int32_t P, P_;
  uint16_t tmp, C_10_0,C_10_1,C_10_10,C_10_11,C_10_12,C_10_13,C_10_14,C_10_15,C_10_2,C_10_3,C_10_4,C_10_5,C_10_6,C_10_7,C_10_8,C_10_9,C_11_0,C_11_1,C_11_10,C_11_11,C_11_12,C_11_13,C_11_14,C_11_15,C_11_2,C_11_3,C_11_4,C_11_5,C_11_6,C_11_7,C_11_8,C_11_9,C_12_0,C_12_1,C_12_10,C_12_11,C_12_12,C_12_13,C_12_14,C_12_15,C_12_2,C_12_3,C_12_4,C_12_5,C_12_6,C_12_7,C_12_8,C_12_9,C_13_0,C_13_1,C_13_10,C_13_11,C_13_12,C_13_13,C_13_14,C_13_15,C_13_2,C_13_3,C_13_4,C_13_5,C_13_6,C_13_7,C_13_8,C_13_9,C_14_0,C_14_1,C_14_10,C_14_11,C_14_12,C_14_13,C_14_14,C_14_15,C_14_2,C_14_3,C_14_4,C_14_5,C_14_6,C_14_7,C_14_8,C_14_9,C_15_0,C_15_1,C_15_10,C_15_11,C_15_12,C_15_13,C_15_14,C_15_15,C_15_2,C_15_3,C_15_4,C_15_5,C_15_6,C_15_7,C_15_8,C_15_9,C_16_0,C_16_1,C_16_10,C_16_11,C_16_12,C_16_13,C_16_14,C_16_15,C_16_2,C_16_3,C_16_4,C_16_5,C_16_6,C_16_7,C_16_8,C_16_9,C_6_15,C_6_9,C_7_0,C_7_1,C_7_10,C_7_11,C_7_12,C_7_13,C_7_14,C_7_15,C_7_2,C_7_3,C_7_4,C_7_5,C_7_6,C_7_7,C_7_8,C_7_9,C_8_0,C_8_1,C_8_10,C_8_11,C_8_12,C_8_13,C_8_14,C_8_15,C_8_2,C_8_3,C_8_4,C_8_5,C_8_6,C_8_7,C_8_8,C_8_9,C_9_0,C_9_1,C_9_10,C_9_11,C_9_12,C_9_13,C_9_14,C_9_15,C_9_2,C_9_3,C_9_4,C_9_5,C_9_6,C_9_7,C_9_8,C_9_9,S_0_15,S_10_0,S_10_1,S_10_10,S_10_11,S_10_12,S_10_13,S_10_14,S_10_15,S_10_2,S_10_3,S_10_4,S_10_5,S_10_6,S_10_7,S_10_8,S_10_9,S_11_0,S_11_1,S_11_10,S_11_11,S_11_12,S_11_13,S_11_14,S_11_15,S_11_2,S_11_3,S_11_4,S_11_5,S_11_6,S_11_7,S_11_8,S_11_9,S_12_0,S_12_1,S_12_10,S_12_11,S_12_12,S_12_13,S_12_14,S_12_15,S_12_2,S_12_3,S_12_4,S_12_5,S_12_6,S_12_7,S_12_8,S_12_9,S_13_0,S_13_1,S_13_10,S_13_11,S_13_12,S_13_13,S_13_14,S_13_15,S_13_2,S_13_3,S_13_4,S_13_5,S_13_6,S_13_7,S_13_8,S_13_9,S_14_0,S_14_1,S_14_10,S_14_11,S_14_12,S_14_13,S_14_14,S_14_15,S_14_2,S_14_3,S_14_4,S_14_5,S_14_6,S_14_7,S_14_8,S_14_9,S_15_0,S_15_1,S_15_10,S_15_11,S_15_12,S_15_13,S_15_14,S_15_15,S_15_2,S_15_3,S_15_4,S_15_5,S_15_6,S_15_7,S_15_8,S_15_9,S_16_0,S_16_1,S_16_10,S_16_11,S_16_12,S_16_13,S_16_14,S_16_15,S_16_2,S_16_3,S_16_4,S_16_5,S_16_6,S_16_7,S_16_8,S_16_9,S_1_14,S_2_13,S_3_12,S_4_11,S_5_10,S_6_0,S_6_1,S_6_10,S_6_11,S_6_12,S_6_13,S_6_14,S_6_15,S_6_2,S_6_3,S_6_4,S_6_5,S_6_6,S_6_7,S_6_8,S_6_9,S_7_0,S_7_1,S_7_10,S_7_11,S_7_12,S_7_13,S_7_14,S_7_15,S_7_2,S_7_3,S_7_4,S_7_5,S_7_6,S_7_7,S_7_8,S_7_9,S_8_0,S_8_1,S_8_10,S_8_11,S_8_12,S_8_13,S_8_14,S_8_15,S_8_2,S_8_3,S_8_4,S_8_5,S_8_6,S_8_7,S_8_8,S_8_9,S_9_0,S_9_1,S_9_10,S_9_11,S_9_12,S_9_13,S_9_14,S_9_15,S_9_2,S_9_3,S_9_4,S_9_5,S_9_6,S_9_7,S_9_8,S_9_9;
  S_0_15 = 1;
  S_1_14 = 1;
  S_2_13 = 1;
  S_3_12 = 1;
  S_4_11 = 1;
  S_5_10 = 1;
  S_6_0 = (((A>>6)&1) & ((B>>0)&1));
  S_6_1 = (((A>>6)&1) & ((B>>1)&1));
  S_6_2 = (((A>>6)&1) & ((B>>2)&1));
  S_6_3 = (((A>>6)&1) & ((B>>3)&1));
  S_6_4 = (((A>>6)&1) & ((B>>4)&1));
  S_6_5 = (((A>>6)&1) & ((B>>5)&1));
  S_6_6 = (((A>>6)&1) & ((B>>6)&1));
  S_6_7 = (((A>>6)&1) & ((B>>7)&1));
  S_6_8 = (((A>>6)&1) & ((B>>8)&1));
  S_6_9 = S_5_10^(((A>>6)&1) & ((B>>9)&1));
  C_6_9 = S_5_10&(((A>>6)&1) & ((B>>9)&1));
  S_6_10 = (((A>>6)&1) & ((B>>10)&1));
  S_6_11 = (((A>>6)&1) & ((B>>11)&1));
  S_6_12 = (((A>>6)&1) & ((B>>12)&1));
  S_6_13 = (((A>>6)&1) & ((B>>13)&1));
  S_6_14 = (((A>>6)&1) & ((B>>14)&1));
  S_6_15 = 1^(((((A>>6)&1) & ((B>>15)&1)))^1);
  C_6_15 = 1&(((((A>>6)&1) & ((B>>15)&1)))^1);
  S_7_0 = S_6_1^(((A>>7)&1) & ((B>>0)&1));
  C_7_0 = S_6_1&(((A>>7)&1) & ((B>>0)&1));
  S_7_1 = S_6_2^(((A>>7)&1) & ((B>>1)&1));
  C_7_1 = S_6_2&(((A>>7)&1) & ((B>>1)&1));
  S_7_2 = S_6_3^(((A>>7)&1) & ((B>>2)&1));
  C_7_2 = S_6_3&(((A>>7)&1) & ((B>>2)&1));
  S_7_3 = S_6_4^(((A>>7)&1) & ((B>>3)&1));
  C_7_3 = S_6_4&(((A>>7)&1) & ((B>>3)&1));
  S_7_4 = S_6_5^(((A>>7)&1) & ((B>>4)&1));
  C_7_4 = S_6_5&(((A>>7)&1) & ((B>>4)&1));
  S_7_5 = S_6_6^(((A>>7)&1) & ((B>>5)&1));
  C_7_5 = S_6_6&(((A>>7)&1) & ((B>>5)&1));
  S_7_6 = S_6_7^(((A>>7)&1) & ((B>>6)&1));
  C_7_6 = S_6_7&(((A>>7)&1) & ((B>>6)&1));
  S_7_7 = S_6_8^(((A>>7)&1) & ((B>>7)&1));
  C_7_7 = S_6_8&(((A>>7)&1) & ((B>>7)&1));
  S_7_8 = S_6_9^(((A>>7)&1) & ((B>>8)&1));
  C_7_8 = S_6_9&(((A>>7)&1) & ((B>>8)&1));
  tmp = S_6_10^C_6_9;
  S_7_9 = tmp^(((A>>7)&1) & ((B>>9)&1));
  C_7_9 = (tmp&(((A>>7)&1) & ((B>>9)&1)))|(S_6_10&C_6_9);
  S_7_10 = S_6_11^(((A>>7)&1) & ((B>>10)&1));
  C_7_10 = S_6_11&(((A>>7)&1) & ((B>>10)&1));
  S_7_11 = S_6_12^(((A>>7)&1) & ((B>>11)&1));
  C_7_11 = S_6_12&(((A>>7)&1) & ((B>>11)&1));
  S_7_12 = S_6_13^(((A>>7)&1) & ((B>>12)&1));
  C_7_12 = S_6_13&(((A>>7)&1) & ((B>>12)&1));
  S_7_13 = S_6_14^(((A>>7)&1) & ((B>>13)&1));
  C_7_13 = S_6_14&(((A>>7)&1) & ((B>>13)&1));
  S_7_14 = S_6_15^(((A>>7)&1) & ((B>>14)&1));
  C_7_14 = S_6_15&(((A>>7)&1) & ((B>>14)&1));
  S_7_15 = C_6_15^(((((A>>7)&1) & ((B>>15)&1)))^1);
  C_7_15 = C_6_15&(((((A>>7)&1) & ((B>>15)&1)))^1);
  tmp = S_7_1^C_7_0;
  S_8_0 = tmp^(((A>>8)&1) & ((B>>0)&1));
  C_8_0 = (tmp&(((A>>8)&1) & ((B>>0)&1)))|(S_7_1&C_7_0);
  tmp = S_7_2^C_7_1;
  S_8_1 = tmp^(((A>>8)&1) & ((B>>1)&1));
  C_8_1 = (tmp&(((A>>8)&1) & ((B>>1)&1)))|(S_7_2&C_7_1);
  tmp = S_7_3^C_7_2;
  S_8_2 = tmp^(((A>>8)&1) & ((B>>2)&1));
  C_8_2 = (tmp&(((A>>8)&1) & ((B>>2)&1)))|(S_7_3&C_7_2);
  tmp = S_7_4^C_7_3;
  S_8_3 = tmp^(((A>>8)&1) & ((B>>3)&1));
  C_8_3 = (tmp&(((A>>8)&1) & ((B>>3)&1)))|(S_7_4&C_7_3);
  tmp = S_7_5^C_7_4;
  S_8_4 = tmp^(((A>>8)&1) & ((B>>4)&1));
  C_8_4 = (tmp&(((A>>8)&1) & ((B>>4)&1)))|(S_7_5&C_7_4);
  tmp = S_7_6^C_7_5;
  S_8_5 = tmp^(((A>>8)&1) & ((B>>5)&1));
  C_8_5 = (tmp&(((A>>8)&1) & ((B>>5)&1)))|(S_7_6&C_7_5);
  tmp = S_7_7^C_7_6;
  S_8_6 = tmp^(((A>>8)&1) & ((B>>6)&1));
  C_8_6 = (tmp&(((A>>8)&1) & ((B>>6)&1)))|(S_7_7&C_7_6);
  tmp = S_7_8^C_7_7;
  S_8_7 = tmp^(((A>>8)&1) & ((B>>7)&1));
  C_8_7 = (tmp&(((A>>8)&1) & ((B>>7)&1)))|(S_7_8&C_7_7);
  tmp = S_7_9^C_7_8;
  S_8_8 = tmp^(((A>>8)&1) & ((B>>8)&1));
  C_8_8 = (tmp&(((A>>8)&1) & ((B>>8)&1)))|(S_7_9&C_7_8);
  tmp = S_7_10^C_7_9;
  S_8_9 = tmp^(((A>>8)&1) & ((B>>9)&1));
  C_8_9 = (tmp&(((A>>8)&1) & ((B>>9)&1)))|(S_7_10&C_7_9);
  tmp = S_7_11^C_7_10;
  S_8_10 = tmp^(((A>>8)&1) & ((B>>10)&1));
  C_8_10 = (tmp&(((A>>8)&1) & ((B>>10)&1)))|(S_7_11&C_7_10);
  tmp = S_7_12^C_7_11;
  S_8_11 = tmp^(((A>>8)&1) & ((B>>11)&1));
  C_8_11 = (tmp&(((A>>8)&1) & ((B>>11)&1)))|(S_7_12&C_7_11);
  tmp = S_7_13^C_7_12;
  S_8_12 = tmp^(((A>>8)&1) & ((B>>12)&1));
  C_8_12 = (tmp&(((A>>8)&1) & ((B>>12)&1)))|(S_7_13&C_7_12);
  tmp = S_7_14^C_7_13;
  S_8_13 = tmp^(((A>>8)&1) & ((B>>13)&1));
  C_8_13 = (tmp&(((A>>8)&1) & ((B>>13)&1)))|(S_7_14&C_7_13);
  tmp = S_7_15^C_7_14;
  S_8_14 = tmp^(((A>>8)&1) & ((B>>14)&1));
  C_8_14 = (tmp&(((A>>8)&1) & ((B>>14)&1)))|(S_7_15&C_7_14);
  S_8_15 = C_7_15^(((((A>>8)&1) & ((B>>15)&1)))^1);
  C_8_15 = C_7_15&(((((A>>8)&1) & ((B>>15)&1)))^1);
  tmp = S_8_1^C_8_0;
  S_9_0 = tmp^(((A>>9)&1) & ((B>>0)&1));
  C_9_0 = (tmp&(((A>>9)&1) & ((B>>0)&1)))|(S_8_1&C_8_0);
  tmp = S_8_2^C_8_1;
  S_9_1 = tmp^(((A>>9)&1) & ((B>>1)&1));
  C_9_1 = (tmp&(((A>>9)&1) & ((B>>1)&1)))|(S_8_2&C_8_1);
  tmp = S_8_3^C_8_2;
  S_9_2 = tmp^(((A>>9)&1) & ((B>>2)&1));
  C_9_2 = (tmp&(((A>>9)&1) & ((B>>2)&1)))|(S_8_3&C_8_2);
  tmp = S_8_4^C_8_3;
  S_9_3 = tmp^(((A>>9)&1) & ((B>>3)&1));
  C_9_3 = (tmp&(((A>>9)&1) & ((B>>3)&1)))|(S_8_4&C_8_3);
  tmp = S_8_5^C_8_4;
  S_9_4 = tmp^(((A>>9)&1) & ((B>>4)&1));
  C_9_4 = (tmp&(((A>>9)&1) & ((B>>4)&1)))|(S_8_5&C_8_4);
  tmp = S_8_6^C_8_5;
  S_9_5 = tmp^(((A>>9)&1) & ((B>>5)&1));
  C_9_5 = (tmp&(((A>>9)&1) & ((B>>5)&1)))|(S_8_6&C_8_5);
  tmp = S_8_7^C_8_6;
  S_9_6 = tmp^(((A>>9)&1) & ((B>>6)&1));
  C_9_6 = (tmp&(((A>>9)&1) & ((B>>6)&1)))|(S_8_7&C_8_6);
  tmp = S_8_8^C_8_7;
  S_9_7 = tmp^(((A>>9)&1) & ((B>>7)&1));
  C_9_7 = (tmp&(((A>>9)&1) & ((B>>7)&1)))|(S_8_8&C_8_7);
  tmp = S_8_9^C_8_8;
  S_9_8 = tmp^(((A>>9)&1) & ((B>>8)&1));
  C_9_8 = (tmp&(((A>>9)&1) & ((B>>8)&1)))|(S_8_9&C_8_8);
  tmp = S_8_10^C_8_9;
  S_9_9 = tmp^(((A>>9)&1) & ((B>>9)&1));
  C_9_9 = (tmp&(((A>>9)&1) & ((B>>9)&1)))|(S_8_10&C_8_9);
  tmp = S_8_11^C_8_10;
  S_9_10 = tmp^(((A>>9)&1) & ((B>>10)&1));
  C_9_10 = (tmp&(((A>>9)&1) & ((B>>10)&1)))|(S_8_11&C_8_10);
  tmp = S_8_12^C_8_11;
  S_9_11 = tmp^(((A>>9)&1) & ((B>>11)&1));
  C_9_11 = (tmp&(((A>>9)&1) & ((B>>11)&1)))|(S_8_12&C_8_11);
  tmp = S_8_13^C_8_12;
  S_9_12 = tmp^(((A>>9)&1) & ((B>>12)&1));
  C_9_12 = (tmp&(((A>>9)&1) & ((B>>12)&1)))|(S_8_13&C_8_12);
  tmp = S_8_14^C_8_13;
  S_9_13 = tmp^(((A>>9)&1) & ((B>>13)&1));
  C_9_13 = (tmp&(((A>>9)&1) & ((B>>13)&1)))|(S_8_14&C_8_13);
  tmp = S_8_15^C_8_14;
  S_9_14 = tmp^(((A>>9)&1) & ((B>>14)&1));
  C_9_14 = (tmp&(((A>>9)&1) & ((B>>14)&1)))|(S_8_15&C_8_14);
  S_9_15 = C_8_15^(((((A>>9)&1) & ((B>>15)&1)))^1);
  C_9_15 = C_8_15&(((((A>>9)&1) & ((B>>15)&1)))^1);
  tmp = S_9_1^C_9_0;
  S_10_0 = tmp^(((A>>10)&1) & ((B>>0)&1));
  C_10_0 = (tmp&(((A>>10)&1) & ((B>>0)&1)))|(S_9_1&C_9_0);
  tmp = S_9_2^C_9_1;
  S_10_1 = tmp^(((A>>10)&1) & ((B>>1)&1));
  C_10_1 = (tmp&(((A>>10)&1) & ((B>>1)&1)))|(S_9_2&C_9_1);
  tmp = S_9_3^C_9_2;
  S_10_2 = tmp^(((A>>10)&1) & ((B>>2)&1));
  C_10_2 = (tmp&(((A>>10)&1) & ((B>>2)&1)))|(S_9_3&C_9_2);
  tmp = S_9_4^C_9_3;
  S_10_3 = tmp^(((A>>10)&1) & ((B>>3)&1));
  C_10_3 = (tmp&(((A>>10)&1) & ((B>>3)&1)))|(S_9_4&C_9_3);
  tmp = S_9_5^C_9_4;
  S_10_4 = tmp^(((A>>10)&1) & ((B>>4)&1));
  C_10_4 = (tmp&(((A>>10)&1) & ((B>>4)&1)))|(S_9_5&C_9_4);
  tmp = S_9_6^C_9_5;
  S_10_5 = tmp^(((A>>10)&1) & ((B>>5)&1));
  C_10_5 = (tmp&(((A>>10)&1) & ((B>>5)&1)))|(S_9_6&C_9_5);
  tmp = S_9_7^C_9_6;
  S_10_6 = tmp^(((A>>10)&1) & ((B>>6)&1));
  C_10_6 = (tmp&(((A>>10)&1) & ((B>>6)&1)))|(S_9_7&C_9_6);
  tmp = S_9_8^C_9_7;
  S_10_7 = tmp^(((A>>10)&1) & ((B>>7)&1));
  C_10_7 = (tmp&(((A>>10)&1) & ((B>>7)&1)))|(S_9_8&C_9_7);
  tmp = S_9_9^C_9_8;
  S_10_8 = tmp^(((A>>10)&1) & ((B>>8)&1));
  C_10_8 = (tmp&(((A>>10)&1) & ((B>>8)&1)))|(S_9_9&C_9_8);
  tmp = S_9_10^C_9_9;
  S_10_9 = tmp^(((A>>10)&1) & ((B>>9)&1));
  C_10_9 = (tmp&(((A>>10)&1) & ((B>>9)&1)))|(S_9_10&C_9_9);
  tmp = S_9_11^C_9_10;
  S_10_10 = tmp^(((A>>10)&1) & ((B>>10)&1));
  C_10_10 = (tmp&(((A>>10)&1) & ((B>>10)&1)))|(S_9_11&C_9_10);
  tmp = S_9_12^C_9_11;
  S_10_11 = tmp^(((A>>10)&1) & ((B>>11)&1));
  C_10_11 = (tmp&(((A>>10)&1) & ((B>>11)&1)))|(S_9_12&C_9_11);
  tmp = S_9_13^C_9_12;
  S_10_12 = tmp^(((A>>10)&1) & ((B>>12)&1));
  C_10_12 = (tmp&(((A>>10)&1) & ((B>>12)&1)))|(S_9_13&C_9_12);
  tmp = S_9_14^C_9_13;
  S_10_13 = tmp^(((A>>10)&1) & ((B>>13)&1));
  C_10_13 = (tmp&(((A>>10)&1) & ((B>>13)&1)))|(S_9_14&C_9_13);
  tmp = S_9_15^C_9_14;
  S_10_14 = tmp^(((A>>10)&1) & ((B>>14)&1));
  C_10_14 = (tmp&(((A>>10)&1) & ((B>>14)&1)))|(S_9_15&C_9_14);
  S_10_15 = C_9_15^(((((A>>10)&1) & ((B>>15)&1)))^1);
  C_10_15 = C_9_15&(((((A>>10)&1) & ((B>>15)&1)))^1);
  tmp = S_10_1^C_10_0;
  S_11_0 = tmp^(((A>>11)&1) & ((B>>0)&1));
  C_11_0 = (tmp&(((A>>11)&1) & ((B>>0)&1)))|(S_10_1&C_10_0);
  tmp = S_10_2^C_10_1;
  S_11_1 = tmp^(((A>>11)&1) & ((B>>1)&1));
  C_11_1 = (tmp&(((A>>11)&1) & ((B>>1)&1)))|(S_10_2&C_10_1);
  tmp = S_10_3^C_10_2;
  S_11_2 = tmp^(((A>>11)&1) & ((B>>2)&1));
  C_11_2 = (tmp&(((A>>11)&1) & ((B>>2)&1)))|(S_10_3&C_10_2);
  tmp = S_10_4^C_10_3;
  S_11_3 = tmp^(((A>>11)&1) & ((B>>3)&1));
  C_11_3 = (tmp&(((A>>11)&1) & ((B>>3)&1)))|(S_10_4&C_10_3);
  tmp = S_10_5^C_10_4;
  S_11_4 = tmp^(((A>>11)&1) & ((B>>4)&1));
  C_11_4 = (tmp&(((A>>11)&1) & ((B>>4)&1)))|(S_10_5&C_10_4);
  tmp = S_10_6^C_10_5;
  S_11_5 = tmp^(((A>>11)&1) & ((B>>5)&1));
  C_11_5 = (tmp&(((A>>11)&1) & ((B>>5)&1)))|(S_10_6&C_10_5);
  tmp = S_10_7^C_10_6;
  S_11_6 = tmp^(((A>>11)&1) & ((B>>6)&1));
  C_11_6 = (tmp&(((A>>11)&1) & ((B>>6)&1)))|(S_10_7&C_10_6);
  tmp = S_10_8^C_10_7;
  S_11_7 = tmp^(((A>>11)&1) & ((B>>7)&1));
  C_11_7 = (tmp&(((A>>11)&1) & ((B>>7)&1)))|(S_10_8&C_10_7);
  tmp = S_10_9^C_10_8;
  S_11_8 = tmp^(((A>>11)&1) & ((B>>8)&1));
  C_11_8 = (tmp&(((A>>11)&1) & ((B>>8)&1)))|(S_10_9&C_10_8);
  tmp = S_10_10^C_10_9;
  S_11_9 = tmp^(((A>>11)&1) & ((B>>9)&1));
  C_11_9 = (tmp&(((A>>11)&1) & ((B>>9)&1)))|(S_10_10&C_10_9);
  tmp = S_10_11^C_10_10;
  S_11_10 = tmp^(((A>>11)&1) & ((B>>10)&1));
  C_11_10 = (tmp&(((A>>11)&1) & ((B>>10)&1)))|(S_10_11&C_10_10);
  tmp = S_10_12^C_10_11;
  S_11_11 = tmp^(((A>>11)&1) & ((B>>11)&1));
  C_11_11 = (tmp&(((A>>11)&1) & ((B>>11)&1)))|(S_10_12&C_10_11);
  tmp = S_10_13^C_10_12;
  S_11_12 = tmp^(((A>>11)&1) & ((B>>12)&1));
  C_11_12 = (tmp&(((A>>11)&1) & ((B>>12)&1)))|(S_10_13&C_10_12);
  tmp = S_10_14^C_10_13;
  S_11_13 = tmp^(((A>>11)&1) & ((B>>13)&1));
  C_11_13 = (tmp&(((A>>11)&1) & ((B>>13)&1)))|(S_10_14&C_10_13);
  tmp = S_10_15^C_10_14;
  S_11_14 = tmp^(((A>>11)&1) & ((B>>14)&1));
  C_11_14 = (tmp&(((A>>11)&1) & ((B>>14)&1)))|(S_10_15&C_10_14);
  S_11_15 = C_10_15^(((((A>>11)&1) & ((B>>15)&1)))^1);
  C_11_15 = C_10_15&(((((A>>11)&1) & ((B>>15)&1)))^1);
  tmp = S_11_1^C_11_0;
  S_12_0 = tmp^(((A>>12)&1) & ((B>>0)&1));
  C_12_0 = (tmp&(((A>>12)&1) & ((B>>0)&1)))|(S_11_1&C_11_0);
  tmp = S_11_2^C_11_1;
  S_12_1 = tmp^(((A>>12)&1) & ((B>>1)&1));
  C_12_1 = (tmp&(((A>>12)&1) & ((B>>1)&1)))|(S_11_2&C_11_1);
  tmp = S_11_3^C_11_2;
  S_12_2 = tmp^(((A>>12)&1) & ((B>>2)&1));
  C_12_2 = (tmp&(((A>>12)&1) & ((B>>2)&1)))|(S_11_3&C_11_2);
  tmp = S_11_4^C_11_3;
  S_12_3 = tmp^(((A>>12)&1) & ((B>>3)&1));
  C_12_3 = (tmp&(((A>>12)&1) & ((B>>3)&1)))|(S_11_4&C_11_3);
  tmp = S_11_5^C_11_4;
  S_12_4 = tmp^(((A>>12)&1) & ((B>>4)&1));
  C_12_4 = (tmp&(((A>>12)&1) & ((B>>4)&1)))|(S_11_5&C_11_4);
  tmp = S_11_6^C_11_5;
  S_12_5 = tmp^(((A>>12)&1) & ((B>>5)&1));
  C_12_5 = (tmp&(((A>>12)&1) & ((B>>5)&1)))|(S_11_6&C_11_5);
  tmp = S_11_7^C_11_6;
  S_12_6 = tmp^(((A>>12)&1) & ((B>>6)&1));
  C_12_6 = (tmp&(((A>>12)&1) & ((B>>6)&1)))|(S_11_7&C_11_6);
  tmp = S_11_8^C_11_7;
  S_12_7 = tmp^(((A>>12)&1) & ((B>>7)&1));
  C_12_7 = (tmp&(((A>>12)&1) & ((B>>7)&1)))|(S_11_8&C_11_7);
  tmp = S_11_9^C_11_8;
  S_12_8 = tmp^(((A>>12)&1) & ((B>>8)&1));
  C_12_8 = (tmp&(((A>>12)&1) & ((B>>8)&1)))|(S_11_9&C_11_8);
  tmp = S_11_10^C_11_9;
  S_12_9 = tmp^(((A>>12)&1) & ((B>>9)&1));
  C_12_9 = (tmp&(((A>>12)&1) & ((B>>9)&1)))|(S_11_10&C_11_9);
  tmp = S_11_11^C_11_10;
  S_12_10 = tmp^(((A>>12)&1) & ((B>>10)&1));
  C_12_10 = (tmp&(((A>>12)&1) & ((B>>10)&1)))|(S_11_11&C_11_10);
  tmp = S_11_12^C_11_11;
  S_12_11 = tmp^(((A>>12)&1) & ((B>>11)&1));
  C_12_11 = (tmp&(((A>>12)&1) & ((B>>11)&1)))|(S_11_12&C_11_11);
  tmp = S_11_13^C_11_12;
  S_12_12 = tmp^(((A>>12)&1) & ((B>>12)&1));
  C_12_12 = (tmp&(((A>>12)&1) & ((B>>12)&1)))|(S_11_13&C_11_12);
  tmp = S_11_14^C_11_13;
  S_12_13 = tmp^(((A>>12)&1) & ((B>>13)&1));
  C_12_13 = (tmp&(((A>>12)&1) & ((B>>13)&1)))|(S_11_14&C_11_13);
  tmp = S_11_15^C_11_14;
  S_12_14 = tmp^(((A>>12)&1) & ((B>>14)&1));
  C_12_14 = (tmp&(((A>>12)&1) & ((B>>14)&1)))|(S_11_15&C_11_14);
  S_12_15 = C_11_15^(((((A>>12)&1) & ((B>>15)&1)))^1);
  C_12_15 = C_11_15&(((((A>>12)&1) & ((B>>15)&1)))^1);
  tmp = S_12_1^C_12_0;
  S_13_0 = tmp^(((A>>13)&1) & ((B>>0)&1));
  C_13_0 = (tmp&(((A>>13)&1) & ((B>>0)&1)))|(S_12_1&C_12_0);
  tmp = S_12_2^C_12_1;
  S_13_1 = tmp^(((A>>13)&1) & ((B>>1)&1));
  C_13_1 = (tmp&(((A>>13)&1) & ((B>>1)&1)))|(S_12_2&C_12_1);
  tmp = S_12_3^C_12_2;
  S_13_2 = tmp^(((A>>13)&1) & ((B>>2)&1));
  C_13_2 = (tmp&(((A>>13)&1) & ((B>>2)&1)))|(S_12_3&C_12_2);
  tmp = S_12_4^C_12_3;
  S_13_3 = tmp^(((A>>13)&1) & ((B>>3)&1));
  C_13_3 = (tmp&(((A>>13)&1) & ((B>>3)&1)))|(S_12_4&C_12_3);
  tmp = S_12_5^C_12_4;
  S_13_4 = tmp^(((A>>13)&1) & ((B>>4)&1));
  C_13_4 = (tmp&(((A>>13)&1) & ((B>>4)&1)))|(S_12_5&C_12_4);
  tmp = S_12_6^C_12_5;
  S_13_5 = tmp^(((A>>13)&1) & ((B>>5)&1));
  C_13_5 = (tmp&(((A>>13)&1) & ((B>>5)&1)))|(S_12_6&C_12_5);
  tmp = S_12_7^C_12_6;
  S_13_6 = tmp^(((A>>13)&1) & ((B>>6)&1));
  C_13_6 = (tmp&(((A>>13)&1) & ((B>>6)&1)))|(S_12_7&C_12_6);
  tmp = S_12_8^C_12_7;
  S_13_7 = tmp^(((A>>13)&1) & ((B>>7)&1));
  C_13_7 = (tmp&(((A>>13)&1) & ((B>>7)&1)))|(S_12_8&C_12_7);
  tmp = S_12_9^C_12_8;
  S_13_8 = tmp^(((A>>13)&1) & ((B>>8)&1));
  C_13_8 = (tmp&(((A>>13)&1) & ((B>>8)&1)))|(S_12_9&C_12_8);
  tmp = S_12_10^C_12_9;
  S_13_9 = tmp^(((A>>13)&1) & ((B>>9)&1));
  C_13_9 = (tmp&(((A>>13)&1) & ((B>>9)&1)))|(S_12_10&C_12_9);
  tmp = S_12_11^C_12_10;
  S_13_10 = tmp^(((A>>13)&1) & ((B>>10)&1));
  C_13_10 = (tmp&(((A>>13)&1) & ((B>>10)&1)))|(S_12_11&C_12_10);
  tmp = S_12_12^C_12_11;
  S_13_11 = tmp^(((A>>13)&1) & ((B>>11)&1));
  C_13_11 = (tmp&(((A>>13)&1) & ((B>>11)&1)))|(S_12_12&C_12_11);
  tmp = S_12_13^C_12_12;
  S_13_12 = tmp^(((A>>13)&1) & ((B>>12)&1));
  C_13_12 = (tmp&(((A>>13)&1) & ((B>>12)&1)))|(S_12_13&C_12_12);
  tmp = S_12_14^C_12_13;
  S_13_13 = tmp^(((A>>13)&1) & ((B>>13)&1));
  C_13_13 = (tmp&(((A>>13)&1) & ((B>>13)&1)))|(S_12_14&C_12_13);
  tmp = S_12_15^C_12_14;
  S_13_14 = tmp^(((A>>13)&1) & ((B>>14)&1));
  C_13_14 = (tmp&(((A>>13)&1) & ((B>>14)&1)))|(S_12_15&C_12_14);
  S_13_15 = C_12_15^(((((A>>13)&1) & ((B>>15)&1)))^1);
  C_13_15 = C_12_15&(((((A>>13)&1) & ((B>>15)&1)))^1);
  tmp = S_13_1^C_13_0;
  S_14_0 = tmp^(((A>>14)&1) & ((B>>0)&1));
  C_14_0 = (tmp&(((A>>14)&1) & ((B>>0)&1)))|(S_13_1&C_13_0);
  tmp = S_13_2^C_13_1;
  S_14_1 = tmp^(((A>>14)&1) & ((B>>1)&1));
  C_14_1 = (tmp&(((A>>14)&1) & ((B>>1)&1)))|(S_13_2&C_13_1);
  tmp = S_13_3^C_13_2;
  S_14_2 = tmp^(((A>>14)&1) & ((B>>2)&1));
  C_14_2 = (tmp&(((A>>14)&1) & ((B>>2)&1)))|(S_13_3&C_13_2);
  tmp = S_13_4^C_13_3;
  S_14_3 = tmp^(((A>>14)&1) & ((B>>3)&1));
  C_14_3 = (tmp&(((A>>14)&1) & ((B>>3)&1)))|(S_13_4&C_13_3);
  tmp = S_13_5^C_13_4;
  S_14_4 = tmp^(((A>>14)&1) & ((B>>4)&1));
  C_14_4 = (tmp&(((A>>14)&1) & ((B>>4)&1)))|(S_13_5&C_13_4);
  tmp = S_13_6^C_13_5;
  S_14_5 = tmp^(((A>>14)&1) & ((B>>5)&1));
  C_14_5 = (tmp&(((A>>14)&1) & ((B>>5)&1)))|(S_13_6&C_13_5);
  tmp = S_13_7^C_13_6;
  S_14_6 = tmp^(((A>>14)&1) & ((B>>6)&1));
  C_14_6 = (tmp&(((A>>14)&1) & ((B>>6)&1)))|(S_13_7&C_13_6);
  tmp = S_13_8^C_13_7;
  S_14_7 = tmp^(((A>>14)&1) & ((B>>7)&1));
  C_14_7 = (tmp&(((A>>14)&1) & ((B>>7)&1)))|(S_13_8&C_13_7);
  tmp = S_13_9^C_13_8;
  S_14_8 = tmp^(((A>>14)&1) & ((B>>8)&1));
  C_14_8 = (tmp&(((A>>14)&1) & ((B>>8)&1)))|(S_13_9&C_13_8);
  tmp = S_13_10^C_13_9;
  S_14_9 = tmp^(((A>>14)&1) & ((B>>9)&1));
  C_14_9 = (tmp&(((A>>14)&1) & ((B>>9)&1)))|(S_13_10&C_13_9);
  tmp = S_13_11^C_13_10;
  S_14_10 = tmp^(((A>>14)&1) & ((B>>10)&1));
  C_14_10 = (tmp&(((A>>14)&1) & ((B>>10)&1)))|(S_13_11&C_13_10);
  tmp = S_13_12^C_13_11;
  S_14_11 = tmp^(((A>>14)&1) & ((B>>11)&1));
  C_14_11 = (tmp&(((A>>14)&1) & ((B>>11)&1)))|(S_13_12&C_13_11);
  tmp = S_13_13^C_13_12;
  S_14_12 = tmp^(((A>>14)&1) & ((B>>12)&1));
  C_14_12 = (tmp&(((A>>14)&1) & ((B>>12)&1)))|(S_13_13&C_13_12);
  tmp = S_13_14^C_13_13;
  S_14_13 = tmp^(((A>>14)&1) & ((B>>13)&1));
  C_14_13 = (tmp&(((A>>14)&1) & ((B>>13)&1)))|(S_13_14&C_13_13);
  tmp = S_13_15^C_13_14;
  S_14_14 = tmp^(((A>>14)&1) & ((B>>14)&1));
  C_14_14 = (tmp&(((A>>14)&1) & ((B>>14)&1)))|(S_13_15&C_13_14);
  S_14_15 = C_13_15^(((((A>>14)&1) & ((B>>15)&1)))^1);
  C_14_15 = C_13_15&(((((A>>14)&1) & ((B>>15)&1)))^1);
  tmp = S_14_1^C_14_0;
  S_15_0 = tmp^(((((A>>15)&1) & ((B>>0)&1)))^1);
  C_15_0 = (tmp&(((((A>>15)&1) & ((B>>0)&1)))^1))|(S_14_1&C_14_0);
  tmp = S_14_2^C_14_1;
  S_15_1 = tmp^(((((A>>15)&1) & ((B>>1)&1)))^1);
  C_15_1 = (tmp&(((((A>>15)&1) & ((B>>1)&1)))^1))|(S_14_2&C_14_1);
  tmp = S_14_3^C_14_2;
  S_15_2 = tmp^(((((A>>15)&1) & ((B>>2)&1)))^1);
  C_15_2 = (tmp&(((((A>>15)&1) & ((B>>2)&1)))^1))|(S_14_3&C_14_2);
  tmp = S_14_4^C_14_3;
  S_15_3 = tmp^(((((A>>15)&1) & ((B>>3)&1)))^1);
  C_15_3 = (tmp&(((((A>>15)&1) & ((B>>3)&1)))^1))|(S_14_4&C_14_3);
  tmp = S_14_5^C_14_4;
  S_15_4 = tmp^(((((A>>15)&1) & ((B>>4)&1)))^1);
  C_15_4 = (tmp&(((((A>>15)&1) & ((B>>4)&1)))^1))|(S_14_5&C_14_4);
  tmp = S_14_6^C_14_5;
  S_15_5 = tmp^(((((A>>15)&1) & ((B>>5)&1)))^1);
  C_15_5 = (tmp&(((((A>>15)&1) & ((B>>5)&1)))^1))|(S_14_6&C_14_5);
  tmp = S_14_7^C_14_6;
  S_15_6 = tmp^(((((A>>15)&1) & ((B>>6)&1)))^1);
  C_15_6 = (tmp&(((((A>>15)&1) & ((B>>6)&1)))^1))|(S_14_7&C_14_6);
  tmp = S_14_8^C_14_7;
  S_15_7 = tmp^(((((A>>15)&1) & ((B>>7)&1)))^1);
  C_15_7 = (tmp&(((((A>>15)&1) & ((B>>7)&1)))^1))|(S_14_8&C_14_7);
  tmp = S_14_9^C_14_8;
  S_15_8 = tmp^(((((A>>15)&1) & ((B>>8)&1)))^1);
  C_15_8 = (tmp&(((((A>>15)&1) & ((B>>8)&1)))^1))|(S_14_9&C_14_8);
  tmp = S_14_10^C_14_9;
  S_15_9 = tmp^(((((A>>15)&1) & ((B>>9)&1)))^1);
  C_15_9 = (tmp&(((((A>>15)&1) & ((B>>9)&1)))^1))|(S_14_10&C_14_9);
  tmp = S_14_11^C_14_10;
  S_15_10 = tmp^(((((A>>15)&1) & ((B>>10)&1)))^1);
  C_15_10 = (tmp&(((((A>>15)&1) & ((B>>10)&1)))^1))|(S_14_11&C_14_10);
  tmp = S_14_12^C_14_11;
  S_15_11 = tmp^(((((A>>15)&1) & ((B>>11)&1)))^1);
  C_15_11 = (tmp&(((((A>>15)&1) & ((B>>11)&1)))^1))|(S_14_12&C_14_11);
  tmp = S_14_13^C_14_12;
  S_15_12 = tmp^(((((A>>15)&1) & ((B>>12)&1)))^1);
  C_15_12 = (tmp&(((((A>>15)&1) & ((B>>12)&1)))^1))|(S_14_13&C_14_12);
  tmp = S_14_14^C_14_13;
  S_15_13 = tmp^(((((A>>15)&1) & ((B>>13)&1)))^1);
  C_15_13 = (tmp&(((((A>>15)&1) & ((B>>13)&1)))^1))|(S_14_14&C_14_13);
  tmp = S_14_15^C_14_14;
  S_15_14 = tmp^(((((A>>15)&1) & ((B>>14)&1)))^1);
  C_15_14 = (tmp&(((((A>>15)&1) & ((B>>14)&1)))^1))|(S_14_15&C_14_14);
  S_15_15 = C_14_15^(((A>>15)&1) & ((B>>15)&1));
  C_15_15 = C_14_15&(((A>>15)&1) & ((B>>15)&1));
  S_16_0 = S_15_1^C_15_0;
  C_16_0 = S_15_1&C_15_0;
  tmp = S_15_2^C_16_0;
  S_16_1 = tmp^C_15_1;
  C_16_1 = (tmp&C_15_1)|(S_15_2&C_16_0);
  tmp = S_15_3^C_16_1;
  S_16_2 = tmp^C_15_2;
  C_16_2 = (tmp&C_15_2)|(S_15_3&C_16_1);
  tmp = S_15_4^C_16_2;
  S_16_3 = tmp^C_15_3;
  C_16_3 = (tmp&C_15_3)|(S_15_4&C_16_2);
  tmp = S_15_5^C_16_3;
  S_16_4 = tmp^C_15_4;
  C_16_4 = (tmp&C_15_4)|(S_15_5&C_16_3);
  tmp = S_15_6^C_16_4;
  S_16_5 = tmp^C_15_5;
  C_16_5 = (tmp&C_15_5)|(S_15_6&C_16_4);
  tmp = S_15_7^C_16_5;
  S_16_6 = tmp^C_15_6;
  C_16_6 = (tmp&C_15_6)|(S_15_7&C_16_5);
  tmp = S_15_8^C_16_6;
  S_16_7 = tmp^C_15_7;
  C_16_7 = (tmp&C_15_7)|(S_15_8&C_16_6);
  tmp = S_15_9^C_16_7;
  S_16_8 = tmp^C_15_8;
  C_16_8 = (tmp&C_15_8)|(S_15_9&C_16_7);
  tmp = S_15_10^C_16_8;
  S_16_9 = tmp^C_15_9;
  C_16_9 = (tmp&C_15_9)|(S_15_10&C_16_8);
  tmp = S_15_11^C_16_9;
  S_16_10 = tmp^C_15_10;
  C_16_10 = (tmp&C_15_10)|(S_15_11&C_16_9);
  tmp = S_15_12^C_16_10;
  S_16_11 = tmp^C_15_11;
  C_16_11 = (tmp&C_15_11)|(S_15_12&C_16_10);
  tmp = S_15_13^C_16_11;
  S_16_12 = tmp^C_15_12;
  C_16_12 = (tmp&C_15_12)|(S_15_13&C_16_11);
  tmp = S_15_14^C_16_12;
  S_16_13 = tmp^C_15_13;
  C_16_13 = (tmp&C_15_13)|(S_15_14&C_16_12);
  tmp = S_15_15^C_16_13;
  S_16_14 = tmp^C_15_14;
  C_16_14 = (tmp&C_15_14)|(S_15_15&C_16_13);
  tmp = 1^C_16_14;
  S_16_15 = tmp^C_15_15;
  C_16_15 = (tmp&C_15_15)|(1&C_16_14);
  P = 0;
  P |= (S_6_0 & 1) << 6;
  P |= (S_7_0 & 1) << 7;
  P |= (S_8_0 & 1) << 8;
  P |= (S_9_0 & 1) << 9;
  P |= (S_10_0 & 1) << 10;
  P |= (S_11_0 & 1) << 11;
  P |= (S_12_0 & 1) << 12;
  P |= (S_13_0 & 1) << 13;
  P |= (S_14_0 & 1) << 14;
  P |= (S_15_0 & 1) << 15;
  P |= (S_16_0 & 1) << 16;
  P |= (S_16_1 & 1) << 17;
  P |= (S_16_2 & 1) << 18;
  P |= (S_16_3 & 1) << 19;
  P |= (S_16_4 & 1) << 20;
  P |= (S_16_5 & 1) << 21;
  P |= (S_16_6 & 1) << 22;
  P |= (S_16_7 & 1) << 23;
  P |= (S_16_8 & 1) << 24;
  P |= (S_16_9 & 1) << 25;
  P |= (S_16_10 & 1) << 26;
  P |= (S_16_11 & 1) << 27;
  P |= (S_16_12 & 1) << 28;
  P |= (S_16_13 & 1) << 29;
  P |= (S_16_14 & 1) << 30;
  P |= (S_16_15 & 1) << 31;
  return P;
}
