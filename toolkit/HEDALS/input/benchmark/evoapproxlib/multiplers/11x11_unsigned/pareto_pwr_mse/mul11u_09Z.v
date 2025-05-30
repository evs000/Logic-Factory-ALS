/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, S. S. Sarwar, L. Sekanina, Z. Vasicek and K. Roy, "Design of power-efficient approximate multipliers for approximate artificial neural networks," 2016 IEEE/ACM International Conference on Computer-Aided Design (ICCAD), Austin, TX, 2016, pp. 1-7. doi: 10.1145/2966986.2967021 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mse parameters
***/
// MAE% = 1.18 %
// MAE = 49343 
// WCE% = 6.03 %
// WCE = 252964 
// WCRE% = 3051.52 %
// EP% = 99.90 %
// MRE% = 19.95 %
// MSE = 37290.89e5 
// PDK45_PWR = 0.236 mW
// PDK45_AREA = 524.2 um2
// PDK45_DELAY = 1.13 ns


module mul11u_09Z(A, B, O);
  input [10:0] A, B;
  output [21:0] O;
  wire [10:0] A, B;
  wire [21:0] O;
  wire sig_75, sig_76, sig_86, sig_87, sig_95, sig_96;
  wire sig_97, sig_98, sig_106, sig_107, sig_108, sig_109;
  wire sig_116, sig_117, sig_118, sig_119, sig_120, sig_127;
  wire sig_128, sig_129, sig_130, sig_131, sig_137, sig_138;
  wire sig_139, sig_140, sig_141, sig_142, sig_235, sig_238;
  wire sig_239, sig_240, sig_269, sig_272, sig_273, sig_274;
  wire sig_275, sig_277, sig_278, sig_279, sig_280, sig_282;
  wire sig_283, sig_284, sig_285, sig_286, sig_287, sig_288;
  wire sig_289, sig_376, sig_377, sig_378, sig_379, sig_380;
  wire sig_381, sig_382, sig_384, sig_385, sig_386, sig_387;
  wire sig_388, sig_389, sig_390, sig_391, sig_420, sig_441;
  wire sig_442, sig_444, sig_473, sig_474, sig_475, sig_476;
  wire sig_477, sig_478, sig_479, sig_480, sig_481, sig_482;
  wire sig_483, sig_484, sig_485, sig_486, sig_487, sig_488;
  wire sig_489, sig_490, sig_491, sig_493, sig_494, sig_495;
  wire sig_496, sig_538, sig_539, sig_540, sig_542, sig_543;
  wire sig_544, sig_545, sig_546, sig_547, sig_548, sig_549;
  wire sig_550, sig_551, sig_552, sig_553, sig_554, sig_555;
  wire sig_556, sig_575, sig_591, sig_592, sig_593, sig_595;
  wire sig_596, sig_597, sig_598, sig_599, sig_600, sig_601;
  wire sig_604, sig_605, sig_606, sig_607, sig_608, sig_609;
  wire sig_610, sig_611, sig_612, sig_613, sig_615, sig_617;
  wire sig_618, sig_621, sig_623, sig_625, sig_652, sig_655;
  wire sig_691, sig_692, sig_693, sig_694, sig_707, sig_708;
  wire sig_709, sig_711, sig_748, sig_749, sig_750, sig_751;
  wire sig_752, sig_753, sig_754, sig_755, sig_756, sig_757;
  wire sig_758, sig_759, sig_760, sig_761, sig_762, sig_763;
  wire sig_764, sig_765, sig_766, sig_767, sig_768, sig_769;
  wire sig_770, sig_771, sig_772, sig_773, sig_774, sig_775;
  wire sig_776, sig_777, sig_778, sig_779, sig_780, sig_781;
  wire sig_782, sig_783, sig_784, sig_785, sig_786, sig_787;
  wire sig_788, sig_789, sig_791, sig_792, sig_793, sig_795;
  wire sig_797, sig_799, sig_801, sig_803, sig_804, sig_805;
  wire sig_806, sig_807, sig_808, sig_810, sig_811, sig_812;
  wire sig_813, sig_814, sig_816, sig_817, sig_818, sig_819;
  wire sig_821, sig_822, sig_823;
  assign O[3] = A[8] & B[7];
  assign sig_75 = !(B[0] | B[4]);
  assign sig_76 = A[10] & B[4];
  assign sig_86 = A[9] & B[5];
  assign sig_87 = A[10] & B[5];
  assign sig_95 = A[0] & B[0];
  assign sig_96 = A[8] & B[6];
  assign sig_97 = A[9] & B[6];
  assign sig_98 = A[10] & B[6];
  assign sig_106 = A[7] & B[5];
  assign sig_107 = A[8] & B[7];
  assign sig_108 = A[9] & B[7];
  assign sig_109 = A[10] & B[7];
  assign O[7] = A[4] & B[8];
  assign sig_116 = A[6] & B[8];
  assign sig_117 = A[7] & B[8];
  assign sig_118 = A[8] & B[8];
  assign sig_119 = A[9] & B[8];
  assign sig_120 = A[10] & B[8];
  assign sig_127 = A[6] & B[9];
  assign sig_128 = A[7] & B[9];
  assign sig_129 = A[8] & B[9];
  assign sig_130 = A[9] & B[9];
  assign sig_131 = A[10] & B[9];
  assign sig_137 = A[5] & B[10];
  assign sig_138 = A[6] & B[10];
  assign sig_139 = A[7] & B[10];
  assign sig_140 = A[8] & B[10];
  assign sig_141 = A[9] & B[10];
  assign sig_142 = A[10] & B[10];
  assign O[8] = B[6] & A[5];
  assign sig_235 = A[1] & sig_75;
  assign sig_238 = sig_235;
  assign sig_239 = sig_76 & sig_86;
  assign sig_240 = sig_76 ^ sig_86;
  assign O[6] = B[7] & A[10];
  assign sig_269 = sig_95 & B[6];
  assign sig_272 = sig_269 | B[4];
  assign sig_273 = sig_96;
  assign sig_274 = A[8] & sig_106;
  assign sig_275 = sig_273 & sig_116;
  assign O[4] = sig_273 ^ sig_116;
  assign sig_277 = sig_274 | sig_275;
  assign sig_278 = sig_97 ^ sig_107;
  assign sig_279 = sig_97 & sig_107;
  assign sig_280 = sig_278 & sig_117;
  assign sig_282 = sig_279 | sig_280;
  assign sig_283 = sig_98 ^ sig_108;
  assign sig_284 = sig_98 & sig_108;
  assign sig_285 = sig_283 & sig_118;
  assign sig_286 = sig_283 ^ sig_118;
  assign sig_287 = sig_284 | sig_285;
  assign sig_288 = sig_109 & sig_119;
  assign sig_289 = sig_109 ^ sig_119;
  assign sig_376 = sig_238 ^ O[4];
  assign sig_377 = sig_238 & O[4];
  assign sig_378 = sig_376 & sig_272;
  assign sig_379 = sig_376 ^ sig_272;
  assign sig_380 = sig_377 | sig_378;
  assign sig_381 = sig_239;
  assign sig_382 = sig_239 & A[3];
  assign sig_384 = sig_381 ^ sig_277;
  assign sig_385 = sig_382;
  assign sig_386 = sig_286 & sig_282;
  assign sig_387 = sig_286 ^ sig_282;
  assign sig_388 = sig_289 & sig_287;
  assign sig_389 = sig_289 ^ sig_287;
  assign sig_390 = sig_120 & sig_288;
  assign sig_391 = sig_120 ^ sig_288;
  assign sig_420 = B[3];
  assign sig_441 = sig_240 & sig_379;
  assign sig_442 = sig_240 ^ sig_379;
  assign O[9] = sig_87 & sig_384;
  assign sig_444 = sig_87 ^ sig_384;
  assign O[15] = sig_380 ^ sig_127;
  assign sig_473 = sig_380 & sig_127;
  assign sig_474 = O[15] & sig_137;
  assign sig_475 = O[15] ^ sig_137;
  assign sig_476 = sig_473 | sig_474;
  assign sig_477 = sig_385 ^ sig_128;
  assign sig_478 = sig_385 & sig_128;
  assign sig_479 = sig_477 & sig_138;
  assign sig_480 = sig_477 ^ sig_138;
  assign sig_481 = sig_478 | sig_479;
  assign sig_482 = sig_386 ^ sig_129;
  assign sig_483 = sig_386 & sig_129;
  assign sig_484 = sig_482 & sig_139;
  assign sig_485 = sig_482 ^ sig_139;
  assign sig_486 = sig_483 | sig_484;
  assign sig_487 = sig_388 ^ sig_130;
  assign sig_488 = sig_388 & sig_130;
  assign sig_489 = sig_487 & sig_140;
  assign sig_490 = sig_487 ^ sig_140;
  assign sig_491 = sig_488 | sig_489;
  assign O[0] = sig_390 ^ sig_131;
  assign sig_493 = sig_390 & sig_131;
  assign sig_494 = O[0] & sig_141;
  assign sig_495 = O[0] ^ sig_141;
  assign sig_496 = sig_493 | sig_494;
  assign O[5] = A[10] & sig_420;
  assign sig_538 = A[5];
  assign sig_539 = sig_442 & B[6];
  assign sig_540 = !sig_538;
  assign sig_542 = sig_539 | sig_540;
  assign sig_543 = sig_444 ^ sig_441;
  assign sig_544 = sig_444 | sig_441;
  assign sig_545 = sig_543 & B[2];
  assign sig_546 = sig_543 ^ sig_475;
  assign sig_547 = sig_544 | sig_545;
  assign sig_548 = sig_387 ^ O[9];
  assign sig_549 = sig_387 & O[9];
  assign sig_550 = sig_548 & sig_480;
  assign sig_551 = sig_548 ^ sig_480;
  assign sig_552 = sig_549 | sig_550;
  assign sig_553 = sig_389 & sig_485;
  assign sig_554 = sig_389 ^ sig_485;
  assign sig_555 = sig_391 & sig_490;
  assign sig_556 = sig_391 ^ sig_490;
  assign sig_575 = A[8] ^ A[8];
  assign sig_591 = B[8] & A[5];
  assign sig_592 = sig_546 ^ sig_542;
  assign sig_593 = sig_546 & sig_542;
  assign sig_595 = !sig_592;
  assign sig_596 = sig_593;
  assign sig_597 = sig_551 ^ sig_547;
  assign sig_598 = sig_551 & sig_547;
  assign sig_599 = sig_597 & sig_476;
  assign sig_600 = sig_597 ^ sig_476;
  assign sig_601 = sig_598 | sig_599;
  assign O[1] = sig_554 ^ sig_552;
  assign O[2] = sig_554 & sig_552;
  assign sig_604 = O[1] & sig_481;
  assign sig_605 = O[1] ^ sig_481;
  assign sig_606 = O[2] | sig_604;
  assign sig_607 = sig_556 ^ sig_553;
  assign sig_608 = sig_556 & sig_553;
  assign sig_609 = sig_607 & sig_486;
  assign sig_610 = sig_607 ^ sig_486;
  assign sig_611 = sig_608 | sig_609;
  assign sig_612 = sig_495 ^ sig_555;
  assign sig_613 = sig_495 & sig_555;
  assign O[13] = sig_612 & sig_491;
  assign sig_615 = sig_612 ^ sig_491;
  assign O[10] = sig_613 | O[13];
  assign sig_617 = sig_142 & sig_496;
  assign sig_618 = sig_142 ^ sig_496;
  assign sig_621 = A[2];
  assign sig_623 = sig_621 & B[7];
  assign sig_625 = A[1] | sig_623;
  assign sig_652 = sig_575 & A[5];
  assign sig_655 = sig_652;
  assign sig_691 = !(sig_625 | A[0]);
  assign sig_692 = sig_655 & sig_691;
  assign sig_693 = B[6] & sig_625;
  assign sig_694 = sig_692 ^ sig_693;
  assign sig_707 = sig_595 ^ sig_591;
  assign sig_708 = B[3] & A[10];
  assign sig_709 = sig_707 & B[6];
  assign sig_711 = sig_708 | sig_709;
  assign sig_748 = sig_711 & A[7];
  assign sig_749 = A[6] & sig_694;
  assign sig_750 = sig_748 | sig_749;
  assign sig_751 = sig_600 ^ sig_596;
  assign sig_752 = sig_600 & sig_596;
  assign sig_753 = sig_605 ^ sig_601;
  assign sig_754 = sig_605 & sig_601;
  assign sig_755 = sig_753 & sig_752;
  assign sig_756 = sig_753 ^ sig_752;
  assign sig_757 = sig_754 | sig_755;
  assign sig_758 = sig_610 ^ sig_606;
  assign sig_759 = sig_610 & sig_606;
  assign sig_760 = sig_758 & sig_757;
  assign sig_761 = sig_758 ^ sig_757;
  assign sig_762 = sig_759 | sig_760;
  assign sig_763 = sig_615 ^ sig_611;
  assign sig_764 = sig_615 & sig_611;
  assign sig_765 = sig_763 & sig_762;
  assign sig_766 = sig_763 ^ sig_762;
  assign sig_767 = sig_764 | sig_765;
  assign sig_768 = !(sig_600 ^ A[2]);
  assign sig_769 = sig_600 & B[9];
  assign sig_770 = !sig_768;
  assign sig_771 = sig_769 | sig_768;
  assign sig_772 = sig_605 ^ sig_601;
  assign sig_773 = sig_605 & sig_601;
  assign sig_774 = sig_772 & sig_771;
  assign sig_775 = sig_772 ^ sig_771;
  assign sig_776 = sig_773 ^ sig_774;
  assign sig_777 = sig_610 ^ sig_606;
  assign sig_778 = sig_610 & sig_606;
  assign sig_779 = sig_777 & sig_776;
  assign sig_780 = sig_777 ^ sig_776;
  assign sig_781 = sig_778 | sig_779;
  assign sig_782 = sig_615 ^ sig_611;
  assign sig_783 = sig_615 & sig_611;
  assign sig_784 = sig_782 & sig_781;
  assign sig_785 = sig_782 ^ sig_781;
  assign sig_786 = sig_783 | sig_784;
  assign sig_787 = !sig_750;
  assign sig_788 = sig_751 & sig_787;
  assign sig_789 = sig_770 & sig_750;
  assign O[16] = sig_788 | sig_789;
  assign sig_791 = !sig_750;
  assign sig_792 = sig_756 & sig_791;
  assign sig_793 = sig_775 & sig_750;
  assign O[11] = sig_792 | sig_793;
  assign sig_795 = !sig_750;
  assign O[12] = sig_761 & sig_795;
  assign sig_797 = sig_780 & sig_750;
  assign O[18] = O[12] | sig_797;
  assign sig_799 = !sig_750;
  assign O[14] = sig_766 & sig_799;
  assign sig_801 = sig_785 & sig_750;
  assign O[19] = O[14] ^ sig_801;
  assign sig_803 = !sig_750;
  assign sig_804 = sig_767 & sig_803;
  assign sig_805 = sig_786 & sig_750;
  assign sig_806 = sig_804 | sig_805;
  assign sig_807 = sig_618 ^ O[10];
  assign sig_808 = sig_618 & O[10];
  assign sig_810 = sig_617 ^ sig_808;
  assign sig_811 = sig_618 ^ O[10];
  assign sig_812 = A[6] & O[10];
  assign sig_813 = !sig_811;
  assign sig_814 = sig_812 | sig_811;
  assign sig_816 = sig_617 ^ sig_814;
  assign sig_817 = !sig_806;
  assign sig_818 = sig_807 & sig_817;
  assign sig_819 = sig_813 & sig_806;
  assign O[20] = sig_818 | sig_819;
  assign sig_821 = !sig_806;
  assign sig_822 = sig_810 & sig_821;
  assign sig_823 = sig_816 & sig_806;
  assign O[21] = sig_822 | sig_823;
  assign O[17] = O[11];
endmodule

