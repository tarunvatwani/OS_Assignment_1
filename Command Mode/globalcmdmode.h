#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <iostream>
#include <termios.h>

using namespace std;

#ifndef INC_GLOBALCMDMODE_H
#define INC_GLOBALCMDMODE_H

extern vector<string> command_vector;
extern struct termios initial_settings;
extern char c; 
#endif
