#include <stdio.h>

// repeat prints the string n times, where
// n is an integer larger than 0
void repeat(char *s, int n) {
  if (n >= 1) {
    int i;
    for (i = 0; i < n; ++i) {
      printf("%s\n", s);
    }
  }
  return;
}

int main(int argc, char **argv) {
  char *s = "hello";
  repeat(s, -10);
  repeat(s, 1);
  repeat(s, 3);
}
