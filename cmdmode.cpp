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
			else if(!( command_vector[0].compare("create_dir") )){
				create_dir();
			}
			else if(!( command_vector[0].compare("create_file") )){
				create_file();
			}
			else if(!( command_vector[0].compare("rename") )){
				rename();
			}
			else if(!( command_vector[0].compare("delete_file") )){
				delete_file();
			}
			else if(!( command_vector[0].compare("delete_dir") )){
				delete_dir();				
			}
			else if(!( command_vector[0].compare("move") )){
				move();				
			}
			else{
				cout<<"\33[2K\r";
				cout<<"Invalid Command";
			}
		}
		
	}
	
}
