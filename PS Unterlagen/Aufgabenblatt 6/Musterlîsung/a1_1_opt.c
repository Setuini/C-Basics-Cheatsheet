/* Implementation with while loop */

#include <stdio.h>

// Value of i never changes anyway so --i and ++i can be removed

// Since i never changes the expression (i + 5) < x is always true and can be
// removed

// Since we removed (i + 5) < x, i and x are not used at all in the program and
// can be removed

int main(void) {
  printf("zeile 1\n");
  int j = 3;
  while (j > -50) {
    printf("zeile 2\n");
    if (j % 4)
      printf("zeile 3\n");
    j -= 3;
  }
  printf("zeile 4\n");
}
