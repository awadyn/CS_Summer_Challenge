# NOTE: inspired by needing to avoid unnecessary computation
#	--> there is no need to resort an already sorted list each time
#	--> this can be done by inserting a new element in the right 
#	place
# NOTE: for that, the right position must be searched for
#	--> we will implement this search as a simple linear search
# 	--> the trick is how to recreate the list when the new input
#	belongs somewhere in the middle of the list
int_list = []
list_size = 0
median = 0
median_index = 0



def get_list():
	global int_list
	global list_size

	print("Enter 5 integers: ")
	str_list = input().split()
	# new list_size
	list_size = len(str_list)
	for i in range(0, list_size):
		int_list.append(int(str_list[i]))


def print_list():
	global int_list
	print(int_list)


def sort_list():
	global int_list
	global list_size

	print("Sorting input list ...")
	for i in range(1, list_size):
		x = int_list[i]
		for j in range(i - 1, -1, -1):
			y = int_list[j]
			if (x < y):
				int_list[j] = x
				int_list[j + 1] = y
			print_list()


# NOTE: simple linear search
def search_index(value):
	global int_list
	global list_size

	for i in range(0, list_size):
		# if the new input is lower in value
		# insert it at this index
		if (value <= int_list[i]):
			return i
	# if the new input is higher in value than all other inputs
	# insert it at the end of the list
	return list_size



# NOTE: we will search for the right location
#	then use temporary variables to store parts of the list
#	then reassign the global list to the consecutive parts
def insert():
	global int_list
	global list_size

	print("Insert a new integer: ")
	new_entry = int(input())

	input_index = search_index(new_entry)
	print("Inserting integer at index ", input_index, " ...")

	# if new input is higher than all others
	# append to end of list
	if (input_index == list_size):
		int_list.append(new_entry)
	else:
		# otherwise, grab lower values
		lower = int_list[0:input_index]
		# append new input to them
		lower.append(new_entry)
		# then extend list with higher values
		higher = int_list[input_index:]
		int_list = lower
		int_list.extend(higher)

	list_size = list_size + 1



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



