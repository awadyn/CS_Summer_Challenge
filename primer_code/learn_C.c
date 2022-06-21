/*
 PL: C
 PL translator: gcc compiler
 To compile and run this C file:	gcc -o learner learn_C.c
					./learner

**********

 C constructs: - functions (instructions) + variables (data)
	       - data types: int (integer), char (character), double (decimal)

**********

**********

 C rules: --> every C file must define a main() function
	  --> every C variable must define its type on first use
	  --> every C function must define its return type (default return type: void)
	  --> every C predefined function must be imported with #include <function_file.h>

**********

**********

 C operations:
    assignment:				type var = val;
					var = val1 +/-* val2;
    function call:			function(var1, var2, ...);
    assignment to function output:	varX = func(var1, var2, ...);
    function definition:		return_type function(var1, var2, ...) {
						<operation>;
						<operation>;
						...
						return varX;
					}
*/

#include <stdio.h>

// TODO: replicate Python learner code here

