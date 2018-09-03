#include "globalheader.h"

extern vector<string> command_vector;
queue<string> dir_name;

void fn(const char* curr_dir){
	struct dirent **namelist_local;
	struct stat filename;
	
	char* working_dir = get_current_dir_name();
	
	int no_entries;
	FILE* temp;
	
	temp = fopen(command_vector[2].c_str(),"a");
	
	if(chdir(curr_dir) == -1){
		cout<<"Error in cp_file line 19 for "<<curr_dir<<":"<<strerror(errno);
		fclose(temp);
	}
		
	no_entries = scandir(".", &namelist_local, NULL, alphasort);
	
	if (no_entries == -1) {
		printf("Scan Directory Failed");
		return;
	}
	
	size_t pos = string(curr_dir).find_last_of("/");
   	string dir = string(curr_dir).substr(pos+1);

	fprintf(temp,"%s:\n",dir.c_str());
	
	
	for(int i = 2; i<no_entries; i++){
		stat(namelist_local[i]->d_name, &filename);
		
		if(S_ISREG(filename.st_mode)){
				fprintf(temp,"%s \t",namelist_local[i]->d_name);
		}
		
		if(S_ISDIR(filename.st_mode)){
			chdir(namelist_local[i]->d_name);
			dir_name.push(get_current_dir_name());
			chdir(curr_dir);
		}
	}
	
	fprintf(temp,"\n\n");
		
	fclose(temp);
	free(namelist_local);
	
	chdir(working_dir);
}

void snapshot(){
	
	int argc = command_vector.size();

	if(argc != 3){
		cout<<"\33[2K\r";
		cout<<"Invalid Command !!!!";
	}	

	
	struct dirent **namelist_local;
	struct stat filename;
	
	char* working_dir = get_current_dir_name();
	
	int no_entries;
	
	no_entries = scandir(command_vector[1].c_str(), &namelist_local, NULL, alphasort);
	FILE *temp;

	if (no_entries == -1) {
		printf("Scan Directory Failed");
		return;
	}
	
	temp = fopen(command_vector[2].c_str(),"w");
	
	fprintf(temp,".:\n");
	
	for(int i = 2; i<no_entries; i++){
		stat(namelist_local[i]->d_name, &filename);
		
		if(S_ISREG(filename.st_mode)){
				fprintf(temp,"%s \t",namelist_local[i]->d_name);
		}
		
		if(S_ISDIR(filename.st_mode)){
			chdir(namelist_local[i]->d_name);
			dir_name.push(get_current_dir_name());
			chdir(working_dir);
		}
	}
	
	fprintf(temp,"\n\n");
	
	fclose(temp);
	free(namelist_local);
	
	while(!dir_name.empty()){
		string front = dir_name.front();
		dir_name.pop();
		fn(front.c_str());
	}
	
}
