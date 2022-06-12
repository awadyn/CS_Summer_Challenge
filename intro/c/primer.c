/* Learning Objectives

- Reason for learning C:
-- The Python language hides from the user the many stages taken by the interpreter software to translate the Python code into a machine-level encoding.

- 

*/ 

// start translation:
/*
- Like the Python language defines a print function,
- C defines a printf function.
- Unlike the Python language, in C programming, every pre-defined function must be credited to its source file - i.e. its implementation.
- In C, #include<filename> is used to import code not in the current file for use by the current file.

- printf does not automatically add a new line like a print function.
- Hence, we have to type in the character encoding of a new line.
- In the language of programming - i.e. ASCII - the character encoding for a new line is /n.

- The C compiler will take care of converting the characters in the ASCII string to binary code/language.

- The C compiler requires that every single line of code is ended with a ; by the programmer. This informs the compiler of what a single line of code is.
- Unlike Python, C is compiled in full, not line by line. Python by its design separates its scripts into lines.

*/

/*
#include<stdio.h>

printf("Hello from me!\n");
*/

/*
- If we compile the above, we will get an error.
- This is because the compiler was confused.
- Just like the Python interpreter expects correctly written single lines of code in a script,
- the C compiler gcc expects correctly written C code that it was programmed to translate.
- Though Python seemed so straightforward, it has its own language rules.
- C has more rules. This is because writing C code is more close to creating binary code than Python.
- For many of the rules, you will see that they map directly to the visualization of how binary code executes.
- This is why I think learning C is important, because it helps you understand binary structure of software.

- Rule 1: every C program must have a 'main()' function.
- The compiler looks for this function when preparing the binary code.
- It places this function in the final binary code such that execution begins with the code of this function.
- In this function, we can make calls to other functions, such as printf.
- The source of printf still has to be included. 

- Rule 2: every C function must have a return type
- A function computes something and can sometimes return the result of computation.
- In C, the type of this data must be specified when defining a new function.
- The printf function only displays to the screen, it does not return any data.
- A non-return type is called void.
- The main function must always return an integer. Reason for later.

*/

/*
#include<stdio.h>

int main() {
	printf("Hello from me!\n");

	return 0;
}
*/

/*
	compiling and running
*/

/*
	data types: string is char array
	passing multiple parameters to printf function
		noting string concatenation not a basic operation in C
	format strings: specify the type of data to interpret the parameter as
*/

/*
#include <stdio.h>

char name[] = "Yara";
char greeting[] = "Hello from me: ";

int main() {

	printf("%s %s\n", greeting, name);
	printf("%p %p\n", &greeting, &name);

	return 0;
}
*/

int num_1 = 5;
int num_2 = 7;

int sum() {
	int sum = num_1 + num_2;
	return sum;
}

//int sum()(int x, int y) {
//	int sum = x + y;
//	return sum;
//}

int main() {
	int my_sum = sum();
	//int my_sum = sum(num_1, num_2);
	printf("sum = %d\n", my_sum);
	return 0;
}

// NOTE data types, data sizes, all visible with objdump

/*
	from objdump, note the hex values that represent our strings
	goto data representation
*/



