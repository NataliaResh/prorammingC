#include <stdio.h>

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}
	
int main() {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("Before swap:\na = %d\nb = %d\n", a, b);
	swap(&a, &b);
	printf("After swap:\na = %d\nb = %d\n", a, b);
	return 0;
}