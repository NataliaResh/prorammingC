#include <stdio.h>
#include <string.h>

int isPalindrom(const char *str) {
	const char *start = str;
	const char *end = str + strlen(str) - 1;
	while (start != end) {
		while (start != end && *start == ' ') {
			start++;
		}
		while (end != start && *end == ' ') {
			end--;
		}
		if (end - start <= 0) {
			return 1;
		}
		if (*start != *end) {
			return 0;
		}
		start++;
		end--;
	}
	return 1;
}

int main() {
	char* str = "ab aa   b b a   a ba";
	printf("%d\n", isPalindrom(str));
	return 0;
}
