#include <stdio.h>
#include <stdlib.h>

#include "address.h"

void print_array(const struct address arr[], const int lastElement) {
  for (int i = 0; i <= lastElement; i++) {
    printf("Dataset Nr. %d\n", i + 1);
    print_address(&arr[i]);
    printf("\n");
  }
}

void enqueue(struct address arr[], int *lastElement, struct address element) {
  (*lastElement)++;
  arr[*lastElement] = element;
}

char menu(void) {
  printf("a ... Add dataset\n");
  printf("p ... Print all datasets\n");
  printf("q ... Quit program\n");

  printf("Selection: \n");
  char c = '\0';
  while (c != 'a' && c != 'p' && c != 'q') {
    c = getchar();
  }
  return c;
}

int main() {
  int lastElement = -1;
  struct address array[10];

  for (;;) { // Infinite loop
    char selection = menu();

    switch (selection) {
    case 'a': { // Add new data
      enqueue(array, &lastElement, input_address());
      break;
    }
    case 'p': { // Print all data
      print_array(array, lastElement);
      break;
    }
    case 'q': { // Quit program
      return EXIT_SUCCESS;
      break;
    }
    default:
      break;
    }
  }
}
