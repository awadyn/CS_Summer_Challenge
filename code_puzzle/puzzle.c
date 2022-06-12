#include <stdio.h>
#include <stdlib.h>

static int list[5];
static int median;
static int median_index;

int print_list() {
	int i;
	for (i = 0; i < 5; i ++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

int get_list() {
	printf("Enter 5 integers:\n");
	if (scanf("%d %d %d %d %d", list, list+1, list+2, list+3, list+4) == 5) return 0;
	else return -1;
}

int int_compare(const void *ptr_1, const void *ptr_2) {
	int a1 = *((int*) ptr_1);
	int a2 = *((int*) ptr_2);
	if (a1 <= a2) return 0;
	else return 1;
}

int sort_list() {
	qsort(list, 5, sizeof(int), int_compare);
	return 0;
}

void get_median() {
//	median_index = (sizeof(list)/sizeof(int))/2;
	median_index = 5/2;
	median = list[median_index];
}

int main() {
	int rc = get_list();

	if (rc == 0) {
		printf("Successfully read integer list: ");
		print_list();
	} else printf("Unsuccessful list entry.\n");

	if ((rc = sort_list()) == 0) {
		printf("Successfully sorted list: "),
		print_list();
	} else printf("Unsuccessful list sort.\n");

	get_median();
	printf("\n Median: %d\n", median);

	return 0;
}
