#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#ifndef INC_GLOBALVARIABLES_H
#define INC_GLOBALVARIABLES_H

struct termios initial_settings;
struct dirent **namelist;
char c;

#endif
