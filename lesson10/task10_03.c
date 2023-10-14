#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void checkNull(void *ptr) {
	if (ptr == NULL) {
		printf("Out of memory\n");
		exit(0);
	}
}

char** split(const char* str, size_t *size, size_t *capasity) {
	*size = 0;
	*capasity = 1;
	char **arr_split = (char**)malloc(*(capasity) * sizeof(char*));
	checkNull(arr_split);
	for (const char *start = str; *start != '\0'; start++) {
		if (*start == ' ') {
			continue;
		}
		const char *end = start;
		while (*end != ' ' && end != 0) {
			end++;
		}
		if (*size >= *capasity) {
			*capasity = (*capasity) * 2;
			arr_split = (char**)realloc(arr_split, *capasity * sizeof(char*));
			checkNull(arr_split);
		}
		arr_split[*size] = (char*)malloc(((end - start) + 1) * sizeof(char));
		checkNull(arr_split[*size]);
		for (const char* i = start; i != end; i++) {
			arr_split[*size][i - start] = *i;
		}
		*size = *size + 1;
		start = end;
	}
	return arr_split;
}

int main() {
	const char *str = "    adsf dsfd safas dfghfkfg     h";
	size_t size = 0, capasity = 0;
	char **str_split = split(str, &size, &capasity);
	for (size_t i = 0; i < size; i++) {
		printf("%s\n", str_split[i]);
	}
	for (size_t i = 0; i < size; i++) {
		free(str_split[i]);
	}
	free(str_split);
	return 0;
}
