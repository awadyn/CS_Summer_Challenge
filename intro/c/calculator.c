#include <stdio.h>

// NOTE: data types - and initial values (optional)
int num_1;
int num_2;
char operator;
int result;

int sum(int x, int y) {
	int sum = x + y;
	return sum;
}

int calculate() {
	// NOTE: - calling predefined scanf function
	//	 - format string specifies data type; scanf function will use this
	//	 input parameter to know that it must cast our input ASCII string
	//	 into the binary representation of an integer value
	//	 - then, scanf uses the second input parameter to know where to store
	//	 the read integer value, here in the address of num_1
	// 	 - now, the value of num_1 will from 0 to our input, because the content
	//	 of the memory dedicated to num_1 was changed
	//	 - scanf is also defined in stdio.h like printf
	printf("Enter your first parameter:\n");
	scanf("%d", &num_1);
	printf("Enter your operator:\n");
	// NOTE: - format string specifies character data type
	// NOTE: - bug before adding newline to the format string
	//	   this is because a newline character is stuck in the input stream
	//	   from the entry of the input before this
	// NOTE: - debug this by looking at the output
	scanf("\n%c", &operator);
	printf("Enter your second parameter:\n");
	scanf("%d", &num_2);

	if (operator == '+') {
		result = sum(num_1, num_2);
	}

	// testing
	// NOTE: use of format string in C versus commas in python
	printf("%d %c %d = %d\n", num_1, operator, num_2, result);

	return result;
}

int main() {
	calculate();

	return 0;
}

/*
	GOTO build, see objdumps of data and bss and text regions
	GOTO gdb
	- explain debugging: pausing at certain times in execution and
	  observing the contents of the binary code - i.e. variables
	- layout split: - observe C code alongside the binary code
			- explain disassembly from binary signal to assembly text
	- print var, print/t var
	- x/b memory, x/x memory
	- note how the same binary pattern can be interpreted in different
	  ways to reflect different data types
*/





