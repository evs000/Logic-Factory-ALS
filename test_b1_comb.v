// Benchmark "top_module" written by ABC on Tue Jan 14 15:30:15 2025

module top_module ( 
    n1, n2, n3,
    n4, n5, n6  );
  input  n1, n2, n3;
  output n4, n5, n6;
  wire new_n8, new_n9;
  sky130_fd_sc_hs__xor2_1          g0(.A(n1), .B(n2), .X(n4));
  sky130_fd_sc_hs__a21oi_1         g1(.A1(n1), .A2(n2), .B1(n3), .Y(new_n8));
  sky130_fd_sc_hs__o21a_1          g2(.A1(n1), .A2(n2), .B1(n3), .X(new_n9));
  sky130_fd_sc_hs__nor2_1          g3(.A(new_n8), .B(new_n9), .Y(n5));
  sky130_fd_sc_hs__clkinv_1        g4(.A(n3), .Y(n6));
endmodule


