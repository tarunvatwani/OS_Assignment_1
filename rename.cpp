#include "globalheader.h"

void rename(){

	int argc = command_vector.size();
	
	if(argc != 3){
		cout<<"\33[2K\r";
		cout<<"Invalid Command !!!!";
	}	

	else{
		char* working_dir = get_current_dir_name();
		
		if(rename(command_vector[1].c_str(),command_vector[2].c_str())!= 0){
			cout<<"\33[2K\r";
			cout<<"Error in rename line 17 "<<":"<<strerror(errno);
			return;
		}
		
		chdir(working_dir);		
	}	

}
