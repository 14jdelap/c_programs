// C library that has printf
#include <stdio.h>

// We need a main function to compile the program into an executable file
// By default the executable is called a.out

// int refers to the tight coupling between UNIX and C, where a return value of
// 0 means a normal execution and non-0 an abnormal execution of the function
int main(int argc, char **argv) {
  // Printf does not have a carriage return by default
  printf("Hello, world!\n");
}