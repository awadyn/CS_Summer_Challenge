#include <stdio.h>

int x1;
int x2;
int result;

int add(int x, int y) {
	int sum = x + y;
	return sum;
}

void calculate() {
	printf("Enter your first parameter:\n");
	scanf("%d", &x1);
	printf("Enter your second parameter:\n");
	scanf("%d", &x2);

	if (operator == '+') {
		result = add(x1, x2);
	}
}

int main() {
	calculate();

	printf("%d + %d = %d\n", x1, x2, result);

	return 0;
}






