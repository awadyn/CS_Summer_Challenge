####################
# PL: Python
# PL translator: python3 interpreter
# To interpret and run this Python script:	python3 python_exercise.py
#
####################

# NOTE: 1) define a Python function that takes 2 parameters, num1 and num2,
#	   computes their sum, and returns the computed sum
# 	2) call that function and save its return value in a variable
#	3) display function return value



# TODO: def function_name(var1, var2):
#		<operation>
#		return <value>
#	variable = function_name(var1, var2)
#	print(variable)
#
#
# write your code below:
########################
x1 = 0			# global variable to store operand 1 of calculation
x2 = 0			# global variable to store operand 2 of calculation
result = 0		# global variable to store result of calculation


def get_input():
	global x1		# sometimes we have to declare using global variables in Python
	global x2

	print("Enter your first value:")
	input1 = input()
	# casting operation to change data type from string to integer
	x1 = int(input1)
	print("Enter your second value:")
	input2 = input()
	x2 = int(input2)



def add(x, y):
	sum = x + y
	return sum



## all needed functions have been defined above
## now we can call the functions as needed
#
# 1) call get_input() function to get user input
get_input()

# 2) call a calculation function and display result
result = add(x1, x2)
print(result)

