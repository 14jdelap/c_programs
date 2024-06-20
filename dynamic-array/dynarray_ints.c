#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STARTING_CAPACITY 8

/*
- Should be able to grow indefinitely
- Should have any data type -> stretch goal, requires the void data type
  - I.e. everything is an 8 byte pointer?

// void* are pointers to anything, which are 8 bytes
// void* is different from void, which says you aren't returning anything

Memory as 0 to a large number, where each cell is a byte
Memory is byte addresseable
A pointer is a location to a value
Strings are pointers where the end is the null byte '\0'
*/

typedef struct DA {
  int size;
  int capacity;
  int* array;  // If not pointer would need to create an array with a specific size
} DA;


DA* DA_new (void) {
  DA* arr = (DA*)malloc(sizeof(DA));
  if (arr == NULL) {
    // Handle memory allocation failure
    return NULL;
  }
  arr -> size = 0;
  arr -> capacity = STARTING_CAPACITY;
  arr -> array = (int*)malloc(STARTING_CAPACITY*sizeof(int));
  return arr;
}

int DA_size(DA *da) {
  return da -> size;
}

void DA_push (DA* da, int x) {
  if (da -> size == da -> capacity) {
    int old_capacity = da -> capacity;
    int new_capacity = old_capacity * old_capacity;
    int* new_array = (int*)realloc(da -> array, new_capacity*sizeof(int));

    da -> array = new_array;
    da -> capacity = new_capacity;
  }

  da -> array[da -> size] = x;
  da -> size ++;
}

int DA_pop(DA *da) {
  int current_size = da -> size;
  if (current_size == 0) {
    return -1;
  }

  int popped_value = *(da -> array + current_size-1);
  da -> size --;
  return popped_value;
}

void DA_set(DA* da, int x, int i) {
  if (da -> size < (i-1)) {
    return;
  }
  da -> array[i] = x;
}

int DA_get(DA *da, int i) {
  if (da -> size < (i-1)) {
    return -1;
  }
  return da -> array[i];
}


void DA_free(DA *da) {
  // TODO deallocate anything on the heap
}

int main() {
    DA* da = DA_new();

    assert(DA_size(da) == 0);

    // basic push and pop test
    int x = 5;
    int y = 6;
    DA_push(da, x);
    DA_push(da, y);
    assert(DA_size(da) == 2);

    assert(DA_pop(da) == y);
    assert(DA_size(da) == 1);

    assert(DA_pop(da) == x);
    assert(DA_size(da) == 0);
    assert(DA_pop(da) == -1);

    // basic set/get test
    DA_push(da, x);
    DA_set(da, y, 0);
    assert(DA_get(da, 0) == y);
    DA_pop(da);
    assert(DA_size(da) == 0);

    // expansion test
    DA *da2 = DA_new(); // use another DA to show it doesn't get overriden
    DA_push(da2, x);
    int i, n = 100 * STARTING_CAPACITY, arr[n];
    for (i = 0; i < n; i++) {
      arr[i] = i;
      DA_push(da, arr[i]);
    }
    assert(DA_size(da) == n);
    for (i = 0; i < n; i++) {
      assert(DA_get(da, i) == arr[i]);
    }
    for (; n; n--)
      DA_pop(da);
    assert(DA_size(da) == 0);
    assert(DA_pop(da2) == x); // this will fail if da doesn't expand

    DA_free(da);
    DA_free(da2);
    printf("OK\n");
}
