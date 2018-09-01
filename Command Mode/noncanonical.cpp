#include "globalcmdmode.h"

void can2non_can(struct termios* initial_settings){

	struct termios new_settings = *initial_settings;

	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_lflag &= ~ISIG;
	
	if(tcsetattr(STDIN_FILENO, TCSANOW, &new_settings) != 0) {
		printf("could not set attributes\n");
	}

}
