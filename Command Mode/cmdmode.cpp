#include "noncanonical.h"
#include "canonical.h"
#include "globalcmdmode.h"
#include "readcmd.h"
#include "cpcmd.h"

int main()
{	
	tcgetattr(STDIN_FILENO, &initial_settings);
	can2non_can(&initial_settings);

	while(true){
		c = getchar();
		
		if(c == 27){
			break;
		}
		
		else{
			read_cmd();
			cout<<command_vector[0]<<"\n";
			if(!( command_vector[0].compare("copy") )){
				cout<<"h2";
				cp_cmd();
			}
		}
	}
	
	non_can2can(&initial_settings);
	
	return 0;
	
}
