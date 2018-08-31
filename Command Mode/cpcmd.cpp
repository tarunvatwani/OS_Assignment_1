#include "cpcmd.h"

extern vector<string> command_vector;

void cp_func(const char* filename, const char* dirname){
	
	int c;
	FILE *in, *out;

	in = fopen(filename,"rb");
	
	chdir(dirname);
	
	out = fopen(filename,"wb");

	while((c = fgetc(in)) != EOF)
		fputc(c,out);
		
	fclose(in);
	fclose(out);

}

void cp_cmd(){
	cp_func(command_vector[1].c_str(), command_vector[2].c_str());	
}
