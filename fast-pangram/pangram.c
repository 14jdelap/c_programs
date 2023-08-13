#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool ispangram(char *s) {
  // initialize an int array with elements of value 0
  int counter[26] = {0};
  for(int i = 0; i < strlen(s); ++i) {
    int charValue = (int)tolower(s[i]);
    if (charValue >= 97 && charValue <= 122) {
      counter[charValue-97] += 1;
    }
  }
  for(int i = 0; i < 26; ++i) {
    if (counter[i] == 0) {
        return false;
    }
  }
  return true;
}

int main() {
  size_t len;
  ssize_t read;
  char *line = NULL;
  while ((read = getline(&line, &len, stdin)) != -1) {
    if (ispangram(line))
      printf("%s", line);
  }

  if (ferror(stdin))
    fprintf(stderr, "Error reading from stdin");

  free(line);
  fprintf(stderr, "ok\n");
}
