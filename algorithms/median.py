int_list = [0] * 5
median = 0
median_index = 0

def get_list():
	# NOTE: need to declare global sometimes
	global int_list

	print("Enter 5 integers: ")
	str_list = input().split()
	# NOTE: learning for loop syntax
	#	--> learning range function
	for i in range(0, 5):
		int_list[i] = int(str_list[i])

def print_list():
	global int_list
	# NOTE: python print function supports list printing
	print(int_list)


def sort_list():
	global int_list

	# NOTE: basic sorting algorithm	
	print("Sorting input list ...")
	for i in range(1, 5):
		x = int_list[i]
		for j in range(i - 1, -1, -1):
			y = int_list[j]
			if (x < y):
				int_list[j] = x
				int_list[j + 1] = y
			print_list()
	

def get_median():
	global median
	global median_index

	median_index = int(len(int_list)/2)
	median = int_list[median_index]


def main():
	get_list()
	print("Input list = ")
	print_list()
	sort_list()
	print("Sorted list = ")
	print_list()
	get_median()
	print("Median = ", median)


main()



