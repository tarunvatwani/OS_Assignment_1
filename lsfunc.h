#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>


#ifndef INC_LSFUNC_H
#define INC_LSFUNC_H

int ls_func(struct dirent **);

#endif
