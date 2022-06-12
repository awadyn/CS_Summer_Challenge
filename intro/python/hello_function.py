## Learning Objectives:
## 
## Defining Functions
## NOTE The difference between 'user-defined' and 'system-defined' or 'language-defined' functions and variables. We, as users, make use of the latters, and create the former.
## Just like the print function that is defined in the Python language, we can define our own functions.
## A 'say_hello' function can be defined to always use the Python 'print' function to display a greeting.
##
## Intrpretation = line-by-line conversion of code to binary instructions
## User defined function 'say_hello' is first converted to executable binary instructions.
## Then, the call to this function is converted to executable binary instructions.
## Finally, the call executes.
##
## Variable Scope: Global Variables
## A variable can be defined in a function - local - or outside a function - global.
## Depending on how we need to use the variable, this choice is important.
##
## Exploring the memory location of user-defined functions and variables.
## Here we explore global variables and their memory location in the binary.


## try 0
## TODO: using user-defined functions
#def say_hello():
#	print("Hello from me! Welcome to CS Summer Challenge :)")
#
#say_hello()


## try 1
## TODO: function must first be defined and interpreted, then it can be called
## NOTE: observe error here
#say_hello()
#
#def say_hello():
#	print("Hello from me! Welcome to CS Summer Challenge :)")


## try 2
## TODO: defining a global variable that all functions can access
#name = "Yara"
#greeting = "Hello from " + name + " ! Welcome to CS Summer Challenge :)"
#
#def say_hello():
#	print(greeting)
#
#say_hello()


## try 3
## TODO: defining memory locations of user-defined instructions and data
name = "Yara"
greeting = "Hello from " + name + " ! Welcome to CS Summer Challenge :)"

def say_hello():
	print(greeting)

say_hello()
print(id(name))
print(id(greeting))
print(id(say_hello))

 
