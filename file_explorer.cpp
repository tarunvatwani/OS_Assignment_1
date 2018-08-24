#include "lsfunc.h"
#include "noncanonical.h"
#include "canonical.h"
#include "globalvariables.h"
#include "cursors.h"

int main()
{
	tcgetattr(STDIN_FILENO, &initial_settings);

	can2non_can(&initial_settings);

	printf("\033c");
	
	ls_func(namelist);
	
	do{
		c = getchar();	
		if (c == 27){
			movement(c);
		}
		else if(c == '\n'){
			
		}
	}while(c != 'q');
	
	non_can2can(&initial_settings);
		
	return 0;
}
