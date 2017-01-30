// Compile using gcc -Wall -Werror -std=c99 -lm a1.c -o a1
#include <stdio.h>
#include <math.h>

// Apply function f to all elements of array and replace element by result of f
void map(int *array, int length, int (*f)(int)) {
  for (int i = 0; i < length; i++)
    array[i] = f(array[i]);
}

// Return given int multiplied by 2
int mul(int a) { return a * 2; }

// Return square of given int
int sqr(int a) { return a * a; }

// Return square root of given int
int int_sqrt(int a) { return sqrt(a); }

// Prints array on screen
void print(int *array, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// Fill array with consecutive numbers
void fill(int *array, int length) {
  for (int i = 0; i < length; i++) {
    array[i] = i;
  }
}

int main() {
  const int LENGTH = 10;
  int arr1[LENGTH];
  fill(arr1, LENGTH);
  int arr2[LENGTH];
  fill(arr2, LENGTH);
  int arr3[LENGTH];
  fill(arr3, LENGTH);

  print(arr1, LENGTH);
  map(arr1, LENGTH, mul);
  print(arr1, LENGTH);
  map(arr2, LENGTH, sqr);
  print(arr2, LENGTH);
  map(arr3, LENGTH, int_sqrt);
  print(arr3, LENGTH);
}
