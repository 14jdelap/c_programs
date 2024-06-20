#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STARTING_CAPACITY 8

typedef struct DA {
  int size;
  int capacity;
  void** array;
} DA;


// DA_new allocates array for the struct and array in different expressions
// This will make it easier to resize the array independently of the struct
DA* DA_new (void) {
  DA* arr = (DA*)malloc(sizeof(DA));
  if (arr == NULL) {
    // Handle memory allocation failure
    return NULL;
  }

  arr -> size = 0;
  arr -> capacity = STARTING_CAPACITY;
  arr -> array = (int**)malloc(STARTING_CAPACITY*sizeof(int*));
  return arr;
}

int DA_size(DA *da) {
  return da -> size;
}

void DA_push (DA* da, void* x) {
  if (da -> size == da -> capacity) {
    int old_capacity = da -> capacity;
    int new_capacity = old_capacity * old_capacity;
    int** new_array = (int**)realloc(da -> array, new_capacity*sizeof(int*));

    da -> array = new_array;
    da -> capacity = new_capacity;
  }

  da -> array[da -> size] = x;
  da -> size ++;
}

void *DA_pop(DA *da) {
  int current_size = da -> size;
  if (current_size == 0) {
    return NULL;
  }

  int** popped_value = da -> array + current_size-1;
  da -> size --;
  return *popped_value;
}

void DA_set(DA *da, void *x, int i) {
  if (da -> size < (i-1)) {
    return;
  }
  da -> array[i] = x;
}

void *DA_get(DA *da, int i) {
  if (da -> size < (i-1)) {
    return NULL;
  }
  return da -> array[i];
}


void DA_free(DA *da) {
  free(da -> array);
  free(da);
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
