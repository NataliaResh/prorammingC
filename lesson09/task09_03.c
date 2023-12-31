#include <stdio.h>
#include <stdlib.h>

void checkNull(void *ptr) {
	if (ptr == NULL) {
		printf("Out of memory!\n");
		exit(0);
	}
}

int* findSubArr(int *arr1, size_t len1, int *arr2, size_t len2) {
	size_t start = 0, i = 0;
	while (start + len2 <= len1) {
		if (i == len2) {
			return &(arr1[start]);
		}
		if (arr1[start + i] == arr2[i]) {
			i++;
		} else {
			i = 0;
			start = start + 1;
		}
	}
	return NULL;
}

int* removeSubArr(int *arr1, size_t *len1, int *arr2, size_t len2) {
	int *start = findSubArr(arr1, *len1, arr2, len2);
	while (start != NULL) {
		for (size_t i = (start - arr1) + len2; i < *len1; i++) {
			arr1[i - len2] = arr1[i];
		}
		*len1 = *len1 - len2;
		arr1 = realloc(arr1, (*len1) * sizeof(int));
    checkNull(arr1);
		start = findSubArr(arr1, *len1, arr2, len2);
	}
  return arr1;
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
	arr1 = removeSubArr(arr1, &len1, arr2, len2);
	for (size_t i = 0; i < len1; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
	free(arr1);
	return 0;
}
