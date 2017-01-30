#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

// Fill array with random numbers from 0 to 99
void fill_array(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    arr[i] = rand() % 100;
  }
}

// Print array
void print_array(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Sort array according to size of integer
// If arg = 1 normal sorting, if arg = -1 sort in reverse
int sort1(const void *a, const void *b, void *arg) {
  int *p = (int *)a;
  int *q = (int *)b;
  int order = *((int *)arg);

  if (*p < *q)
    return -order;
  if (*p > *q)
    return order;
  return 0; // In this case p and q have to be equal
}

// Returns number of 1s in binary represenation of a
int get_number_of_ones(int a) {
  int count = 0;
  while (a != 0) {
    if (a % 2 == 1)
      count++;
    a = a >> 1;
  }
  return count;
}

// Print binary representation of a (warning: Reversed order)
void print_binary(int a) {
  while (a != 0) {
    if (a % 2 == 1)
      printf("1");
    else
      printf("0");
    a = a >> 1;
  }
}

// Print array in binary representation (warning: Reversed order)
void print_array_binary(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    print_binary(arr[i]);
    printf(" ");
  }
  printf("\n");
}

// Sort according to number of 1s in binary representation of number
// If arg = 1 normal sorting, if arg = -1 sort in reverse
int sort2(const void *a, const void *b, void *arg) {
  int p = get_number_of_ones(*(int *)a);
  int q = get_number_of_ones(*(int *)b);
  int order = *((int *)arg);

  if (p < q)
    return -order;
  if (p > q)
    return order;
  return 0; // In this case p and q have to be equal
}

// Return length of longest sequence of the same bit
int longest_sequence(int a) {
  int max = 0;
  int count = 0;
  int looking_at = 1;

  // sizeof(int) returns unsigned so we should also make i unsigned!
  for (unsigned int i = 0; i < sizeof(int) * 8; i++) {
    int digit = a % 2;
    a = a >> 1;
    if (digit == looking_at) {
      count++;
      if (count > max)
        max = count;
    } else {
      looking_at = digit;
      count = 1;
    }
  }
  return max;
}

// Sort according to length of longest sequence of the same bit
// If arg = 1 normal sorting, if arg = -1 sort in reverse
int sort3(const void *a, const void *b, void *arg) {
  int p = longest_sequence(*(int *)a);
  int q = longest_sequence(*(int *)b);
  int order = *((int *)arg);

  if (p < q)
    return -order;
  if (p > q)
    return order;
  return 0; // In this case p and q have to be equal
}

int main() {
  const int LEN = 10;

  int arr[LEN];
  fill_array(arr, LEN);
  print_array(arr, LEN);

  // Sort in normal order
  int order = 1; // order defines direction of sorting. Passed to all calles of
                 // sort1, sort2, sort3
  printf("\nSorting in normal order:\n--------------------");
  // Sort array according to value
  printf("\nSort using value of numbers\n");
  qsort_r(arr, LEN, sizeof(int), sort1, &order);
  print_array(arr, LEN);
  // Sort array according to number of ones
  printf("\nSort using amount of 1s in binary representation\n");
  qsort_r(arr, LEN, sizeof(int), sort2, &order);
  print_array_binary(arr, LEN);
  // Sort using longest sequence of same bit
  printf("\nSort using longest sequence of same bit\n");
  qsort_r(arr, LEN, sizeof(int), sort3, &order);
  print_array_binary(arr, LEN);

  // Sort in reverse order
  order = -1;
  printf("\nSorting in reverse order:\n--------------------");
  // Sort array according to value
  printf("\nSort using value of numbers\n");
  qsort_r(arr, LEN, sizeof(int), sort1, &order);
  print_array(arr, LEN);
  // Sort array according to number of ones
  printf("\nSort using amount of 1s in binary representation\n");
  qsort_r(arr, LEN, sizeof(int), sort2, &order);
  print_array_binary(arr, LEN);
  // Sort using longest sequence of same bit
  printf("\nSort using longest sequence of same bit\n");
  qsort_r(arr, LEN, sizeof(int), sort3, &order);
  print_array_binary(arr, LEN);
}
