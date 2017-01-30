#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const int max = 100; // Maximal number

int main(void) {
  int guesses = 0;   // Number of guesses the user made until now
  srand(time(NULL)); // Initalize random number generator

  // Generate the number that is "chosen" by the computer
  int number = (rand() % max) + 1;

  // Start the game loop
  bool running = true;
  while (running) {
    // Read the three numbers from the user
    int n1, n2, n3;
    do { // Repeat until the user enters three valid numbers
      printf("Please enter three numbers between 1 and %d:", max);
      scanf("%d %d %d", &n1, &n2, &n3);
    } while (n1 < 1 || n1 > max || n2 < 1 || n2 > max || n3 < 1 || n3 > max);
    guesses++;

    // Check if one of the entered numbers is the correct one
    if (n1 == number || n2 == number || n3 == number) {
      printf("Congratulations. %d was the correct number. You won with %d "
             "guesses\n",
             number, guesses);
      running = false; // We have won. So stop running the loop
    } else {
      // None was the correct number
      // Find out wether more of the numbers were greater or smaller than the
      // correct number
      if ((n1 > number) + (n2 > number) + (n3 > number) >
          (n1 < number) + (n2 < number) + (n3 < number)) {
        printf("More numbers were greater than the true number\n");
      } else {
        printf("More numbers were smaller than the true number\n");
      }
    }
  }
}
