#include "globalheader.h"

void non_can2can(struct termios* initial_settings){

		tcsetattr(STDIN_FILENO,TCSANOW,initial_settings);
}
