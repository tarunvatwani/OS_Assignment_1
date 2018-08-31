#include "globalvariables.h"

extern char c;
extern int count;
extern int count_MAX;

void movement(){	

	if (c==65) 
	{ 
		if(count > 0){
			(count)--;
			printf("\033[A");
		}
	}
	
	if (c==66) 
	{ 
		if(count < count_MAX-1){
			(count)++;
			printf("\033[B");
		}		
	}
}
