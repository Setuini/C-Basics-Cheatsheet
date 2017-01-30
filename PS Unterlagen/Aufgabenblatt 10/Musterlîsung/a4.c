// additional includes
#include <sys/ioctl.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <time.h>

#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))

const int MAX_COLS =  160;
const int MAX_ROWS =  40;
const int SLEEP_NANOSEC =  200000;
const int FILL_PERCENT =  20;

typedef enum { DEAD, ALIVE } cell_status;

/**
 * clears the current terminal
 */
void clear_terminal() { system("clear"); }

/**
 * gets the number of rows of the current terminal
 */
int get_current_terminal_rows() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return w.ws_row;
}

/**
 * gets the number of columns of the current terminal
 */
int get_current_terminal_columns() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return w.ws_col;
}

// Prints the gamefield (clipped to the current terminal size)
void print_gamefield(uint8_t field[][MAX_COLS]) {
  for (int row = 0; row < min(MAX_ROWS, get_current_terminal_rows()); row++) {
    for (int col = 0; col < min(MAX_COLS, get_current_terminal_columns());
         col++) {
      if (field[row][col] == ALIVE) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// Returns the number of alive cells in the neighborhood of a cell at a given position
int count_neighbours_alive(int row, int col, uint8_t field[][MAX_COLS]) {
  int neighbors_alive = 8;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }

      // test if neighbour is alive
      if (field[(row + i + MAX_ROWS) % MAX_ROWS][(col + j + MAX_COLS) %
                                                 MAX_COLS] == DEAD) {
        neighbors_alive--;
      }
    }
  }
  return neighbors_alive;
}

/**
 * calc cell with wrap around semantic
 */
int calc_cell(int row, int col, uint8_t field[][MAX_COLS]) {
  int neighbors_alive = count_neighbours_alive(row, col, field);
  int is_cell_alive = field[row][col];
  if (is_cell_alive) {
    // Any live cell with fewer than two live neighbours dies, as if caused by
    // under-population.
    // Any live cell with two or three live neighbours lives on to the next
    // generation.
    // Any live cell with more than three live neighbours dies, as if by
    // over-population.
    return neighbors_alive == 2 || neighbors_alive == 3;
  } else {
    // Any dead cell with exactly three live neighbours becomes a live cell, as
    // if by reproduction.
    return neighbors_alive == 3;
  }
}

// Initialize whole gamefield with random dead and alive cells
void init_field(uint8_t field[][MAX_COLS]) {
  for (int row = 0; row < MAX_ROWS; row++) {
    for (int col = 0; col < MAX_COLS; col++) {
      field[row][col] = rand() < RAND_MAX / 100 * FILL_PERCENT;
    }
  }
}

// Update whole gamefield
void step(uint8_t field_old[][MAX_COLS], uint8_t field_new[][MAX_COLS]) {
  for (int row = 0; row < MAX_ROWS; row++) {
    for (int col = 0; col < MAX_COLS; col++) {
      field_new[row][col] = calc_cell(row, col, field_old);
    }
  }
}

int main() {
  uint8_t field_a[MAX_ROWS][MAX_COLS] = {0};
  uint8_t field_b[MAX_ROWS][MAX_COLS] = {0};

  srand(time(NULL));
  init_field(field_a);
  print_gamefield(field_a);

  for (unsigned int count = 0; 1; count++) {
    clear_terminal();

    if (count % 2 == 0) {
      step(field_a, field_b);
      print_gamefield(field_b);
    } else {
      step(field_b, field_a);
      print_gamefield(field_a);
    }
    usleep(SLEEP_NANOSEC);
  }
}
