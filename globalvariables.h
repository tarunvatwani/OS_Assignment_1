#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#include <stack>
#include <string>

using namespace std;

#ifndef INC_GLOBALVARIABLES_H
#define INC_GLOBALVARIABLES_H

extern struct termios initial_settings;
extern char c;
extern int count;
extern int count_MAX;
extern char* root;
extern stack<char*> forward_filename;
extern stack<char*> backward_filename;

#endif
