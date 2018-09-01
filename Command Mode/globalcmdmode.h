#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <termios.h>
#include <sys/stat.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#ifndef INC_GLOBALCMDMODE_H
#define INC_GLOBALCMDMODE_H

extern vector<string> command_vector;
extern struct termios initial_settings;
extern char c;

/*Functions Declarations*/
void non_can2can(struct termios*);
void can2non_can(struct termios*);
void cp_cmd();
void read_cmd();
 
#endif
