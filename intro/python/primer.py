## Learning Objectives:
#
#
#
# Code = data + instructions
## A code file has variables and functions. Functions can use variables.
## Our code file is written in Python. It uses a 'print' function that prints a 'string' variable. A string is a sequence of ASCII characters.
## A variable 'greeting' can be used to store a string. Then, the print function can print the value of this variable.
#
#
# Execution = operation of written code
## A Python code file is converted to a runnable binary code by the
## python3 interpreter s/w. The interpreter parses the code line by 
## line and converts it to binary encodings.
## For a binary code to run, it is copied to memory.
## In the binary code, each function has a unique address/id,
## and each variable has a unique address/id.
## When executing, the processor/cpu can locate different functions and
## variables it needs through their unique memory addresses.
#
#
# Defining Variables and Functions
## Just like the print function that is defined in the Python language
## we can define our own functions.
## A 'greet' function can be defined to always use the Python 'print'
## function to display a greeting.
## During interpretation, user defined variable 'greeting' is first
## translated to its binary encoding: a region of the full binary code
## that contains the value of 'greeting'.
## Then, function 'greet' is translated to its binary encoding: a 
## region of the full binary that contains the instructions of the
## function.
## Finally, the call to 'greet' is converted to its binary encoding,
## which tells the processor to execute the instructions of 'greet'.



# PL constructs:
## making function calls - PL vocabulary
## function arguments
## constant data, data types

## try 0
## TODO: making a call to predefined print function, passing a
##	 string variable
## NOTE: python3 interpretter translates python code to binary code;
##	 the call to the print function becomes a sequence of binary
##	 encodings, and the characters of the greeting are translated
##	 to a binary representation of them;
##	 the OS then runs this code to print to screen.

print("Hello from me! Welcome to CS Summer Challenge :)")


# PL constructs:
## user-defined variables
## function argument passing

## try 1
## TODO: using variables
## NOTE: python3 translates variables to regions in the binary code
## 	 that hold chunks of data; it then translates the print
##	 function such that it knows the location of these chunks
##	 in the code
 
greeting = "Hello from me! Welcome to CS Summer Challenge :)"
print(greeting)

print(id(greeting))
print(id(print))


# PL constructs:
## basic operations

## try 2
## TODO: string concatenation
## NOTE: python3 translates the '+' operator to binary encodings that 
##	 concatenate the 3 different strings together to become the
##	 value of the greeting variable

name = "Yara"
greeting = "Hello from " + name + " ! Welcome to CS Summer Challenge :)"
print(greeting)

print(id(name))
print(id(greeting))
print(id(print))


# PL constructs:
## defining functions
## using variables inside defined functions

## try 3
## TODO: user-defined greet()
## NOTE: a custom function can be defined to be used; python3
##	 translates the function to a chunk of binary code in the
##	 full binary; this code knows the location of the 
##	 variable 'greeting' in the full binary
#
name = "Yara"
greeting = "Hello from " + name + " ! Welcome to CS Summer Challenge :)"

def greet():
	print(greeting)

greet()

print(id(name))
print(id(greeting))
print(id(print))
print(id(greet))


# PL constructs:
## program organization

## try 4
## NOTE: function must first be defined and interpreted, then it can be called

#name = "Yara"
#greeting = "Hello from " + name + " ! Welcome to CS Summer Challenge :)"
#
#greet()
#
#def greet():
#	print(greeting)


# PL constructs:
## defining a local variable inside a function
## returning value of local variable from a function

## try 5
## NOTE: understand using local variables; when translated to binary, the function
##	 binary encoding will have space reserved for a local variable, known only to
##	 this function, called sum; the value of this variable will be computed 
##	 by the function.
##	 understand returning values; returned values also have space reserved for them
##	 in the binary, however, they don't have names; hence, return values must be 
##	 captured by named variables if they are to be used - e.g. printed

num_1 = 5;
num_2 = 7;

def sum():
	sum = num_1 + num_2;
	return sum

my_sum = sum()
print("sum = ", my_sum)


# PL constructs:
## defining a function that expects parameters when it is called
## passing multiple parameters to a function

## try 6
## NOTE: understand parameter passing; when translated to binary, the function
##	 binary encoding will have space reserved for two parameters identified as
##	 x and y by the function; the code in the sum function will use the values
##	 of these two parameters 

num_1 = 5;
num_2 = 7;

def sum(x, y):
	sum = x + y;
	return sum

my_sum = sum(num_1, num_2)
print("sum = ", my_sum)



