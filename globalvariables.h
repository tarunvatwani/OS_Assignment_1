#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>

#include <iostream>
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

/*Functions Declaration*/
void non_can2can(struct termios*);
void can2non_can(struct termios*);
void movement();
void enter_dir(void);
int ls_func(char *);
void traverse(void);

#endif
