/** Author: Vivienne Kupiecki @kupiecki@bc.edu 
 * Source codes: lab6.c, main.c, makefile, lab6.h --> author: Amitai Arivam 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

#include "pa2.h"


void print_bits(unsigned INT_TYPE input, unsigned INT_TYPE size) {
	unsigned int shift = size-1; 
	unsigned INT_TYPE mask = U_ONE << shift; 
	while (mask) {
        putchar((! (! (input & mask))) + '0');
        mask >>= 1;
	--shift;
    }
}


void print_fields(union Converter input) 
{
	// Print sign
	fputs("Sign: ", stdout);
	print_bits(input.fields.sign, SIGN_SIZE);
	putchar('\n');
    	// Print exponent
	fputs("Exponent: ", stdout);
	print_bits(input.fields.exponent, EXPONENT_SIZE); 
	putchar('\n'); 
    	// Print mantissa
	fputs("Mantissa: ", stdout);
	print_bits(input.fields.mantissa, MANTISSA_SIZE);
	putchar('\n');
}

// Function that converts the mantissa by applying the correct formula.
FP_TYPE mantissa_convert(unsigned INT_TYPE mantissa){ 
	FP_TYPE temp = (FP_TYPE) mantissa; 
	for (int i = 0; i< MANTISSA_SIZE; ++i){ 
		temp /=2; 
	} 
	return temp; 
}
// returns the exponent if it is normalized.
INT_TYPE is_normalized(unsigned INT_TYPE exponent){ 
	return exponent != 0; 
} 
// returns the exponent if it is denormalized.
INT_TYPE is_denormalized(unsigned INT_TYPE exponent){ 
	return exponent == 0; 
}


void print_normalized(union Converter converter){ 
	// checks if the input value is zero
	if(converter.f == 0){ 
		// checks the sign of the input value (-0 or +0) 
		if(!(converter.fields.sign)){ 
			printf("Original value: 0.0");	
		} 
		else {
			printf("Original value: -0.0"); 
		} 
	}
	else { 
		printf("Original value: (-1)^{%d} ", converter.fields.sign); 
		if (is_normalized(converter.fields.exponent)) { 
			printf("x (1+ %f)", mantissa_convert(converter.fields.mantissa)); 
			printf("x 2^{%u - %u} ", converter.fields.exponent, BIAS);
		}		
		if (is_denormalized(converter.fields.exponent)){
			printf("x %.45f ", mantissa_convert(converter.fields.mantissa));
			printf("x 2^{1 - %u}", BIAS); 
		}
		printf("= %.2f", converter.f); 
	} 
	putchar('\n'); 
}



	


