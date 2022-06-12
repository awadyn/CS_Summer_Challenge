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

#include<stdio.h>

printf("Hello from me!\n");


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


*/

#include<stdio.h>

main() {
	printf("Hello from me!\n");
}
