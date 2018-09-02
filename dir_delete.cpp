#include "globalheader.h"

void dir_del_fn(const char* target){
	struct dirent **namelist_local;
	struct stat filename;
		
	char* working_dir = get_current_dir_name();
	int no_entries;
				
	no_entries = scandir(target, &namelist_local, NULL, alphasort);
		
	if((chdir(target)) == -1){
		cout<<"\33[2K\r";
		cout<<"Error in delete_dir line 24 for"<<command_vector[1]<<":"<<strerror(errno);
		return;
	}
				
	if (no_entries == -1) {
		cout<<"\33[2K\r";
		cout<<"Error in delete_dir line 25 for"<<command_vector[1]<<":"<<strerror(errno);
		return;
	}		
		
		
	for(int i = 2; i<no_entries; i++){
		stat(namelist_local[i]->d_name, &filename);
		
		if(S_ISDIR(filename.st_mode)){
			dir_del_fn(namelist_local[i]->d_name);
			if(remove(namelist_local[i]->d_name) != 0){
				cout<<"\33[2K\r";
				cout<<"Error in delete_dir line 43 for "<<namelist_local[i]->d_name<<":"<<strerror(errno);
				return;
			}
		}
		
		if(S_ISREG(filename.st_mode)){
			if(remove(namelist_local[i]->d_name) != 0){
				cout<<"\33[2K\r";
				cout<<"Error in delete_dir line 52 for "<<namelist_local[i]->d_name<<":"<<strerror(errno);
				return;
			}
		}
	}
				
	chdir(working_dir);		
}
