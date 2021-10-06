/** Author: Vivienne Kupiecki @kupiecki@bc.edu 
 *
 */ 

//header file that defines symbolic constants, a bit field (structure) type, 
// and a union type to be use for conversion between floating-point numbers 

#define BYTE_SIZE 8

#ifdef FLOAT 
#define FP_TYPE float
#define INT_TYPE int
#define FORMAT_STRING "%f"
#define U_ONE 1u
#define EXPONENT_SIZE 8

#else
#define FP_TYPE double
#define INT_TYPE long
#define FORMAT_STRING "%lf"
#define U_ONE 1ul
#define EXPONENT_SIZE 11
#endif

#define TYPE_SIZE (sizeof(FP_TYPE) * BYTE_SIZE)
#define SIGN_SIZE 1
#define MANTISSA_SIZE (TYPE_SIZE - SIGN_SIZE - EXPONENT_SIZE)
#define BIAS ((1u << (EXPONENT_SIZE - 1)) - 1)

union Converter {
    FP_TYPE f;
    unsigned INT_TYPE u;
    struct {
        unsigned INT_TYPE mantissa : MANTISSA_SIZE;
        unsigned INT_TYPE exponent : EXPONENT_SIZE;
        unsigned INT_TYPE sign : SIGN_SIZE;
    } fields;
};

// Call functions 

void print_bits(unsigned INT_TYPE input, unsigned INT_TYPE size); 

void print_fields(union Converter input);

void print_normalized(union Converter converter); 

INT_TYPE is_normalized(unsigned INT_TYPE exponent); 

INT_TYPE is_denormalized(unsigned INT_TYPE exponent); 

FP_TYPE mantissa_convert(unsigned INT_TYPE mantissa); 
