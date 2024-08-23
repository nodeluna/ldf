#include <sys/sysinfo.h>
#include "ram.h"
#include "ldf.h"
#include "progress.h"
#include "log.h"

void ram_usage(void){
	struct sysinfo si;
	if(sysinfo(&si) != 0){
		llog::error("couldn't get RAM info, " + std::string(std::strerror(errno)));
		return;
	}

	line();
	rows("RAM", "", "", "usage", "", "");
	line();
	progress_bar(si.totalram, si.totalram - si.freeram);
	line();
}

void swap_usage(void){
	struct sysinfo si;
	if(sysinfo(&si) != 0){
		llog::error("couldn't get SWAP info, " + std::string(std::strerror(errno)));
		return;
	}

	line();
	rows("SWAP", "", "", "usage", "", "");
	line();
	progress_bar(si.totalswap, si.totalswap - si.freeswap);
	line();
}
