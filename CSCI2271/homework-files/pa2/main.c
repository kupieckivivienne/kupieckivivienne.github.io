/** Author: Vivienne Kupiecki @kupiecki@bc.edu 
 *
 */ 
#include <stdlib.h> 
#include <stdio.h>
#include "pa2.h"

int main() {
	union Converter value_float;
	puts("Please enter a floating-point number or q to quit.");
	printf("> ");
	while (scanf(FORMAT_STRING, &value_float.f)) {
		//prints the float 
        	printf("%f\n", value_float.f);
		//prints all bits of float on one line 
		// Print all bits
		printf("All bits: "); 
		print_bits(value_float.u, sizeof(value_float.u) * BYTE_SIZE); 
		putchar('\n'); 
        	print_fields(value_float);
		putchar('\n'); 
		print_normalized(value_float); 
		putchar('\n');
        	printf("> ");
    	}
    	return EXIT_SUCCESS;
}

