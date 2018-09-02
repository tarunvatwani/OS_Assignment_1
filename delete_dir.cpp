#include "globalheader.h"
#include "dir_delete.cpp"

void delete_dir(){

	int argc = command_vector.size();
	
	if(argc != 2){
		cout<<"\33[2K\r";
		cout<<"Invalid Command !!!!";
	}	

	else{
		dir_del_fn(command_vector[1].c_str());
		if(remove(command_vector[1].c_str()) != 0){
					cout<<"\33[2K\r";
					cout<<"Error in delete_dir(main) for "<<command_vector[1]<<":"<<strerror(errno);
		}	
	}	

}
