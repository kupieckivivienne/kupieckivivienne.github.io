module ComparatorStructural(input[1:0] a, input[1:0] b, output gt);
	wire w1, w2, w3, w4, w5, w6, w7, w8, w9;
	not g1(w1, b[1]);
	not g2(w2, b[0]);
	and g3(w3, w1, w2);
	and g4(w4, w3, a[0]);
	
	and g5(w5, a[1], w1);

	and g6(w6, a[1], a[0]);
	and g7(w7, w6, w2);

	or g8(w9, w4, w5);
	or g9(gt, w9, w7);

endmodule

module ComparatorDataflow(input[1:0] a, input[1:0] b, output gt);
	assign gt = (a[0] & ~b[1] & ~b[0]) + (a[1] & ~b[1]) + (a[1] & a[0] & ~b[0]);
	
endmodule

module ComparatorTest;
	reg[1:0] a,b;
	wire gt;
	ComparatorDataflow circuit(a, b, gt);
	
	initial begin
		$monitor("%d a b = %b%b gt = %b", $time, a, b, gt);
		#10 {a,b} = 0;
		#10 {a,b} = 1;
		#10 {a,b} = 2;
		#10 {a,b} = 3;
		#10 {a,b} = 4;
		#10 {a,b} = 5;
		#10 {a,b} = 6;
		#10 {a,b} = 7;
		#10 {a,b} = 8;
		#10 {a,b} = 9;
		#10 {a,b} = 10;
		#10 {a,b} = 11;
		#10 {a,b} = 12;
		#10 {a,b} = 13;
		#10 {a,b} = 14;
		#10 {a,b} = 15;
		#10 $finish;
	end

endmodule
