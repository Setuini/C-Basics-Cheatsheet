#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  printf("f ... Sort by first name\n");
  printf("s ... Sort by surname\n");
  printf("l ... Sort by length\n");
  printf("q ... Quit program\n");

  printf("Selection: \n");
  char c = '\0';
  while (c != 'a' && c != 'p' && c != 'q' && c != 'f' && c != 's' && c != 'l') {
    c = getchar();
  }
  return c;
}

int sort_first_name_ascending(const void *a, const void *b) {
  const char *p = ((struct address *)a)->vorname;
  const char *q = ((struct address *)b)->vorname;
  return strcmp(p, q);
}

int sort_last_name_descending(const void *a, const void *b) {
  const char *p = ((struct address *)a)->nachname;
  const char *q = ((struct address *)b)->nachname;
  return -strcmp(p, q);
}

int sort_first_last_name_length(const void *a, const void *b) {
  const struct address *p = a;
  const struct address *q = b;
  int cmp = strlen(q->vorname) - strlen(p->vorname);
  if (cmp == 0) { // If length of both first names are equal we have to compare
                  // the last name
    cmp = strlen(q->nachname) - strlen(p->nachname);
  }
  return cmp;
}

int main() {
  const int LEN = 10;
  int lastElement = -1;
  struct address array[LEN];

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
    case 'f': { // Sort data by first name ascending
      qsort(array, lastElement + 1, sizeof(struct address),
            sort_first_name_ascending);
      break;
    }
    case 's': { // Sort data by last name descending
      qsort(array, lastElement + 1, sizeof(struct address),
            sort_last_name_descending);
      break;
    }
    case 'l': { // Sort data by length ascending
      qsort(array, lastElement + 1, sizeof(struct address),
            sort_first_last_name_length);
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
