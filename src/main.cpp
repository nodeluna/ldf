#include <vector>
#include "ldf.h"
#include "ram.h"
#include "log.h"
#include "cliargs.h"
#include "config.h"


int main(const int argc, const char* argv[]){
	cliargs(argc, argv);

	if(options::devices){
		std::vector<mnt> devs = get_devices();
		ldf(devs);
		llog::print("\n");
	}

	if(options::ram){
		ram_usage();
		llog::print("\n");
	}

	if(options::swap){
		swap_usage();
		llog::print("\n");
	}

	if(!options::devices && !options::ram && !options::swap)
		llog::print("-[!] devices, ram and swap info has been disabled");

	return 0;
}
