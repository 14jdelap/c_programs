#include <stdio.h>
#include <stdbool.h>

// odd takes an integer and returns true if it's odd, else false
bool odd(int i) {
  if (i % 2 == 0) {
    return false;
  }
  return true;
}

int main(int argc, char **argv) {
  printf("%d\n", odd(5) == true);
  printf("%d\n", odd(4)  == false);
  printf("%d\n", odd(0)  == false);
}
