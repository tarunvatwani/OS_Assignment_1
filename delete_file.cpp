#include "globalheader.h"

void delete_file(){

	int argc = command_vector.size();
	
	if(argc != 2){
		cout<<"\33[2K\r";
		cout<<"Invalid Command !!!!";
	}	

	else{
		char* working_dir = get_current_dir_name();
		
		if(remove(command_vector[1].c_str()) != 0){
			cout<<"\33[2K\r";
			cout<<"Error in delete_file line 17 for "<<command_vector[1]<<":"<<strerror(errno);
			return;
		}
		
		chdir(working_dir);		
	}	

}
