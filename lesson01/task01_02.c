#include <stdio.h>

int a, b;

int main(){
	scanf("%d", &a);
	scanf("%d", &b);
	
	printf("a + b = %d\n", a + b);
	printf("a - b = %d\n", a - b);
	printf("a * b = %d\n", a * b);
	printf("a / b = %d\n", a / b);
	printf("a %% b = %d\n", a % b);

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

	printf("c / 0 = %d", c / 0);
	
	return 0;
}

