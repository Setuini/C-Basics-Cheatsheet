#include <stdio.h>

const int n = 3; // Max for each of the "digits"

int main(void) {
  int x = 0;
  while (x <= n) {
    int y = 0;
    while (y <= n) {
      int z = 0;
      while (z <= n) {
        // Check if no number appears twice
        if (x != y && x != z && y != z) {
          printf("(%d, %d, %d)\n", x, y, z);
        }
        z++;
      }
      y++;
    }
    x++;
  }
}
