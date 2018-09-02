#include "globalheader.h"
#include "filecopy.cpp"
#include "dircopy.cpp"

extern vector<string> command_vector;

void cp_cmd(){

	int argc = command_vector.size();
	struct stat command_content;
	
	if(argc < 3){
		cout<<"\33[2K\r";
		cout<<"Insufficient Arguments !!!!";
	}	

	else{		
		for(int i = 1; i<(argc-1); i++){
		
			if((stat(command_vector[i].c_str(), &command_content) == 0) && (S_ISDIR(command_content.st_mode)) ){
				cp_dir(command_vector[i].c_str(), command_vector[argc-1].c_str());
			}
			
			if((stat(command_vector[i].c_str(), &command_content) == 0) && S_ISREG(command_content.st_mode)){
				cp_file(command_vector[i].c_str(), command_vector[argc-1].c_str());
			}		
		}
	}
}
