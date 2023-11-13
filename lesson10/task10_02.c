#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkNull(void *ptr) {
  if (ptr == NULL) {
    printf("Out of memory\n");
  exit(0);
  }
}

char* trim(const char* str) {
  size_t start = 0, end = strlen(str) - 1;
  while (start < strlen(str) && str[start] == ' ') {
    start++;
  }
  if (start == strlen(str)) {
    return NULL;
  }
  while (end >= 0 && str[end] == ' ') {
    end--;
  }
  char* newstr = (char*)malloc(sizeof(char) * (end - start + 2));
  for (size_t i = start; i <= end; i++) {
    newstr[i - start] = str[i];
  }
  newstr[end - start + 1] = '\0';
  return newstr;
}

int main() {
  char* str = "  aaaa a aa  ";
  printf("%s\n", str);
  char* newstr = trim(str);
  printf("%s\n", newstr);
  free(newstr);
  return 0;
}
