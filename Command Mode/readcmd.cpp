#include "globalcmdmode.h"

extern char c;
extern vector <string> command_vector;
extern struct termios initial_settings;

void read_cmd(){
	
	command_vector.clear();
	
	char x;
	string cmd;
	
	cout<<c;

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
	
		
	if(c != cmd[0]){
		string dummy(1,c);        //Adjustment for first charcter
		cmd.insert(0,dummy);      //Input
	}

	
	istringstream stream(cmd); 
	
	string argument;
	
	while(stream>>argument)
		command_vector.push_back(argument);
		
}