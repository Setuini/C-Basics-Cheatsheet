#include <stdio.h>
#include <stdlib.h>

const int MAX_NUMBER_OF_VALUES = 1000;

typedef enum _user_entry { MORE_NUMBERS = 1, QUIT = 2, INVALID = 3 } user_entry;

// flush the queue
void clear_buffer() {
  while (getchar() != '\n') {
  }
}

user_entry read_number(int *next_value) {
  // try to parse integer
  int matched = scanf("%d", next_value);
  // if matched equals 1, matching was probably successful.
  if (matched == 1) {
    // if the next character is not a newline, the number was invalid
    // this means that there are characters remaining in the buffer
    if (getchar() != '\n') {
      clear_buffer();
      return INVALID;
    } else {
      return MORE_NUMBERS;
    }
  }
  // now that's a bit tricky, because simply putting getchar() == 'q'
  // could remove a '\n' from the buffer. In this case, clearing the
  // the buffer will not work properly, because there is no '\n' until
  // the user enters the next line. So you might lose some input.
  char c = getchar();
  if (c == 'q' && getchar() == '\n') {
    return QUIT;
  }
  // if there is something remaining in the buffer, it is now the time
  // to clear it. This way, we assure that from now on any valid input
  // will be accepted, and not rejected because of remainig parts in the
  // buffer.
  if (c != '\n') {
    clear_buffer();
  }
  return INVALID;
}

int main(void) {
  int next_number;
  int number_of_values = 0;
  int min = 0;
  int max = 0;
  long long sum = 0;
  // main loop: get input, and act accordingly.
  while (number_of_values < MAX_NUMBER_OF_VALUES) {
    user_entry entry = read_number(&next_number);
    // the user has entered only a q, followed by a newline
    if (entry == QUIT) {
      break;
    }
    // the user has entered a valid number. Update statistic.
    if (entry == MORE_NUMBERS) {
      number_of_values++;
      sum += next_number;
      if (min > next_number || number_of_values == 1) {
        min = next_number;
      }
      if (max < next_number || number_of_values == 1) {
        max = next_number;
      }
    }
    // nothing happens on INVALID
  }
  printf("CNT: %d\n", number_of_values);
  printf("MIN: %d\n", min);
  printf("MAX: %d\n", max);
  printf("AVG: %lf\n",
         number_of_values == 0 ? 0.0 : (double)sum / number_of_values);
  return EXIT_SUCCESS;
}
