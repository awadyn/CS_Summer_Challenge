#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int *list;
int list_size = 0;
int median;
int median_index;


int print_list() {
	int i;
	for (i = 0; i < list_size; i ++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}


int get_list() {
	list = (int *)malloc(5 * sizeof(int));
	printf("Enter 5 integers:\n");
	int num_inputs = scanf("%d %d %d %d %d", list, &list[1], &list[2], &list[3], &list[4]); 
	list_size = num_inputs;
	if ( num_inputs == 5) return 0;
	else return -1;
}


// NOTE: nothing changes here
//	--> more reason to understand and use pointers
int my_sort_list() {
	int i, j, x, y;
	for (i = 1; i < list_size; i ++) {
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

/*
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
*/


// NOTE: understanding why get_median() failed previously
//	--> the new list in memory that list variable was assigned
//	to point to disappeared after insert() function terminated
// NOTE: need to use dynamic memory for this new list
//	--> dynamic memory does not disappear unless the programmer
//	frees it
// NOTE: this is why the list in get_list() did not disappear
//	even after get_list() terminated
void insert() {
	int new_input;
	printf("Enter a new integer:\n");
	scanf("%d", &new_input);
		

	// NOTE: attempt 3, reassign list pointer to global new_list
	int *new_list = (int *)malloc((list_size + 1) * sizeof(int));
	int i;
	for (i = 0; i < list_size; i ++) {
		new_list[i] = list[i];
	}
	new_list[i] = new_input;

	list = new_list;
	list_size = list_size + 1;

	// NOTE: Success
	// now sort list to make sure get_median() succeeds
	my_sort_list();
}

/*// NOTE: start here after sort
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
	
	list = new_list;

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
*/



void get_median() {
	median_index = list_size/2;
	median = list[median_index];
}


int main() {
	get_list();
	printf("Successfully read integer list: ");
	print_list();

	my_sort_list();
	printf("Successfully sorted list: "),
	print_list();

	insert();
	printf("Successfully inserted to list: "),
	print_list();

	get_median();
	printf("\n Median: %d\n", median);
	

	return 0;
}
