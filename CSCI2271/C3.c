#include <stdio.h> 

/* Prints a table of Fahrenheit and Celsius temperatures. 
 */ 
int main() 
{  
	// create variables 
	int fahrenheit, celsius; 
	int lower, upper, step;
	//declare variable values 
	lower = 0; 
	upper = 300; 
	step = 20; 

	fahrenheit = lower; 
	while (fahrenheit <= uppper) 
	{  
		celsius = 5* (fahrenheit - 32)/9; 
		printf("%d %d\n", fahrenheit, celsius); 
		fahrenheit = fahreneit + step; 	
	}  
	return 0; 
} 
