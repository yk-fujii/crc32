module crc(
	input wire clk,
	input wire rst,
	input wire [31:0] data,
	output reg [31:0] hash
);


reg[32:0] POLYNOMIAL = 33'h 104c11DB7;
reg[31:0] ini;
reg[33:0] poly;
reg[31:0] r;

integer j;

always @(posedge clk or posedge rst) 
begin 
if(rst) begin
	r = 32'd0;
end else if(clk) begin
	r = data;
	poly = POLYNOMIAL;

	for(j=0; j<32; j=j+1) begin

		if(r[31]!=0) begin
			r[31:1] = r[30:0];
			r[0] = 1'b0;
			r[31:0] = r[31:0] ^ poly[31:0];

		end else begin
			r[31:1] = r[30:0];
			r[0] = 1'b0;
		end
		hash <=  r;
	end
end
end
endmodule
