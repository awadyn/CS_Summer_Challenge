# NOTE: everything is easier in python for one main reason
#	--> every variable in python is a dynamic one
#	and can be reassigned dynamically
# NOTE: in python, a variable is just a name/id
#	--> it is not tied to a data type or even a memory location

# NOTE: this statement creates a dynamic list object
#	--> this is identical to creating a pointer to data of a certain
#	type in C
int_list = []

# new list_size
list_size = 0

median = 0
median_index = 0



# NOTE: the fact that all variables in python are dynamically allocated
#	is a reason why we have to declare global scope
#	if we want to use and update variables globally
def get_list():
	global int_list
	global list_size

	print("Enter 5 integers: ")
	str_list = input().split()
	# new list_size
	list_size = len(str_list)
	for i in range(0, list_size):
		# NOTE: append() function acts like malloc in C
		#	--> it dynamically allocates a new integer
		#	variable and adds it to the chunk of memory
		#	pointed to by int_list
		# NOTE: append() does malloc, then casts to data type,
		#	then updates the value of allocated memory
		#	to the parameter value
		int_list.append(int(str_list[i]))


def print_list():
	global int_list
	print(int_list)


def sort_list():
	global int_list
	global list_size

	print("Sorting input list ...")
	# new list_size
	for i in range(1, list_size):
		x = int_list[i]
		for j in range(i - 1, -1, -1):
			y = int_list[j]
			if (x < y):
				int_list[j] = x
				int_list[j + 1] = y
			print_list()


def insert():
	global int_list
	global list_size

	print("Insert a new integer: ")
	new_entry = int(input())

	# NOTE: can append without explicitely allocating a larger
	#	array; the implementation of append() function 
	#	already does that
	int_list.append(new_entry)
	list_size = list_size + 1

	# NOTE: sort list will fail without new list size
	sort_list()
	

def get_median():
	global median
	global median_index
	global list_size

	median_index = int(list_size/2)
	median = int_list[median_index]


def main():
	get_list()
	print("Input list = ")
	print_list()

	sort_list()
	print("Sorted list = ")
	print_list()

	insert()
	print("New list  = ")
	print_list()

	get_median()
	print("Median = ", median)


main()



