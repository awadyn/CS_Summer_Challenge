## Learning Objectives:
## 
## Code = data + instructions
## A code file has variables and functions. Functions can use variables.
## Our code file is written in Python. It uses a 'print' function that prints a 'string'. A string is a sequence of characters.
## A variable 'greeting' can be used to store a string. Then, the print function can print this variable.
##
## Execution = operation of written code
## A Python code file is converted to a runnable binary code by the python3 interpreter s/w.
## In the runnable binary code, each function has a unique address/id, and each variable has a unique address/id.
## For a binary code to run, it is copied to memory.
## When in memory, the processor/cpu can locate the functions and variables it needs through their unique memory addresses.




## try 0
## TODO: using predefined functions
#print("Hello from me! Welcome to CS Summer Challenge :)")

## try 1
## TODO: variables - regions of memory that hold chunks of data 
#greeting = "Hello from me! Welcome to CS Summer Challenge :)"
#print(greeting)

## try 2
## TODO: addresses - each variable exists in a unique memory location 
#greeting = "Hello from me! Welcome to CS Summer Challenge :)"
#print(id(greeting))
#print(greeting)

## try 3
## TODO: string variables, concatenation
## NOTE: addresses change every run, explaining the dynamic allocation of available memory rather than static allocation of pre-defined memory regions
name = "Yara"
greeting = "Hello from " + name + " ! Welcome to CS Summer Challenge :)"
print("'name'     exists at address = ", id(name), " in memory.")
print("'greeting' exists at address = ", id(greeting), " in memory.")
print(greeting)
