#include <stdio.h>

// Put new element at the end of the queue
int enqueue(int arr[], int *lastElementIdx, int length, int element) {
  if (*lastElementIdx == length - 1) {
    return 0;
  } else {
    arr[++(*lastElementIdx)] = element;
    return 1;
  }
}

// Retrieve and remove first element of the queue
int dequeue(int arr[], int *lastElementIdx) {
  if (*lastElementIdx < 0) {
    return 0;
  } else {
    int result = arr[0];
    // Move all remaining elements to the front
    for (int i = 0; i < *lastElementIdx; i++) {
      arr[i] = arr[i + 1];
    }
    (*lastElementIdx)--;
    return result;
  }
}

// Print complete queue
void printQueue(const int arr[], int lastElementIdx) {
  printf("Current Queue: ");
  for (int i = 0; i <= lastElementIdx; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[100];
  int lastElement = -1;
  printQueue(arr, lastElement);
  enqueue(arr, &lastElement, 100, 23);
  enqueue(arr, &lastElement, 100, 42);
  enqueue(arr, &lastElement, 100, 65);
  enqueue(arr, &lastElement, 100, 78);
  printQueue(arr, lastElement);
  printf("Removed Element %d\n", dequeue(arr, &lastElement));
  printf("Removed Element %d\n", dequeue(arr, &lastElement));
  printQueue(arr, lastElement);
  printf("Removed Element %d\n", dequeue(arr, &lastElement));
  printf("Removed Element %d\n", dequeue(arr, &lastElement));
  printf("Removed Element %d\n", dequeue(arr, &lastElement));
  printf("Removed Element %d\n", dequeue(arr, &lastElement));
}
