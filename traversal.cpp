#include "globalheader.h"

extern char c;
extern int count;
extern int count_MAX;
extern stack<char *> backward_filename;
extern stack <char *> forward_filename;

void traverse(){

	if (c==67) {
    	if(!forward_filename.empty()){
    		char *s = forward_filename.top();
			backward_filename.push(s);
    		forward_filename.pop();
			count = 0;
    	
    		printf("\033c");
			ls_func(s);
		
			printf("\033[%dA",(w.ws_row - 1));
		}
	
	}
    if (c==68){
    	if(!backward_filename.empty()){
    		char *s = backward_filename.top();
    		forward_filename.push(get_current_dir_name());
    		backward_filename.pop();
    		count = 0;
    		
    		printf("\033c");
			ls_func(s);
		
			printf("\033[%dA",(count_MAX));
		}
    }
}
