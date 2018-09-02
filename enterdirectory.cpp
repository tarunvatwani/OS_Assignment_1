#include "globalheader.h"

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
			
		if(strcmp( root, get_current_dir_name() ) == 0){
				if(strcmp(namelist_local[count]->d_name, "..") == 0){
					return;
				}
		}

		if ((stat(namelist_local[count]->d_name, &sb) == 0)&& S_ISDIR(sb.st_mode))
		{	
			backward_filename.push(get_current_dir_name());
			
			while (!forward_filename.empty()) {
        		forward_filename.pop();
    		}
			
			
			char *s = namelist_local[count]->d_name;
			count = 0;
			printf("\033c");
			ls_func(s);
			free(namelist_local[count]);
			printf("\033[%dA",(w.ws_row - 1));
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
		if(strcmp(root, get_current_dir_name()) == 0){
			return;
		}
		
		if ((stat(namelist_local[1]->d_name, &sb) == 0)&& S_ISDIR(sb.st_mode))
		{	
			backward_filename.push(get_current_dir_name());
			char *s = namelist_local[1]->d_name;
			printf("\033c");
			count = 0;
			ls_func(s);
			free(namelist_local[1]);
			printf("\033[%dA",(w.ws_row - 1));
		}
	}
	
	free(namelist_local);
}
