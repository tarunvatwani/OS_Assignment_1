#include "globalcmdmode.h"

int main()
{	
	tcgetattr(STDIN_FILENO, &initial_settings);
	can2non_can(&initial_settings);

	while(true){
		c = getchar();
		
		if(c == 27){
			cout<<"\33[2K\r";
			break;
		}
		
		else{
			read_cmd();
			if(!( command_vector[0].compare("copy") )){
				cp_cmd();
			}
		}
		
	}
	
	non_can2can(&initial_settings);
	
	return 0;
	
}
