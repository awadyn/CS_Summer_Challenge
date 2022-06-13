#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int list[5];
int median;
int median_index;


int print_list() {
	int i;
	for (i = 0; i < sizeof(list); i ++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}


int get_list() {
	printf("Enter 5 integers:\n");
	int num_inputs = scanf("%d %d %d %d %d", list, &list[1], &list[2], &list[3], &list[4]); 
	if ( num_inputs == 5) return 0;
	else return -1;
}



// NOTE: to insert, the list size should be incremented
//	unfortunately, the list variable is a 5-integer variable
//	and cannot be changed
// NOTE: hence we need to create a new larger list for every new input
void insert() {
	// NOTE: read new input
	int new_input;
	printf("Enter a new integer:\n");
	scanf("%d", &new_input);
		

	// NOTE: attempt 1, local variable list
	int new_list[sizeof(list) + 1];
	// copy all present elements
	int i;
	for (i = 0; i < sizeof(list); i ++) {
		new_list[i] = list[i];
	}
	// now add new input to end of list
	// note that the value of i = index of last element
	new_list[i] = new_input;
	// finally assign list to point to this new list
	// NOTE: compilation will fail here; we cannot do this
	//	because list is already a fixed symbol in this binary
	//	that is known to reference 5 consecutive integers
	list = new_list;
	// print to confirm
	print_list();
}


int my_sort_list() {
	int i, j, x, y;
	for (i = 1; i < sizeof(list); i ++) {
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
	median_index = (sizeof(list)/sizeof(int))/2;
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
