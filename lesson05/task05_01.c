#include <stdio.h>

void bar() {
	int n;
	printf("Corrent adress of n: %p\n", &n);
}
void foo() {
	bar();
}

int main() {
	foo();
	bar();
}
