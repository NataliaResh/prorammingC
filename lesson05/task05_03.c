#include <stdio.h>
#include <stddef.h>

int foo(char* start) {
	char end;
	printf("\x1BM");
	printf("%td\n", (ptrdiff_t)(start - &end));
	foo(start);
}

int main() {
	char start;
	foo(&start);
	return 0;
}
