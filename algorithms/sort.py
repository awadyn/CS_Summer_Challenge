int_list = [-12, -1, 14, 33, 89]


# NOTE: think of pseudo code
#	for each list entry after the first, compare to all entries before it
#		if it is less than any, swap them
def sort():
	print(int_list)

	# NOTE: for loops, using an iterator
	for i in range(1, 5):

		x = int_list[i]
		for j in range(i - 1, -1, -1):
			y = int_list[j]
			if x < y:
				int_list[j] = x
				int_list[j+1] = y
			print(int_list)

sort()

#TODO integrate into puzzle code

# NOTE: think of pseudocode first
#	for each new entry, insert into sorted list, increasing
#	array size by 1

# NOTE: newly entered value is not a global variable
#	argument passing of local variables
def search_index(value):
	global int_list
	# NOTE: no more const range, using variable list length
	for i in range(0, len(int_list)):
		if(value <= int_list[i]):
			return i
	# NOTE: base case, if new value is the largest, append it to
	#	end of list
	return len(int_list)
	

def insert():
	# NOTE: needing this because python automatically
	#	makes all variables local to the current scope
	global int_list

	print("Before insert: ", int_list)
	print("Insert a new integer:")
	new_entry = int(input())

	# NOTE: must search for placement index
	#	to maintain order of sorted list
	new_index = search_index(new_entry)

	print("Inserting ", new_entry, " at index ", new_index)
	# NOTE: recreating the list
	#	must create a new empty list of the right size
	#	then copy elements in correct sorted order to it
	new_int_list = [0] * (len(int_list) + 1)
	new_int_list[0:new_index] = int_list[0:new_index]
	print(new_int_list)
	new_int_list[new_index] = new_entry
	new_int_list[new_index+1:] = int_list[new_index:]
	int_list = new_int_list
	print("After insert: ", int_list)
	print(id(new_int_list))
	print(id(int_list))

insert()




