#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


// NOTE
// now, list is just a pointer to integers
//	list size is not known
int *list;

// NOTE
// must save dynamic list size
int list_size;

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
	printf("Enter 5 integers:\n");
	// new
	list = (int*)malloc(5 * sizeof(int));
	int num_inputs = scanf("%d %d %d %d %d", list, &list[1], &list[2], &list[3], &list[4]); 

	// new list_size
	list_size = num_inputs;

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
	for (i = 0; i < list_size; i ++) {
		if (value <= list[i]) {
			return i;
		}
	}
	return i;
}

int insert() {
	int new_entry;
	printf("Enter a new integer:\n");
	scanf("%d", &new_entry);

	int new_index = search_index(new_entry);
	printf("Inserting %d at index %d ...\n", new_entry, new_index);	

	list_size = list_size + 1;
	
	// new NOTE needing dynamic memory allocation for new list
	//	to maintain new list values after function terminates
	int* new_list = (int*)malloc(list_size * sizeof(int));

	int i;
	for (i = 0; i < new_index; i ++)
		new_list[i] = list[i];
	new_list[new_index] = new_entry;
	for (i = new_index + 1; i < list_size; i ++)
		new_list[i] = list[i-1];

	printf("list address = %p\n", list);
	// new
	// NOTE heap address
	printf("new list address = %p\n", new_list);

	list = new_list;
	
	printf("New list: \n");
	print_list();
	
	return 0;
}


int my_sort_list() {
	print_list();

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

int sort_list() {
	qsort(list, list_size, sizeof(int), int_compare);
	return 0;
}


void get_median() {
	median_index = list_size/2;
	median = list[median_index];
}


int main() {
	int rc = get_list();

	if (rc == 0) {
		printf("Successfully read integer list: ");
		print_list();
		// NOTE different between value of list and &list
		printf("Address of list pointer variable = %p\n", &list);
		printf("Address of list elements: %p\n", list);
	} else printf("Unsuccessful list entry.\n");


	if ((rc = my_sort_list()) == 0) {
		printf("Successfully sorted list: "),
		print_list();
	} else printf("Unsuccessful list sort.\n");

	get_median();
	printf("\n Median: %d\n", median);
	
	insert();
	printf("New list: \n");
	// NOTE: see error here
	// --> local stack list is deleted after function terminates
	// GOTO: using global/heap variables for new list
	// then GOTO: not needing a new list: linked list
	print_list();

	get_median();
	printf("\n Median: %d\n", median);
	

	return 0;
}
