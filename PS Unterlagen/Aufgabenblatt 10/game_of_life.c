#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

/**
 * clears the current terminal
 */
void clear_terminal(){
	system ("clear");
}

/**
 * gets the number of rows of the current terminal
 */
int get_current_terminal_rows(){
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_row;
}

/**
 * gets the number of columns of the current terminal
 */
int get_current_terminal_columns(){
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col;
}

int main(int argc, char **argv){
	
}
