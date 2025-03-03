module mult11u_acc(
    A,
    B,
    O
);

input [10:0] A;
input [10:0] B;
output [21:0] O;


assign O = A * B;

endmodule