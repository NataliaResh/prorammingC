#include <stdio.h>
#include <limits.h>

int a, b;

int main(){
	scanf("%d", &a);
	scanf("%d", &b);
	
	if (a >= 0 && INT_MAX - a >= b || a < 0 && INT_MIN - a <= b) {
		printf("a + b = %d\n", a + b);
	} else {
		printf("Addition error!\n");
	}
	if (b >= 0 && INT_MIN + b <= a || b < 0 && INT_MAX + b >= a) {
		printf("a - b = %d\n", a - b);
	} else {
		printf("Subtraction error!\n");
	}
	if (a >= 0 && b >= 0 && INT_MAX / b >= a || 
		a >= 0 && b < 0 && INT_MIN / b >= a ||
		a < 0 && b >= 0 && INT_MIN / a >= b ||
		a < 0 && b < 0 && INT_MAX / b <= a) {
		printf("a * b = %d\n", a * b);
	} else {
		printf("Multiplication error!\n");
	}
	if (b == 0){	
		printf("Division by zero!\n");
	} else if (a == INT_MIN && b == -1) {
		printf("Division error!\n");

	} else {
		printf("a / b = %d\n", a / b);
		printf("a %% b = %d\n", a % b);
	
	}

	printf("a == b = %d\n", a == b);
	printf("a != b = %d\n", a != b);
	printf("a > b = %d\n", a > b);
	printf("a >= b = %d\n", a >= b);
	printf("a < b = %d\n", a < b);
	printf("a <= b = %d\n", a <= b);

	printf("a && b = %d\n", a && b);
	printf("a || b = %d\n", a || b);
	printf("!a = %d\n", !a);

	printf("a & b = %d\n", a & b);
	printf("a | b = %d\n", a | b);
	printf("a ^ b = %d\n", a ^ b);
	printf("~a = %d\n", ~a);

	printf("a << b = %d\n", a << b);
	printf("a >> b = %d\n", a >> b);

	int c = 1 << 31;
	printf("c = %d\n", c);

	c--;
	printf("c = %d\n", c);

	//printf("c / 0 = %d", c / 0);
	
	return 0;
}
