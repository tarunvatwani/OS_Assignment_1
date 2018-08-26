#include "enterdirectory.h"

extern stack<char *> backward_filename;
extern char c;
extern int count;
extern int count_MAX;

void enter_dir(){
	struct dirent **namelist_local = NULL;
	struct stat sb;

	int success = scandir(".", &namelist_local, NULL, alphasort);
	
	if (success == -1) {
		printf("Error !!!!");
	}
	
	if(c == '\n'){
		if ((stat(namelist_local[count]->d_name, &sb) == 0)&& S_ISDIR(sb.st_mode))
		{	
			backward_filename.push(get_current_dir_name());
	
			printf("\033c");
			count_MAX = ls_func(namelist_local[count]->d_name);
			free(namelist_local[count]);
			printf("\033[%dA",(count_MAX));
			count = 0;
		}
		
		if((stat(namelist_local[count]->d_name, &sb) == 0)&& S_ISREG(sb.st_mode)){
			pid_t pid;
            pid = fork();
            if(pid == 0){
            	execl("/usr/bin/xdg-open","xdg-open",namelist_local[count]->d_name,(char*)0);
			}
		}
	}

	if(c == 127){
		if ((stat(namelist_local[1]->d_name, &sb) == 0)&& S_ISDIR(sb.st_mode))
		{	
			backward_filename.push(get_current_dir_name());

			printf("\033c");
			count_MAX = ls_func(namelist_local[1]->d_name);
			free(namelist_local[count]);
			printf("\033[%dA",(count_MAX));
			count = 0;
		}
	}
	
	free(namelist_local);
}
