#include "lsfunc.h"

int ls_func(struct dirent **namelist){
	struct stat filename;
	
	int n;
	
	n = scandir(".", &namelist, NULL, alphasort);
	
	if (n == -1) {
		perror("scandir");
		return 1;
	}
	
	for(int i = 0; i<n; i++){
		stat(namelist[i]->d_name, &filename);
		
		printf("%s\t", namelist[i]->d_name);
		printf("%ld\t", filename.st_size);
		
		printf("%s\t",(getgrgid(filename.st_gid))->gr_name);
		printf("%s\t",(getpwuid(filename.st_uid))->pw_name);

        printf( (filename.st_mode & S_IRUSR) ? "r" : "-");
        printf( (filename.st_mode & S_IWUSR) ? "w" : "-");
        printf( (filename.st_mode & S_IXUSR) ? "x" : "-");
        printf( (filename.st_mode & S_IRGRP) ? "r" : "-");
        printf( (filename.st_mode & S_IWGRP) ? "w" : "-");
        printf( (filename.st_mode & S_IXGRP) ? "x" : "-");
        printf("\t");

		printf("%s\n", ctime(&filename.st_mtime));
		free(namelist[i]);
	}
	
	
	
	free(namelist);
	return 0;
}
