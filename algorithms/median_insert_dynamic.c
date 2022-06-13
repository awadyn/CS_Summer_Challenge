#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// NOTE: converting list from a statically assigned array of 5 integers
//	into a pointer to one or more integers
// NOTE: little else will need to change in the code, because a pointer
//	to integer data and an array of integers have the same syntax
//	--> the only difference is their data type and hence
//		how the compiler allocates regions in the binary code
//		for an array versus a pointer to a chunk of data
int *list;
// NOTE: add list_size variable, since list size is no longer a fixed value
int list_size = 0;
int median;
int median_index;


int print_list() {
	int i;
	// NOTE: need to remove sizeof(list)
	//	because list is now a pointer variable, not an array
	//	and sizeof() function will treat it as such
	for (i = 0; i < list_size; i ++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}


int get_list() {
	// NOTE: first, allocate a list of 5 integers
	//	--> malloc is a function that allocates as many memory
	//	chunks of fixed size as you need
	//	--> malloc returns the address of this allocated memory
	//	--> malloc does not understand the type of the data it
	//	allocates, hence the returned pointer value must be casted
	//	to the correct pointer type
	//		--> this way, the pointer to a chunk of integers
	//		can be treated like an array of integers
	//		because pointer type + size = array
	list = (int *)malloc(5 * sizeof(int));
	printf("Enter 5 integers:\n");

	// NOTE: syntax does not change, pointer to 5 integers 
	//	is the same as an array of 5 integers
	int num_inputs = scanf("%d %d %d %d %d", list, &list[1], &list[2], &list[3], &list[4]); 

	// NOTE new 
	list_size = num_inputs;
	if ( num_inputs == 5) return 0;
	else return -1;
}



// NOTE: understanding why insert() failed previously
//	--> arrays cannot be re-assigned
//	--> however, pointers can be reassigned
//		here we will use pointers to reference regions of memory
//		that we allocate ourselves
//	--> this is called dynamic allocation, unlike the static
//		allocation that happens when we specify our data types
//		and sizes in our code, forcing them to become immutable
//	--> using dynamic allocation, memory regions can be allocated
//		and referenced by many different pointers
// NOTE: understand how variables and variable names are tied to 
//	their allocated memory
//	--> array variable is tied to the chunk of array memory
//	--> pointer variable is only tied to chunk of pointer memory
//		--> it is not tied to whatever its address value
//		points to
void insert() {
	int new_input;
	printf("Enter a new integer:\n");
	scanf("%d", &new_input);
		

	// NOTE: attempt 2, reassign list pointer to local new_list
	int new_list[list_size + 1];
	int i;
	for (i = 0; i < list_size; i ++) {
		new_list[i] = list[i];
	}
	new_list[i] = new_input;
	// finally assign list to point to this new list
	list = new_list;
	list_size = list_size + 1;

	// NOTE: compilation does not fail
	// 	but program produces error
	//	--> list looks complete but get_median is going crazy
	// NOTE: now we must understand that this is because the local
	//	variable new_list disappears when this function terminates
	//	--> so whatever list was pointing to has disappeared
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


void get_median() {
	// NOTE: print list to confirm new error
	printf("get_median sees list = \n");
	print_list();

	// NOTE: change index computation
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
