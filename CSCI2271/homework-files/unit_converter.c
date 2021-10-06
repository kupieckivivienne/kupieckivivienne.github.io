/*Author: Vivienne Kupiecki, kupiecki@bc.edu 
 * Source codes: 
 * tolower() -> Implementation of ToLower function in c (Stackoverflow.com) 
 * strcmp() -> C library function strcmp() (tutorialspoint.com) 
 * stderr() -> How can I print to stderr in C? (stackoverflow.com) 
 * fahrenheit_to_celsius, celsius_to_fahrenheit functions -> conveter.c in class lab 
 */ 
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h> 

//Define constant variables
#define MAX_UNIT_LENGTH 3 
//For temp 
#define NUMERATOR 9.0
#define DENOMINATOR 5.0 
#define ZERO 32.0

//for mass/weight
#define MASS_CONST 2.2046

//for distance 
#define LENGTH_CONST 1.0936

// define enum types 
typedef enum Measure {LENGTH, MASS, TEMP}; 
typedef enum System {METRIC, US};  
typedef enum Op {MULT,DIV};

// declare functions
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit); 
double convert_from_tokens(double value, char * unit, char ** output_unit); 
double convert(double value, enum Measure measure, enum System system); 
double apply(double value, enum Op op, double factor);  

void str_to_lower(char * unit) 
{ 
	for (int i = 0; unit[i]; i++) 
	{ 
		unit[i] = tolower(unit[i]); 
	} 	
}
double convert_from_tokens(double value, char * unit, char ** output_unit) 
{ 
	/* Find three things, return two things 
	 * Find system, measure, 
	 */ 
	// have a string called units, an array of characters 
	// First, lowercase the string 
	//Only switch to lower if the unit is not F or C.
		
	if (strcmp(unit, "F") && strcmp(unit, "C"))
	{ 
		str_to_lower(unit); 	
	}	
	//Next, check cases 
	if (! strcmp(unit, "C")) 
	{ 
		//set value of output unit 
		//return the converted value 
		*output_unit = "F"; 
		return convert(value, TEMP, METRIC); 
	}	
	else if (! strcmp(unit, "F")) 
	{ 
	 	*output_unit = "C"; 
       		return convert(value, TEMP, US); 	       
	}
	else if(! strcmp(unit, "m")) 
	{ 
		*output_unit = "yd"; 
		return convert(value, LENGTH, METRIC);
	}
	else if(! strcmp(unit, "yd")) 
	{ 
		*output_unit = "m"; 
		return convert(value, LENGTH, US); 
	}	
	else if(! strcmp(unit, "kg")) 
	{ 
		*output_unit = "lb"; 
		return convert(value, MASS, METRIC); 
	}
	else if(! strcmp(unit, "lb")) 
	{ 
		*output_unit = "kg"; 
		return convert(value, MASS, US);
	}	

	else 
	{ 
		return NAN; 
	}	
	 	
} 

double convert(double value, enum Measure measure, enum System system) 
{  
	// Do temp first 
	switch (measure)
	{ 
		case TEMP: 
			if (system == METRIC) 
			{ 
				return celsius_to_fahrenheit(value);
				// return has same action as a break statement
			}	
			else
			{
				return fahrenheit_to_celsius(value); 	
			} 
		case LENGTH: 
			if(system == METRIC) 
			{ 
			       return apply(value, MULT, LENGTH_CONST); 	
			} 
			else 
			{ 
				return apply(value, DIV, LENGTH_CONST); 
			}
		case MASS: 
			if (system == METRIC) 
			{ 
			       return apply(value, MULT, MASS_CONST); 	
			}
			else
			{ 
				return apply(value, DIV, MASS_CONST); 
			}	
		default: 
			fprintf(stderr, "%s", "INVALID MEASURE\n");
			exit(EXIT_FAILURE); 
	}	
} 

double apply(double value, enum Op op, double factor) 
{ 
	if (op == MULT)
	{ 
	       double output_value = value * factor; 
	       return output_value; 
	}	
	else
	{ 
		double output_value = value / factor; 
		return output_value; 
	}	
}
int main() 
{ 
	char unit[MAX_UNIT_LENGTH]; 
	double value; 
	char * output_unit; 
	printf("Please enter a temperature, length, or mass, as a decimal number, followed by a unit to be converted: \n");
       	printf("-- F, lb, yd, C, kg, or m. \n Enter q to quit.\n"); 	
	printf(">"); 
	while(scanf("%lf %s", &value, unit)) 
	{ 
		//Call convert from tokens
		double output_value = convert_from_tokens(value, unit, &output_unit);
		if (! isnan(output_value)) 
		{ 	
			printf("%.2f %s = %.2f %s\n", value, unit, output_value, output_unit);   
		      	printf(">");	
		}	
	}

}
//function that converts celsius to fahrenheit 
double celsius_to_fahrenheit(double celsius)
{ 
	double fahrenheit = NUMERATOR * celsius / DENOMINATOR + ZERO; 
	return fahrenheit; 
}	

//Function that converts fahrenheit to celsius 
double fahrenheit_to_celsius(double fahrenheit) 
{ 
	double celsius = DENOMINATOR * (fahrenheit - ZERO) / NUMERATOR; 
	return celsius; 
}	


