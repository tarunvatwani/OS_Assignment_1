#include "globalheader.h"

extern vector<string> command_vector;

void create_file(){

	int argc = command_vector.size();
	
	if(argc != 3){
		cout<<"\33[2K\r";
		cout<<"Invalid Command !!!!";
	}	

	else{
		
		char* working_dir = get_current_dir_name();
		FILE *out;
	
		if(chdir(command_vector[2].c_str()) != 0){
			cout<<"\33[2K\r";
			cout<<"Error in create_file line 21 for "<<command_vector[2]<<":"<<strerror(errno);
			return;
		}
	
		out = fopen(command_vector[1].c_str(),"wb");
		fclose(out);
	
		chdir(working_dir);
	}	
}
