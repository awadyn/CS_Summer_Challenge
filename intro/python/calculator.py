## Learning Objectives:
#
#
#
# User interaction: reading input from user
# Conditional control flow operators: if/else


##############
num_1 = 0
num_2 = 0
operator = ''
result = 0

def add(x, y):
	sum = x + y
	return sum

def calculate():
	print("Enter your first parameter:")
	# NOTE: calling predefined input function
	num_1 = input()
	print("Enter your operator:")
	operator = input()
	print("Enter your second parameter:")
	num_2 = input()

	# NOTE: using if/else conditional construct
	# NOTE: using conditional operator ==
	# NOTE: conditional operators return a value, True or False,
	#	depending on how the expression evaluates
	if (operator == '+'):
		result = add(num_1, num_2)
	
	## testing
	print(num_1, operator, num_2, " = ", result)

#calculate()


### run and observe error as num_1 and num_2 are treated as ASCII strings 
### they were just concatenated as we have seen before

### the importance of data types
# though we are not forced to define them in python as we are in C,
# it is important to know the type of data you are dealing with
# in order for your code to run correctly

### here, as a user, i can only input ASCII text that i understand to the
# running program; the program itself should convert my ASCII text to 
# numeric data
# luckily, functions that do this already exist, and we can use them
# these functions are called casting functions; they convert the binary encoding
# of their parameters from one format to another.
## NOTE remember in the end of C we saw hexadecimal rep of binary encoding of 
##	both ascii strings and integers

def calculate():
	print("Enter your first parameter:")
	num_1_str = input()
	# NOTE casting/type conversion
	num_1 = int(num_1_str)
	print("Enter your operator:")
	operator = input()
	print("Enter your second parameter:")
	num_2_str = input()
	# NOTE casting/type conversion
	num_2 = int(num_2_str)

	if (operator == '+'):
		result = add(num_1, num_2)
	
	## testing
	print(num_1, operator, num_2, " = ", result)

#calculate()


## go to C and see binary, hex, integer, and character representations in GDB
## continue calculate function

def subtract(x, y):
	diff = x - y
	return diff

def multiply(x, y):
	product = x * y
	return product

def divide(x, y):
	quotient = x / y
	return quotient


def calculate():
	print("Enter your first parameter:")
	num_1_str = input()
	num_1 = int(num_1_str)
	print("Enter your operator:")
	operator = input()
	print("Enter your second parameter:")
	num_2_str = input()
	num_2 = int(num_2_str)

	# NOTE: nesting if/else structure
	#	understand nesting syntactically and semantically
	if (operator == '+'):
		result = add(num_1, num_2)
	else: 
		if (operator == '-'):
			result = subtract(num_1, num_2)
		else: 
			if (operator == '*'):
				result = multiply(num_1, num_2)
			else:
				if (operator == '/'):
					result = divide(num_1, num_2)

	## testing
	print(num_1, operator, num_2, " = ", result)

calculate()


### all runs well
### error handling?





