#include "globalheader.h"

void cp_dir(const char* source, const char* dest){
	
	struct dirent **namelist_local;
	struct stat filename;
	
	char* working_dir = get_current_dir_name();
	int chdir_success,no_entries;
				
	no_entries = scandir(source, &namelist_local, NULL, alphasort);
	stat(source, &filename);

	chdir_success = chdir(dest);
	
	if(chdir_success == -1){
		cout<<"\33[2K\r";
		cout<<"Error in cp_dir line 18 for "<<dest<<":"<<strerror(errno);
		return; 
	}
	
	if (no_entries == -1) {
		cout<<"\33[2K\r";
		cout<<"Error in cp_dir line 24 for"<<source<<":"<<strerror(errno);
		return;
	}
	
	
	size_t pos = string(source).find_last_of("/");
   	string dir_name = string(source).substr(pos+1);
	
	if(mkdir(dir_name.c_str(),filename.st_mode) == -1){
		cout<<"\33[2K\r";
		cout<<"Error in cp_dir line 34 for"<<dir_name.c_str()<<":"<<strerror(errno);
		return;
	}
	
	if(chdir(dir_name.c_str()) == -1){
		cout<<"\33[2K\r";
		cout<<"Error in cp_dir line 40 for"<<dir_name.c_str()<<":"<<strerror(errno);
		return;
	
	}
	
	char* dest_path = get_current_dir_name();
	
	if(chdir(working_dir) == -1){
		cout<<"\33[2K\r";
		cout<<"Error in cp_dir line 49 for"<<source<<":"<<strerror(errno);
		return;
	}
	
	if(chdir(source) == -1){
		cout<<"\33[2K\r";
		cout<<"Error in cp_dir line 55 for"<<source<<":"<<strerror(errno);
		return;
	
	}
	
	for(int i = 2; i<no_entries; i++){
		stat(namelist_local[i]->d_name, &filename);
		
		if(S_ISDIR(filename.st_mode)){
			cp_dir(namelist_local[i]->d_name, dest_path);
		}
		
		if(S_ISREG(filename.st_mode)){
			cp_file(namelist_local[i]->d_name, dest_path);
		}
	}
	
	chdir(working_dir);

}
