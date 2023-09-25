#include <stdio.h>
#include <stdlib.h>

void checkNull(void *ptr) {
	if (ptr == NULL) {
		printf("Out of memory!\n");
		exit(0);
	}
}

int* concat(int *arr1, size_t *len1, int *arr2, size_t *len2, size_t *newlen) {
	*newlen = (*len1) + (*len2);
	int *newarr = (int*) malloc(*newlen * sizeof(int));
	checkNull(newarr);
	for (size_t i = 0; i < *len1; i++) {
		newarr[i] = arr1[i];
	}
	for (size_t i = *len1; i < *newlen; i++) {
		newarr[i] = arr2[i - (*len1)];
	}
	return newarr;
}

int main() {
	size_t len1, len2;
	scanf("%zu", &len1);
	int *arr1 = (int*) malloc(len1 * sizeof(int));
	checkNull(arr1);
	for (size_t i = 0; i < len1; i++) {
		scanf("%d", &arr1[i]);
	}
	scanf("%zu", &len2);
	int *arr2 = (int*) malloc(len2 * sizeof(int));
	checkNull(arr2);
	for (size_t i = 0; i < len2; i++) {
		scanf("%d", &arr2[i]);
	}
	size_t newlen;
	int *newarr = concat(arr1, &len1, arr2, &len2, &newlen);
	for (size_t i = 0; i < newlen; i++) {
		printf("%d ", newarr[i]);
	}
	printf("\n");
	return 0;
}
