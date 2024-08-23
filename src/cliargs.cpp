#include <string>
#include "cliargs.h"
#include "log.h"
#include "about.h"
#include "config.h"


bool next_arg(const int argc, const char* argv[], int index){
	if((argc-1) == index)
		return true;

	std::string argument = argv[index+1];
	if(argument == "on")
		return true;
	else if(argument == "off")
		return false;
	else{
		std::string option = argv[index];
		llog::error("unrecognized argument '" + argument + "' for option '" + option + "', read the man page");
		exit(1);
	}
}

void cliargs(const int argc, const char* argv[]){
	int i = 1;
	while(i < argc){
		std::string option = argv[i];
		if(option == "--ram" || option == "-r")
			options::ram = next_arg(argc, argv, i);
		else if(option == "--swap" || option == "-s")
			options::swap = next_arg(argc, argv, i);
		else if(option == "--devices" || option == "-d")
			options::devices = next_arg(argc, argv, i);
		else if(option == "--author"){
			llog::print(about::author);
			exit(0);
		}else if(option == "--license"){
			llog::print(about::license);
			exit(0);
		}else if(option == "--version" || option == "-V"){
			llog::print(about::version);
			exit(0);
		}else if(option == "--help"){
			llog::print(about::help);
			exit(0);
		}else if(option != "on" && option != "off"){
			llog::error("unrecognized option. read the man page");
			exit(1);
		}
		i++;
	}
}
