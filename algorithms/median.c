#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int list[5];
int median;
int median_index;



// NOTE: learn for loop
// NOTE: sizeof() function
void print_list() {
	int i;
	for (i = 0; i < sizeof(list); i ++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}



void get_list() {
	printf("Enter 5 integers:\n");
	int num_inputs = scanf("%d %d %d %d %d", list, &list[1], &list[2], &list[3], &list[4]); 
}



// NOTE: start here after the code puzzle
//	 - learn for loop, nested for loop
//	 - using iterators
//	 - brainstorm sorting algorithm and implement
int my_sort_list() {
	print_list();

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


// NOTE: - compute median
//	 - learn data sizes
void get_median() {
	median_index = (sizeof(list)/sizeof(int))/2;
	median = list[median_index];
}


int main() {
	get_list();
	printf("Successfully read integer list: ");
	print_list();

	sort_list();
	printf("Successfully sorted list: "),
	print_list();

	get_median();
	printf("\n Median: %d\n", median);
	
	return 0;
}
