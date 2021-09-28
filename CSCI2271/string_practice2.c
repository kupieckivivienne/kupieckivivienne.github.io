#include <stdio.h> 

void string_copy1(char *str, char *buffer) 
{ 
	int i = 0; 
	while(str[i] != '\0') 
	{ 
		buffer[i] = str[i];
	}

} 

/* dereference str and read the value 
 * dereference buffer 
 * assign (write) the value 
 * increment str to the next address in the array 
 * increment buffer to the next address in that array. 
 */ 
void string_copy2(char *str, char *buffer) 
{ 
       while((buffer++ = *str++)); 	
}
