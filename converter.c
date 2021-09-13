/* Authors: Vivienne Kupiecki--kupiecki@bc.edu
 * Thomas Li--@licxb@bc.edu
 * Source Codes: 
 *techonthenet.com/c_language/standard_library_functions/stdlib_h/strtod.php  
 */ 
#include <stdio.h> 
#include <stdlib.h> 

// declaration of functions 
double tempConverter(double celsius); 
void userError(int argc); 

int main(int argc, char * argv[])
{ 
        userError(argc); 
	double celsius = strtod(argv[1], NULL); 
	double result = tempConverter(celsius); 
	printf("Celsius = %.2f\n",celsius); 
       	printf("Fahrenheit = %.2f", result); 
	return EXIT_SUCCESS; 
 		
} 

//function that converts celsius to fahrenheit 
double tempConverter(double celsius)
{ 
	double fahrenheit = 9.0 * celsius / 5.0 + 32.0; 
	return fahrenheit; 
}	

//Fuction that will release an error message if user inputs less than two statements. 
void userError(int argc)  
{  
	if(argc <2) 
	{ 
		printf("PLEASE ENTER AT LEAST ONE INPUT!\n"); 
		exit(EXIT_FAILURE); 
	}
}
