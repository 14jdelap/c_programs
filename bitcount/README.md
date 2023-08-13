# Bitcount

Write a function that, given an integer, returns the bitcount (the number of bits that are on).

Examples

- `bitcount(0) == 0` because 0 is `00000000`
- `bitcount(1) == 1` because 1 is `00000001`
- `bitcount(2) == 1` because 2 is `00000010`
- `bitcount(3) == 2` because 3 is `00000011`
- `bitcount(4) == 1` because 4 is `00000100`
- `bitcount(5) == 2` because 5 is `00000101`
- `bitcount(6) == 2` because 6 is `00000110`
- `bitcount(7) == 3` because 7 is `00000111`
- `bitcount(8) == 1` because 8 is `000001000`
- `bitcount(9) == 2` because 9 is `000001001`
- `bitcount(10) == 2` because 10 is `000001010`
- `bitcount(11) == 3` because 11 is `000001011`
- `bitcount(12) == 2` because 12 is `000001100`
- `bitcount(13) == 3` because 13 is `000001101`
- `bitcount(14) == 3` because 14 is `000001110`
- `bitcount(15) == 4` because 15 is `000001111`
- `bitcount(0xffffffff) == 32` because 10 is `000001010`
  - 0xffffffff is 4 bytes fully on
    - Each pair of hex is a single byte
    - Eight hex values are thus two bytes
    - `0xf` means `1111`
    - Thus, `0xffffffff` means `1111` eight times, or 4 bytes of `0b11111111`
    - This means the result is 32 (`1 * 8 hex symbols * 4 bits per hex`)

Solution: probably with a bitwise operator?

Assumptions:

- Input: signed integer
- Treating the sign as part of the bit count

```go
func bitcount(i int64) int64 {
  // get the number of bits on by counting and shifting by the least significant bit
  // do a for loop while the integer variable is greater than 0
  // keep track of the number of bits on with a variable
  // get the last bit with a bitwise operation i & 1
  // since it's 0 or 1, it's safe to just add it
  var bitsOn int64
  for i > 0 {
    bitsOn += i & 1
    i >>= 1
  }
  return bitsOn
}
```

```c
#include <stdio.h>

int main(int argc, char **argv) {
  printf(bitcount(0 == 0))
  printf(bitcount(1) == 1)
  printf(bitcount(2) == 1)
  printf(bitcount(3) == 2)
  printf(bitcount(4) == 1)
  printf(bitcount(5) == 2)
  printf(bitcount(6) == 2)
  printf(bitcount(7) == 3)
  printf(bitcount(8) == 1)
  printf(bitcount(9) == 2)
  printf(bitcount(10) == 2)
  printf(bitcount(11) == 3)
  printf(bitcount(12) == 2)
  printf(bitcount(13) == 3)
  printf(bitcount(14) == 3)
  printf(bitcount(15) == 4)
  printf(bitcount(0xffffffff) == 32)
}

int bitcount(int i) {
  int bitsOn
  for (i > 0) {
    bitsOn += i&1
    i >>= 1
  }
  return bitsOn
}
``````
