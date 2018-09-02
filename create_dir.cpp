#include "globalheader.h"

extern vector<string> command_vector;

void create_dir(){

	int argc = command_vector.size();
	
	if(argc != 3){
		cout<<"\33[2K\r";
		cout<<"Invalid Command !!!!";
	}	

	else{
		
		char* working_dir = get_current_dir_name();
		
		if(chdir(command_vector[2].c_str()) != 0){
			cout<<"\33[2K\r";
			cout<<"Error in create_dir line 20 for "<<command_vector[2]<<":"<<strerror(errno);
			return;
		}
	
		if(mkdir(command_vector[1].c_str(), ACCESSPERMS) == -1){
			cout<<"\33[2K\r";
			cout<<"Error in cp_dir line 26 for"<<command_vector[1]<<":"<<strerror(errno);
			return;
		}
	
		chdir(working_dir);
	}
		
}
