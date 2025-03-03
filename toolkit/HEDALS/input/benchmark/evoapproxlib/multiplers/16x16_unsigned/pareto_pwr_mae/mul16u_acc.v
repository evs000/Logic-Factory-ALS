module mult16u_acc(
    A,
    B,
    O
);

input [15:0] A;
input [15:0] B;
output [31:0] O;


assign O = A * B;

endmodule