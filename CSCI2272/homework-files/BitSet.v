module BitSetStructural(
		input [3:0]x, 
		input [1:0]index, 
		input value, 
		output [3:0]y); 

	always @(x, index, value); 

	assign y[0] = (index == 2'b00) ? value : x[0]; 
	assign y[1] = (index == 2'b01) ? value : x[1]; 
	assign y[2] = (index == 2'b10) ? value : x[2]; 
	assign y[3] = (index == 2'b11) ? value : x[3]; 

endmodule 

module BitSetTest; 
	reg [3:0]x;  
	reg [1:0] index; 
	reg value;
	wire [3:0] y; 

	BitSetStructural bit_set_structural(x, index, value, y); 
	
	initial begin 
		$monitor("%d x = %b, index = %d, value = %b, y = %b", $time, x, index, value, y); 

	#10 
		x = 15;
		index = 2; 
		value = 0; 

	#10 
		x = 8; 
		index = 0; 
		value = 1; 
	#10 

		x = 4; 
		index = 3; 
		value = 1; 
	#10 

		x = 10; 
		index = 1; 
		value = 0; 

	end 

endmodule  
	 
