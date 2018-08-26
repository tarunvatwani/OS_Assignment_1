#include "globalvariables.h"
#include "lsfunc.h"
#include "noncanonical.h"
#include "canonical.h"
#include "cursors.h"
#include "enterdirectory.h"
#include "traversal.h"


int main()
{	
	root = get_current_dir_name();
	tcgetattr(STDIN_FILENO, &initial_settings);
	can2non_can(&initial_settings);

	printf("\033c");
	
	count_MAX = ls_func(root);
	printf("\033[%dA",count_MAX);
	
	do{

		c = getchar();	
		if (c == 27){
			c = getchar();
			c = getchar();
			movement();
			traverse();
			
		}
		
		else if(c == '\n' || c == 127){
			enter_dir();				
		}
	}while(c != 'q');
	
	printf("\033[%dB",count_MAX-count);
	
	non_can2can(&initial_settings);
		
	return 0;
}
