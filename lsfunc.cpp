#include "globalvariables.h"


char conversion(long int *x){
	if(*x < 1024){
		return 'B';
	}
	else if(*x < (1024*1024)){
		*x = *x/1024;
		return 'K';
	}
	else if(*x < (1024*1024*1024)){
		*x = *x/(1024*1024);
		return 'M';
	}
	else{
		*x = *x/(1024*1024*1024);
		return 'G';
	}
}

int ls_func(char *s){
	struct dirent **namelist_local;
	struct stat filename;
	
	int chdir_success,no_entries;
		
	chdir_success = chdir(s);
	no_entries = scandir(".", &namelist_local, NULL, alphasort);
	
	if(chdir_success){
		printf("Change Directory Failed");
	}
	
	if (no_entries == -1) {
		return no_entries;
	}
			
	for(int i = 0; i<no_entries; i++){
		stat(namelist_local[i]->d_name, &filename);
		
		printf("%-35.25s", namelist_local[i]->d_name);
		
		char x = conversion(&filename.st_size);
		printf("%ld%c\t", filename.st_size,x);
		
		printf("%s\t",(getgrgid(filename.st_gid))->gr_name);
		printf("%s\t",(getpwuid(filename.st_uid))->pw_name);

        printf( (filename.st_mode & S_IRUSR) ? "r" : "-");
        printf( (filename.st_mode & S_IWUSR) ? "w" : "-");
        printf( (filename.st_mode & S_IXUSR) ? "x" : "-");
        printf( (filename.st_mode & S_IRGRP) ? "r" : "-");
        printf( (filename.st_mode & S_IWGRP) ? "w" : "-");
        printf( (filename.st_mode & S_IXGRP) ? "x" : "-");
        printf("\t");

		printf("%s", ctime(&filename.st_mtime));
		free(namelist_local[i]);
	}
	
	free(namelist_local);
	return no_entries;
}
