/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, Z. Vasicek, L. Sekanina, H. Jiang and J. Han, "Scalable Construction of Approximate Multipliers With Formally Guaranteed Worst Case Error" in IEEE Transactions on Very Large Scale Integration (VLSI) Systems, vol. 26, no. 11, pp. 2572-2576, Nov. 2018. doi: 10.1109/TVLSI.2018.2856362 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mse parameters
***/
// MAE% = 0.52 %
// MAE = 88064 
// WCE% = 2.10 %
// WCE = 352257 
// WCRE% = 100.00 %
// EP% = 99.94 %
// MRE% = 7.84 %
// MSE = 96443.585e5 
// PDK45_PWR = 0.220 mW
// PDK45_AREA = 420.5 um2
// PDK45_DELAY = 1.50 ns


module mul12u_2F1 ( A, B, O );
  input [11:0] A;
  input [11:0] B;
  output [23:0] O;

  wire C_10_10,C_10_5,C_10_6,C_10_7,C_10_8,C_10_9,C_11_10,C_11_4,C_11_5,C_11_6,C_11_7,C_11_8,C_11_9,C_12_10,C_12_4,C_12_5,C_12_6,C_12_7,C_12_8,C_12_9,C_6_10,C_6_9,C_7_10,C_7_8,C_7_9,C_8_10,C_8_7,C_8_8,C_8_9,C_9_10,C_9_6,C_9_7,C_9_8,C_9_9,S_10_10,S_10_11,S_10_5,S_10_6,S_10_7,S_10_8,S_10_9,S_11_10,S_11_11,S_11_4,S_11_5,S_11_6,S_11_7,S_11_8,S_11_9,S_12_10,S_12_11,S_12_3,S_12_4,S_12_5,S_12_6,S_12_7,S_12_8,S_12_9,S_5_10,S_5_11,S_6_10,S_6_11,S_6_9,S_7_10,S_7_11,S_7_8,S_7_9,S_8_10,S_8_11,S_8_7,S_8_8,S_8_9,S_9_10,S_9_11,S_9_6,S_9_7,S_9_8,S_9_9;

  assign S_5_10 = (A[5] & B[10]);
  assign S_5_11 = (A[5] & B[11]);
  HAX1 U46498 (.A(S_5_10), .B((A[6] & B[9])), .YS(S_6_9), .YC(C_6_9));
  HAX1 U46499 (.A(S_5_11), .B((A[6] & B[10])), .YS(S_6_10), .YC(C_6_10));
  assign S_6_11 = (A[6] & B[11]);
  HAX1 U46509 (.A(S_6_9), .B((A[7] & B[8])), .YS(S_7_8), .YC(C_7_8));
  FAX1 U46510 (.A(S_6_10), .B(C_6_9), .C((A[7] & B[9])), .YS(S_7_9), .YC(C_7_9));
  FAX1 U46511 (.A(S_6_11), .B(C_6_10), .C((A[7] & B[10])), .YS(S_7_10), .YC(C_7_10));
  assign S_7_11 = (A[7] & B[11]);
  HAX1 U46520 (.A(S_7_8), .B((A[8] & B[7])), .YS(S_8_7), .YC(C_8_7));
  FAX1 U46521 (.A(S_7_9), .B(C_7_8), .C((A[8] & B[8])), .YS(S_8_8), .YC(C_8_8));
  FAX1 U46522 (.A(S_7_10), .B(C_7_9), .C((A[8] & B[9])), .YS(S_8_9), .YC(C_8_9));
  FAX1 U46523 (.A(S_7_11), .B(C_7_10), .C((A[8] & B[10])), .YS(S_8_10), .YC(C_8_10));
  assign S_8_11 = (A[8] & B[11]);
  HAX1 U46531 (.A(S_8_7), .B((A[9] & B[6])), .YS(S_9_6), .YC(C_9_6));
  FAX1 U46532 (.A(S_8_8), .B(C_8_7), .C((A[9] & B[7])), .YS(S_9_7), .YC(C_9_7));
  FAX1 U46533 (.A(S_8_9), .B(C_8_8), .C((A[9] & B[8])), .YS(S_9_8), .YC(C_9_8));
  FAX1 U46534 (.A(S_8_10), .B(C_8_9), .C((A[9] & B[9])), .YS(S_9_9), .YC(C_9_9));
  FAX1 U46535 (.A(S_8_11), .B(C_8_10), .C((A[9] & B[10])), .YS(S_9_10), .YC(C_9_10));
  assign S_9_11 = (A[9] & B[11]);
  HAX1 U46542 (.A(S_9_6), .B((A[10] & B[5])), .YS(S_10_5), .YC(C_10_5));
  FAX1 U46543 (.A(S_9_7), .B(C_9_6), .C((A[10] & B[6])), .YS(S_10_6), .YC(C_10_6));
  FAX1 U46544 (.A(S_9_8), .B(C_9_7), .C((A[10] & B[7])), .YS(S_10_7), .YC(C_10_7));
  FAX1 U46545 (.A(S_9_9), .B(C_9_8), .C((A[10] & B[8])), .YS(S_10_8), .YC(C_10_8));
  FAX1 U46546 (.A(S_9_10), .B(C_9_9), .C((A[10] & B[9])), .YS(S_10_9), .YC(C_10_9));
  FAX1 U46547 (.A(S_9_11), .B(C_9_10), .C((A[10] & B[10])), .YS(S_10_10), .YC(C_10_10));
  assign S_10_11 = (A[10] & B[11]);
  HAX1 U46553 (.A(S_10_5), .B((A[11] & B[4])), .YS(S_11_4), .YC(C_11_4));
  FAX1 U46554 (.A(S_10_6), .B(C_10_5), .C((A[11] & B[5])), .YS(S_11_5), .YC(C_11_5));
  FAX1 U46555 (.A(S_10_7), .B(C_10_6), .C((A[11] & B[6])), .YS(S_11_6), .YC(C_11_6));
  FAX1 U46556 (.A(S_10_8), .B(C_10_7), .C((A[11] & B[7])), .YS(S_11_7), .YC(C_11_7));
  FAX1 U46557 (.A(S_10_9), .B(C_10_8), .C((A[11] & B[8])), .YS(S_11_8), .YC(C_11_8));
  FAX1 U46558 (.A(S_10_10), .B(C_10_9), .C((A[11] & B[9])), .YS(S_11_9), .YC(C_11_9));
  FAX1 U46559 (.A(S_10_11), .B(C_10_10), .C((A[11] & B[10])), .YS(S_11_10), .YC(C_11_10));
  assign S_11_11 = (A[11] & B[11]);
  assign S_12_3 = S_11_4;
  HAX1 U46565 (.A(S_11_5), .B(C_11_4), .YS(S_12_4), .YC(C_12_4));
  FAX1 U46566 (.A(S_11_6), .B(C_12_4), .C(C_11_5), .YS(S_12_5), .YC(C_12_5));
  FAX1 U46567 (.A(S_11_7), .B(C_12_5), .C(C_11_6), .YS(S_12_6), .YC(C_12_6));
  FAX1 U46568 (.A(S_11_8), .B(C_12_6), .C(C_11_7), .YS(S_12_7), .YC(C_12_7));
  FAX1 U46569 (.A(S_11_9), .B(C_12_7), .C(C_11_8), .YS(S_12_8), .YC(C_12_8));
  FAX1 U46570 (.A(S_11_10), .B(C_12_8), .C(C_11_9), .YS(S_12_9), .YC(C_12_9));
  FAX1 U46571 (.A(S_11_11), .B(C_12_9), .C(C_11_10), .YS(S_12_10), .YC(C_12_10));
  assign S_12_11 = C_12_10;
  assign O = {S_12_11,S_12_10,S_12_9,S_12_8,S_12_7,S_12_6,S_12_5,S_12_4,S_12_3,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0};

endmodule

