#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int list[5];

//new
//int *list;

int median;
int median_index;


// NOTE: learn for loop
int print_list() {
	int i;
	for (i = 0; i < 5; i ++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}


int get_list() {
	printf("Enter 5 integers:\n");
	// new
//	list = (int*)malloc(5 * sizeof(int));
	int num_inputs = scanf("%d %d %d %d %d", list, &list[1], &list[2], &list[3], &list[4]); 
	if ( num_inputs == 5) return 0;
	else return -1;
}


int int_compare(const void *ptr_1, const void *ptr_2) {
	int a1 = *((int*) ptr_1);
	int a2 = *((int*) ptr_2);
	if (a1 <= a2) return 0;
	else return 1;
}

int search_index(int value) {
	int i;
	// NOTE: finding size of a list
	for (i = 0; i < sizeof(list)/sizeof(int); i ++) {
		// NOTE: find index within ascending list order
		if (value <= list[i]) {
			return i;
		}
	}
	return i;
}

// NOTE: start here after sort
int insert() {
	// NOTE local variable declaration
	int new_entry;
	printf("Enter a new integer:\n");
	scanf("%d", &new_entry);
	// NOTE search sorted list for correct index to place
	//	new element
	// NOTE local variable argument passing
	int new_index = search_index(new_entry);
	printf("Inserting %d at index %d\n", new_entry, new_index);	
	// NOTE: creating and initializing new list
	int new_size = sizeof(list)/sizeof(int) + 1;
	int new_list[new_size];
	printf("old list size: %ld\n", sizeof(list));
	printf("New list size: %ld\n", sizeof(new_list));
	int i;
	for (i = 0; i < new_index; i ++)
		new_list[i] = list[i];
	new_list[new_index] = new_entry;
	for (i = new_index + 1; i < sizeof(new_list)/sizeof(int); i ++)
		new_list[i] = list[i];

	// NOTE: reach bug here: cannot reassign
	//	 checking addrs, see how new list is local
	// 	 while old list is global
	printf("list address = %p\n", list);
	printf("new list address = %p\n", new_list);
	
	printf("New list: \n");
	// NOTE: reach end here, cannot move forward because cannot
	//	 change current list

	// GOTO: python implementation, see that list there
	// can be easily re-assigned
	// this is because in python, all objects are dynamically
	// allocated, that means they can change their memory location
	// at any time
	// hence, the old array can be ignored and the list variable
	// can reference a new array easily in python
	// in c, the symbols are created during compilation
	// --> remember the objdump and where we saw defined variables
	// the address of some variables is fixed, ex: global data
	// this is because these variables are statically allocated
	// --> space for them is reserved and maintained when
	// 	the binary is loaded to memory
	// to make them able to dynamically change their size, 
	// they must be dynamically allocated
	// --> this means that their location is dynamic,
	//	and their size is dynamic


//	print_list();

	// binary_search() -> return index to place new_entry
	// for loop to add elements, try going past array size, fail
	// create new array, cp all elements until index, copy index,
	//	copy all after index
	//
	// run and see print_list after just printing the old list
	// debug: problem is locally scoped list
	// no way to create global data
	// transition to dynamic data and parameter passing
	return 0;
}


// NOTE: start here after the code puzzle
//	 - learn for loop, nested for loop
//	 - using iterators
//	 - brainstorm sorting algorithm and implement
int my_sort_list() {
	print_list();

	int i, j, x, y;
	for (i = 1; i < 5; i ++) {
		x = list[i];
		for (j = i - 1; j >= 0; j--) {
			y = list[j];
			if (x < y) {
				list[j] = x;
				list[j+1] = y;
			}
			print_list();
		}
	}

	return 0;
}

int sort_list() {
	qsort(list, 5, sizeof(int), int_compare);
	return 0;
}


// NOTE: - compute median
//	 - learn data sizes
void get_median() {
	median_index = (sizeof(list)/sizeof(int))/2;
	median = list[median_index];
}


int main() {
	int rc = get_list();

	if (rc == 0) {
		printf("Successfully read integer list: ");
		print_list();
	} else printf("Unsuccessful list entry.\n");

	if ((rc = my_sort_list()) == 0) {
		printf("Successfully sorted list: "),
		print_list();
	} else printf("Unsuccessful list sort.\n");

	get_median();
	printf("\n Median: %d\n", median);
	
	insert();
	print_list();

	return 0;
}
