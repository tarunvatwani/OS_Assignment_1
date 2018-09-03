#include "globalheader.h"

struct termios initial_settings;
struct winsize w;

char c;
int count;
int count_MAX;
char* root = get_current_dir_name();


stack<char*> forward_filename;
stack<char*> backward_filename;
vector <string> command_vector;

int x = ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
int print_limit = (0.8)*w.ws_row;
