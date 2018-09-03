#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

#ifndef INC_GLOBALHEADER_H
#define INC_GLOBALHEADER_H

/*Variable Declaration*/
//Normal Mode
extern struct termios initial_settings;
extern struct winsize w;
extern char c;
extern int count;
extern int count_MAX;
extern int print_limit;
extern char* root;
extern stack<char*> forward_filename;
extern stack<char*> backward_filename;

//Command Mode
extern vector<string> command_vector;

/*Functions Declaration*/
//Normal Mode
void non_can2can(struct termios*);
void can2non_can(struct termios*);
void movement();
void enter_dir(void);
void ls_func(char *);
void traverse(void);

//Command Mode
void cmd_mode();
void cp_cmd();
void read_cmd();
void create_file();
void create_dir();
void rename();
void delete_file();
void delete_dir();
void dir_del_fn(const char*);
void move();
void goto_cmd();

#endif
