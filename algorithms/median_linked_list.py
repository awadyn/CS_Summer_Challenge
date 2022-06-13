# NOTE: parallel to typedef struct Node
#	--> this now allows us to initialize variables of type node
class Node:
	# all classes must have a function to initialize
	# class members called __init__
	#	--> think of this necessity like the necessity of
	#	main in C
	def __init__(self, value = None, next = None):
		self.value = value
		self.next = next

# NOTE: declaring global node_list
node_list = Node()

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


def print_node_list():
	global node_list

	tail = node_list
	while (tail != None):
		print(tail.value, " ", end='')
		tail = tail.next	
	print()


def convert_list():
	global node_list
	global int_list
	global list_size

	tail = node_list
	for i in range(0, list_size):
		tail.value = int_list[i]
		if (i != list_size - 1):
			tail.next = Node()
			tail = tail.next	


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
	global node_list
	global int_list
	global list_size

	tail = node_list
	index = None
	while (tail != None):
		if (value <= tail.value):
			return index
		index = tail
		tail = tail.next
	return index



def insert():
	global node_list
	global int_list
	global list_size

	print("Insert a new integer: ")
	new_entry = int(input())
	
	input_node = Node(new_entry, None)
	index_node = search_index(new_entry)

	if (index_node == None):
		input_node.next = node_list
		node_list = input_node
	else:
		input_node.next = index_node.next
		index_node.next = input_node

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

	convert_list()
	print("Node list = ")
	print_node_list()

	insert()
	print("New list  = ")
	print_node_list()

#	get_median()
#	print("Median = ", median)


main()



