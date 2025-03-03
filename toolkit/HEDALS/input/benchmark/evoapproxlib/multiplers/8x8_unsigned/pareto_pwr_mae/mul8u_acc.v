module mult8u_acc(
    A,
    B,
    O
);

input [7:0] A;
input [7:0] B;
output [15:0] O;


assign O = A * B;

endmodule