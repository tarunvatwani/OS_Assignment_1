#include "globalheader.h"

extern vector<string> command_vector;

void move(){

	int argc = command_vector.size();
	struct stat command_content;
	
	if(argc < 3){
		cout<<"\33[2K\r";
		cout<<"Insufficient Arguments !!!!";
	}	

	else{
		
		cp_cmd();
				
		for(int i = 1; i<(argc-1); i++){
		
			if((stat(command_vector[i].c_str(), &command_content) == 0) && (S_ISDIR(command_content.st_mode)) ){
				dir_delete(command_vector[i].c_str());
			}
			
			if((stat(command_vector[i].c_str(), &command_content) == 0) && S_ISREG(command_content.st_mode)){
				file_delete(command_vector[i].c_str());
			}		
		}
	}
}
