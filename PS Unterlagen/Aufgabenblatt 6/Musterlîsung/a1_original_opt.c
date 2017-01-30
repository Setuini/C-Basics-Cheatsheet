// Value of i never changes anyway so --i and ++i can be removed

// Since i never changes the expression (i + 5) < x is always true and can be
// removed

// Since we removed (i + 5) < x, i and x are not used at all in the program and
// can be removed

#include <stdio.h>
int main(void) {
  printf("zeile 1\n");
  for (int j = 3; j > -50; j -= 3) {
    printf("zeile 2\n");
    if (j % 4)
      printf("zeile 3\n");
  }
  printf("zeile 4\n");
}
