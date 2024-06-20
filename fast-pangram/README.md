# Pangram

A pangram is a sentence that has every character a to z represented at least once.

Given `cases.txt` as input detect which sentences are pangran and output the pangran sentences.

Objective: Write a C version of the Python pangram function that runs in 5ms or less.

Some info:

- char pointer is the closest to a string type in C
- this is an address where the string starts
- to get the value we need to dereference the pointer
- increase until you get to a null byte, which marks the end of the string

## Examples

- Why shouldn’t a quixotic Kazakh vampire jog barefoot?
- Fox dwarves chop my talking quiz job.
- Woven silk pyjamas exchanged for blue quartz.

## Algorithm

- Create a fixed-length array of size 26
  - Key: 0 to 25
  - Value: int with number of cases the character is found in the string
- Iterate over the string
  - Get the lowercase of the current element with `tolower`
  - If the element is a character, add its equivalent position in the array +1

```c
bool pangram(char *s) {
  int register[26];
  for(i = 0; i < strlen(s); ++i) {
    printf(s[i])
  }
}
```

Better solution: use bitwise operators

- Use a bitset instead of an array to keep track of the result
- Use bit shifting to insert the bit in the right position (from positions 0 to 25)

```c
bool ispangram(char *s) {
  uint32_t bitset = 0;
  for(int i = 0; i < strlen(s); ++i) {
    int charValue = (int)tolower(s[i]);
    if (charValue >= 97 && charValue <= 122) {
        bitset |= (charValue-96);
    }
  }
  if (bitset == 0x03ffffff) {
    return true;
  }
  return false;
}
```
