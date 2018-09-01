#include "globalheader.h"

int main()
{	
	tcgetattr(STDIN_FILENO, &initial_settings);
	can2non_can(&initial_settings);

	printf("\033c");
	
	ls_func(root);
	printf("\033[%dA",count_MAX);
	
	while(1){

		c = getchar();
		
		if(c == 'q')
			break;
			
		else if (c == 27){
			c = getchar();
			c = getchar();
			movement();
			traverse();
			
		}
		
		else if(c == '\n' || c == 127){
			enter_dir();				
		}
		
		else if(c == 'h'){
			printf("\033c");
			ls_func(root);
			printf("\033[%dA",count_MAX);
		}
		
		else
			continue;		
	}
	
	if((count + 1) >= print_limit){
		printf("\033[B");
	}
	else{
		if(print_limit < count_MAX){
			printf("\033[%dB", print_limit - count);
		}
		else{
			printf("\033[%dB", count_MAX - count);
		}
	}
	
	
	non_can2can(&initial_settings);
		
	return 0;
}
