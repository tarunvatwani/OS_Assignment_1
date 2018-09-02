#include "globalheader.h"

extern vector <string> command_vector;
extern char c;

void cmd_mode()
{	
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
	
}
