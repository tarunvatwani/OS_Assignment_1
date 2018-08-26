#include "traversal.h"

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
    	
    		printf("\033c");
			count_MAX = ls_func(s);
		
			printf("\033[%dA",(count_MAX));
			count = 0;
		}
	
	}
    if (c==68){
    	if(!backward_filename.empty()){
    		char *s = backward_filename.top();
    		forward_filename.push(s);
    		backward_filename.pop();
    	
    		printf("\033c");
			count_MAX = ls_func(s);
		
			printf("\033[%dA",(count_MAX));
			count = 0;
		}
    }
}
