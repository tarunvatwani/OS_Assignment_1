#include "globalvariables.h"

struct termios initial_settings;
char c;
int count;
int count_MAX;
char* root;

stack<char*> forward_filename;
stack<char*> backward_filename;
