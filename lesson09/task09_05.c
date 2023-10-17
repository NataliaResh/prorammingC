#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void checkNull(void *ptr) {
	if (ptr == NULL) {
		printf("Out of memory\n");
		exit(0);
	}
}

int* scanArr(size_t *size, size_t *capasity) {
	*capasity = 1;
	*size = 0;
	int* arr = (int*) malloc(*capasity * sizeof(int));
	checkNull(arr);
	do {
		scanf("%d", &arr[*size]);
		(*size)++;
		if (*size == *capasity) {
			*capasity *= 2;
			arr = (int*) realloc(arr, *capasity * sizeof(int));
			checkNull(arr);
		}
	} while (arr[*size - 1] != 0);
	(*size)--;
	return arr;
}

void printArr(int *arr, size_t len) {
	for (size_t i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	size_t size = 0, capasity = 1;
	int* arr = scanArr(&size, &capasity);

	printf("Array:\n");
	printArr(arr, size);
	printf("Size = %zu, capasity = %zu\n", size, capasity);
	free(arr);	
	return 0;
}

