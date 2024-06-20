#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STARTING_CAPACITY 8

typedef struct DA {
  int length;
  int capacity;
  void** array;
} DA;


// DA_new allocates array for the struct and array in different expressions
// This will make it easier to resize the array independently of the struct
DA* DA_new (void) {
  DA* arr = (DA*)malloc(sizeof(DA));

  // Handle memory allocation failure
  if (arr == NULL) return NULL;

  arr -> length = 0;
  arr -> capacity = STARTING_CAPACITY;
  arr -> array = malloc(STARTING_CAPACITY*sizeof(void*));
  return arr;
}

void DA_free(DA *da) {
  free(da -> array);
  free(da);
  return;
}

int DA_size(DA *da) {
  return da -> length;
}

void DA_push (DA* da, void* x) {
  // If capacity is reached double before pushing
  if (da -> length == da -> capacity) {
    da -> capacity = 2 * da -> capacity;
    da -> array = realloc(da -> array, da -> capacity * sizeof(void*));
  }

  da -> array[da -> length++] = x;
}

void *DA_pop(DA *da) {
  if (da -> length == 0) return NULL;    // return NULL if length is 0
  return da -> array[--da -> length];
}

void DA_set(DA *da, void *x, int i) {
  if (da -> length < (i-1)) return;      // do not set if max length is less
  da -> array[i] = x;
}

void *DA_get(DA *da, int i) {
  if (da -> length < (i-1)) return NULL; // return NULL if max length is less
  return da -> array[i];
}

int main() {
    DA* da = DA_new();

    assert(DA_size(da) == 0);

    // basic push and pop test
    int x = 5;
    float y = 12.4;
    DA_push(da, &x);
    DA_push(da, &y);
    assert(DA_size(da) == 2);

    assert(DA_pop(da) == &y);
    assert(DA_size(da) == 1);

    assert(DA_pop(da) == &x);
    assert(DA_size(da) == 0);
    assert(DA_pop(da) == NULL);

    // basic set/get test
    DA_push(da, &x);
    DA_set(da, &y, 0);
    assert(DA_get(da, 0) == &y);
    DA_pop(da);
    assert(DA_size(da) == 0);

    // expansion test
    DA *da2 = DA_new(); // use another DA to show it doesn't get overriden
    DA_push(da2, &x);

    int i, n = 100 * STARTING_CAPACITY, arr[n];
    for (i = 0; i < n; i++) {
      arr[i] = i;
      DA_push(da, &arr[i]);
    }
    assert(DA_size(da) == n);
    for (i = 0; i < n; i++) {
      assert(DA_get(da, i) == &arr[i]);
    }
    for (; n; n--)
      DA_pop(da);
    assert(DA_size(da) == 0);
    assert(DA_pop(da2) == &x); // this will fail if da doesn't expand

    DA_free(da);
    DA_free(da2);
    printf("OK\n");
}
