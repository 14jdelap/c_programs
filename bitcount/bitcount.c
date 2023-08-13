#include <assert.h>
#include <stdio.h>

int64_t bitcount(int64_t i) {
  int64_t bitsOn = 0;
  while(i) {
    bitsOn += i&1;
    i >>= 1;
  }
  return bitsOn;
}

int main(int argc, char **argv) {
  assert(bitcount(0) == 0);
  assert(bitcount(1) == 1);
  assert(bitcount(2) == 1);
  assert(bitcount(3) == 2);
  assert(bitcount(4) == 1);
  assert(bitcount(5) == 2);
  assert(bitcount(6) == 2);
  assert(bitcount(7) == 3);
  assert(bitcount(8) == 1);
  assert(bitcount(9) == 2);
  assert(bitcount(10) == 2);
  assert(bitcount(11) == 3);
  assert(bitcount(12) == 2);
  assert(bitcount(13) == 3);
  assert(bitcount(14) == 3);
  assert(bitcount(15) == 4);
  assert(bitcount(0xffffffff) == 32);
  printf("OK\n");
}
