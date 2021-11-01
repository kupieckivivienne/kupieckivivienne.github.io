// Author: Vivienne Kupiecki -- kupiecki@bc.edu 
// Source Codes: Amittai, Arivam. Computer Systems. October 19th, 2021 
 
#include <stdio.h> 
#include <stdlib.h> 

int div_qr(int dividend, int divisor, int * remainder); 

int main(){ 
	int dividend; 
	int divisor; 
	int remainder; 
	puts("Please enter an integer dividend and divisor, or \"q\" to quit."); 
	printf("> "); 
	while(scanf("%d %d", &dividend, &divisor)){ 
		if (divisor == 0) { 
			puts("Division by 0 is undefined."); 
		} 
		else {
			int quotient = div_qr(dividend, divisor, &remainder); 
			printf("%d / %d = %d, r %d\n", dividend, divisor, quotient, remainder);
		} 
		printf("> "); 
	} 
	return EXIT_SUCCESS;   	
}
