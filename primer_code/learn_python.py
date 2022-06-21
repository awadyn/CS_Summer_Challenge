####################
# PL: Python
# PL translator: python3 interpreter
# To interpret and run this Python script:	python3 learn_python.py
#
####################
# Python constructs: functions (instructions) + variables (data)
#
#####################
# Python operations:
#    assignment:			variable = value
#					var = val1 +/-* val2
#    function call:			function(var1, var2, ...)
#    assignment to function output:	varX = func(var1, var2, ...)
#    function definition:		def function(var1, var2, ...):
#						<operation>
#						<operation>
#						...
#						return varX
#####################


# TODO: call a predefined Python function (e.g. "print")
#	--> function_name(function_parameters...)
print("Test 1")
print("Hello from Summer Challenge.")			# print function call
print()


# TODO: define a Python variable
#	--> variable_name = variable_value
# TODO: pass a variable to a function
#	--> function_name(variable_name)
print("Test 2")
year = "2022"						# string global variable
greeting = "Hello from Summer Challenge year .. "	# string global variable
print(greeting, year)					# parameter passing
print()


# TODO: use Python basic operations (e.g. string concatenation)
#	--> variable_name = string_1 + string_2
print("Test 3")
full_greeting = greeting + year			# string concatenation operation
print(full_greeting)
print()


# TODO: define a new Python function (e.g. "greet")
print("Test 4")
def greet():
	print(full_greeting)
greet()
print()


# TODO: define a new parametrized Python function (e.g. "greet_year")
print("Test 5")
def greet(my_parameter):
	print(my_parameter)
greet(full_greeting)				# use global variable as function parameter
print()



