#include "globalheader.h"

extern vector<string> command_vector;
extern int count;

void goto_cmd(){

	int argc = command_vector.size();
	
	if(argc != 2){
		cout<<"\33[2K\r";
		cout<<"Invalid Command !!!!";
	}	

	else{
		printf("\033c");		
		
		if((chdir(command_vector[1].c_str())) == -1){
			cout<<"\33[2K\r";
			cout<<"Error in delete_dir line 24 for"<<command_vector[1]<<":"<<strerror(errno);
			return;
		}
		count =0;		
		ls_func(get_current_dir_name());
		printf("\033[%dA",(w.ws_row - 1 - count));
	}
}
