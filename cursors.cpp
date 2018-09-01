#include "globalheader.h"

extern char c;
extern int count;
extern int count_MAX;
extern int print_limit;

void movement(){	

	if (c==65) 
	{ 
		if(count > 0){
			(count)--;
			if(count < (print_limit-1)){
				printf("\033[A");
			}
			
			if(count >= (print_limit-1)){
				printf("\033c");
				ls_func(get_current_dir_name());
				printf("\033[A");		
			}	
		}
	}
	
	if (c==66) 
	{ 
		if(count_MAX > print_limit){
			if(count < count_MAX-1){
				(count)++;
				if(count < print_limit-1){
					printf("\033[B");
				}
			}
			if(count >= (print_limit - 1)){
				printf("\033c");
				ls_func(get_current_dir_name());
				printf("\033[A");
			}		
		}
		else{
			if(count < count_MAX-1){
				(count)++;
				printf("\033[B");
			} 

		}
	}
}
