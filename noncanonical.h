#include <termios.h>
#include <unistd.h>
#include <stdio.h>


#ifndef INC_NONCANONINCAL_H
#define INC_NONCANONINCAL_H

void can2non_can(struct termios*);

#endif
