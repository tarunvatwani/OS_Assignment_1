#include "globalheader.h"

extern char c;
extern char* root;
extern vector <string> command_vector;
extern struct termios initial_settings;

void read_cmd(){
	
	command_vector.clear();
	
	char x;
	string cmd;
	
	if(c == '\n'){
		cout<<"\33[2K\r";
	}
	else{
		cout<<c;
	}

	while(1){
		x = getchar();
		
		if(x == '\n'){
			cout<<"\33[2K\r";
			break;
		}
		else if(x == 127){
			cout<<"\33[2K\r";
			cmd.clear();
		}
		else{
			cout<<x;
			cmd.push_back(x);		
		}
	}
	
		
	if( c != cmd[0] && (!(cmd.empty())) ){
		string dummy(1,c);        			//Adjustment for first charcter
		cmd.insert(0,dummy);	  			//Input
	}
	
	if(!(cmd.empty())){
		istringstream stream(cmd); 
		string argument;
	
		while(stream>>argument)
			command_vector.push_back(argument);
	}

	
	int argc = command_vector.size();
	
	for(int i = 1; i<(argc); i++){
		size_t pos = command_vector[i].find("~/");
		if((pos != string::npos)){
			command_vector[i].replace(pos,1,root);
		}
		
		pos = command_vector[i].find("/root/");
		if((pos != string::npos)){
			command_vector[i].replace(pos,5,root);
		}
		
		if(command_vector[i].compare("/") == 0){
			command_vector[i] = root;
		}	
	}		
}
