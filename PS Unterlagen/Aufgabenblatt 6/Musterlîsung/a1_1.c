/* Implementation with while loop */

#include <stdio.h>

int main(void) {
  const int x = 7;
  printf("zeile 1\n");
  int i = 0;
  int j = 3;
  while ((i + 5) < x + 10 && j > -50) {
    printf("zeile 2\n");
    if (j % 4)
      printf("zeile 3\n");
    --i;
    ++i;
    j -= 3;
  }
  printf("zeile 4\n");
}
