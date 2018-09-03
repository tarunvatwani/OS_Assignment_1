#include "globalheader.h"

void cp_file(const char* filename, const char* dirname){
	
	char* working_dir = get_current_dir_name();
	
	int c;
	FILE *in, *out;

	if( (in = fopen(filename,"rb"))  == NULL){
		cout<<"\33[2K\r";
		cout<<"Error in cp_file line 12 for "<<filename<<":"<<strerror(errno);
	}
	
	else{
		size_t pos = string(filename).find_last_of("/");
   		string file_name = string(filename).substr(pos+1);
   		
   		struct stat permission;
		stat(filename, &permission);

		if(chdir(dirname) != 0){
			cout<<"\33[2K\r";
			cout<<"Error in cp_file line 21 for "<<dirname<<":"<<strerror(errno);
			fclose(in);
			return;
		}
	
		out = fopen(file_name.c_str(),"wb");
		
		chmod(file_name.c_str(), permission.st_mode);

		while((c = fgetc(in)) != EOF)
			fputc(c,out);
		
		fclose(in);
		fclose(out);
	
		chdir(working_dir);
	}
}

