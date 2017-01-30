#include <stdio.h>
int main(void) {
  int x = 7;
  printf("zeile 1\n");
  for (int i = 0, j = 3; (i + 5) < x + 10 && j > -50; ++i, j -= 3) {
    printf("zeile 2\n");
    if (j % 4)
      printf("zeile 3\n");
    --i;
  }
  printf("zeile 4\n");
}
