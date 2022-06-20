class Node:
	def __init__(self, value = None, left = None, right = None):
		self.value = value
		self.left = left
		self.right = right

# NOTE: declaring global node_tree
node_tree = Node()

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


def print_branches(root, depth):
	if (root.left == None):
		for i in range(0, depth * 3):
			print(" ", end='')

		print(" / ", end='')
		return
	else:
		for i in range(0, depth *3):
			print(" ", end='')
		print(" / " , root.left.value, " ", end='')

	if (root.right == None):
		for i in range(0, depth * 3):
			print(" ", end='')

		print(" \ ", end='')
		return
	else:
		for i in range(0, depth * 3):
			print(" ", end='')

		print(root.right.value, " \ ", end='')

	print()
	print_branches(root.left, depth - 1)
	print_branches(root.right, depth - 1)



def print_node_tree():
	global node_tree

	import math
	depth = int(math.log2(list_size))

	for i in range(0, depth * 3):
		print(" ", end='')

	print(" / ", node_tree.value, " \ ", end='')
	print()

	print_branches(node_tree, depth - 1)
	print()

def print_tree_level(root, level, height):
	if (root == None):
		print("  ", end='')
		return
	# print root of this level
	if (level == 1):
		print(root.value, end='')
	elif (level > 1):
		print_tree_level(root.left, level-1, height-1)
		for j in range(0, 2**(height + 1 - level) - 1):
			print("  ", end='')
		print_tree_level(root.right, level-1, height-1)

def print_tree_temp(root):
	global list_size

	import math
	depth = int(math.log2(list_size))
	height = depth + 1
	print("depth = ", depth)
	print("height = ", height)

	for i in range(1, height + 1):
		for j in range(0, 2**(height - i) - 1):
			print("  ", end='')
		print_tree_level(root, i, height)
		print()


# recursive thinking, divide and conquer the problem
# each time dividing the list in half to convert it
# until we reach a list of size 1
# NOTE: root variable is new in every recursion stack frame
def convert_to_bst(sorted_list):
	n = len(sorted_list)

	if (n == 0):
		return None

	# NOTE: initialize root of this sorted_list
	root = Node()
	root.value = sorted_list[int(n/2)]

	# NOTE: this is a leaf node
	# all calls to this function will return here and assign
	# leaf nodes correctly - prior root left or right
	if (n == 1):
		return root;
	else:
		left_list = sorted_list[0 : int(n/2)]
		right_list = sorted_list[int(n/2) + 1 :]
		root.left = convert_to_bst(left_list)
		root.right = convert_to_bst(right_list)
		return root



def convert_list():
	global node_tree
	global int_list
	global list_size

	node_tree.value = int_list[int(list_size / 2)]

	node_tree.left = convert_to_bst(int_list[0 : int(list_size/2)])
	node_tree.right = convert_to_bst(int_list[int(list_size/2) + 1 :])



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
	print("Node tree = ")
#	print_node_tree()
#	print(node_tree.value, " : ")
#		if (root.left != None):
#			print(root.left.value, " : ", end='')
#			if (root.right != None):
#				print(root.right.value)
	print_tree_temp(node_tree)	

#	insert()
#	print("New list  = ")
#	print_node_list()

#	get_median()
#	print("Median = ", median)


main()



