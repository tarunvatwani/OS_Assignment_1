#include "cursors.h"

void movement(char c){
	c = getchar();
	c = getchar();
	if (c==65) { printf("\033[A");}
	if (c==66) { printf("\033[B");}
	if (c==67) { printf("\033[C");}
    if (c==68) { printf("\033[D");}
}
