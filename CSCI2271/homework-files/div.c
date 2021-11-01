// Author: Vivienne Kupiecki -- kupiecki@bc.edu 
// Source Codes: Amittai, Arivam. Computer Systems. October 19th, 2021 
int div_qr(int dividend, int divisor, int * remainder){ 
	int quotient = dividend / divisor; 
	*remainder = dividend % divisor; 
	return quotient; 
} 
