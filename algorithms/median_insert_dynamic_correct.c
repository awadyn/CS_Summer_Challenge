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
