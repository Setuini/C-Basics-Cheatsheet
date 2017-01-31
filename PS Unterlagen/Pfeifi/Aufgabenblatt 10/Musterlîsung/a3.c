/* Hinweis: Das printf in enqueu und dequeue ist nur um das Programm überprüfen
 * zu können. In der Praxis würde man das nicht machen! */

#include <stdio.h>
#include <stdlib.h>

// Put new element at the end of the queue
// We have to pass a pointer to the array since realloc might change the address
// of the array
void enqueue(int *arr[], int *lastElementIdx, int *length, int element) {
  if (*lastElementIdx == *length - 1) { // Array if full so realloc
    *length *= 2;
    *arr = realloc(*arr, sizeof(int) * (*length));
    printf("Array size increased from %d to %d\n", *length / 2, *length);
  }
  (*arr)[++(*lastElementIdx)] = element;
}

// Retrieve and remove first element of the queue
// We have to pass a pointer to the array since realloc might change the address
// of the array
int dequeue(int *arr[], int *lastElementIdx, int *length) {
  if (*lastElementIdx < 0) { // If there is no element left return 0
    return 0;
  } else {
    int result = *arr[0];
    // Move all remaining elements to the front
    for (int i = 0; i < *lastElementIdx; i++) {
      (*arr)[i] = (*arr)[i + 1];
    }
    (*lastElementIdx)--;
    // If necessary decrease the used memory
    if (*lastElementIdx < *length / 2 && *length != 10) {
      int old_length = *length;
      *length = *length / 2 <= 10 ? 10 : *length / 2;
      *arr = realloc(*arr, sizeof(int) * (*length));
      printf("Array size decreased from %d to %d\n", old_length, *length);
    }
    return result;
  }
}

// Print complete queue
void printQueue(const int *arr, const int lastElementIdx) {
  printf("Current Queue: ");
  if (lastElementIdx == -1) {
    printf("empty");
  }
  for (int i = 0; i <= lastElementIdx; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int lastElement = -1;
  int length = 10;
  int *arr = malloc(sizeof(int) * length);

  printQueue(arr, lastElement);
  for (int i = 0; i < 40; i++) {
    int elem = rand() % 100;
    printf("Adding element %d to the queue\n", elem);
    enqueue(&arr, &lastElement, &length, elem);
  }
  printQueue(arr, lastElement);
  for (int i = 0; i < 35; i++) {
    printf("Removed Element %d\n", dequeue(&arr, &lastElement, &length));
  }
  printQueue(arr, lastElement);

  // At the end of the program a free is not strictly necessary, but it is still
  // good style to do it
  free(arr);
}
