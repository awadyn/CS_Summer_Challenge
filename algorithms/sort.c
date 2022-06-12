#include <stdio.h>

int list[] = {14, -12, 33, 89, -1};

void print_list() {
	int i;
	for (i = 0; i < 5; i ++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

int sort() {
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
}


int main() {
	sort();
	return 0;
}
