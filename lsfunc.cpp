#include "globalheader.h"

extern char* root;
extern int count;
extern int count_MAX;
extern int print_limit;
extern struct winsize w;

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

void ls_func(char *s){
	struct dirent **namelist_local;
	struct stat filename;
	
	int chdir_success,no_entries;
		
	chdir_success = chdir(s);
		
	no_entries = scandir(".", &namelist_local, NULL, alphasort);
	
	if(chdir_success == -1){
		printf("Change Directory Failed");
		return;
	}
	
	if (no_entries == -1) {
		printf("Scan Directory Failed");
		return;
	}
	
	count_MAX = no_entries;
	
	int start = (count <= (print_limit-1))?0:(count - (print_limit-1));
	int end   = (count_MAX < print_limit)?count_MAX:( ((print_limit + start) < count_MAX)?(print_limit + start):count_MAX);
	
	for(int i = start; i<end; i++){
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
	
	string relative_path = string(get_current_dir_name());
	string root_path = string(root);
	size_t pos = relative_path.find(root_path);
	if(root_path.compare(relative_path) == 0){
		cout<<"\e[1mcurrent_dir = /root\e[0m"<<"\r";	
	}
	else{
		cout<<"\e[1mcurrent_dir = /root"<<relative_path.substr(pos+(root_path.length()))<<"\e[0m\r";	
	}
	
	free(namelist_local);
}
