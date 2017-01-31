#include <stdio.h>

const int n = 10; // Upper bound

int main(void) {
  int direction = 1; // Direction of counting j (1 or -1)
  int j = 1;         // Current length of line

  while (j > 0) {
    int i = 1;

    while (i <= j) { // Print all numbers from 1 to j
      printf("%d ", i++);
    }

    printf("\n");

    if (j == n) { // If we are at n, reverse direction
      direction = -1;
    }
    // The next line should contain one number more or less depending on current
    // direction
    j += direction;
  }
}
