#include <cstdint>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <filesystem>
#include <mntent.h>
#include <cstring>
#include <vector>
#include "units.h"
#include "log.h"
#include "about.h"
#include "ldf.h"
#include "term.h"

int fill = 22;

bool include_dev(const std::string& dev){
	if(dev.size() > 4 && dev.substr(0, 5) == "/dev/")
		return true;
	return false;
}

std::vector<mnt> get_devices(void){
	FILE* mnt_fp;
	const struct mntent* mntent;
	std::vector<mnt> devs;
	struct mnt pmnt;

	mnt_fp = setmntent("/etc/mtab", "r");
	if(mnt_fp == NULL)
		llog::local_error("/etc/mtab", "couldn't get mounted devices in", EXIT_FAILURE);

	while((mntent = getmntent(mnt_fp)) != NULL){
		pmnt.dev = mntent->mnt_fsname;
		pmnt.mount = mntent->mnt_dir;
		if(include_dev(pmnt.dev))
			devs.push_back(pmnt);
	}
	
	endmntent(mnt_fp);
	return devs;
}

void line(void){
	std::cout << std::left << std::setw(terminal_size().ws_col) << std::setfill('-') << ""  << std::setfill(' ') << "\n";
}

void rows(const std::string& dev, const std::string& size, const std::string& used, const std::string& available, 
		const std::string& usage, const std::string& mounted_on){

	std::cout << "\x1b[1;32m" <<
		std::left << std::setw(fill) << dev << "\x1b[1;0m" <<
		std::left << std::setw(fill) << size << "\x1b[1;32m" <<
		std::left << std::setw(fill) << used << "\x1b[1;0m" <<
		std::left << std::setw(fill) << available << "\x1b[1;32m" <<
		std::left << std::setw(fill) << usage << "\x1b[1;0m" <<
		std::left << std::setw(fill) << mounted_on <<"\n";
}

void ldf(const std::vector<mnt>& devs){
	struct winsize w = terminal_size();
	fill = w.ws_col / 6;
	line();
	rows("device", "size", "used", "availabe", "usage %", "mounted on");
	line();

	std::uintmax_t size = 0, used = 0, available = 0;
	for(const auto& dev : devs){
		std::filesystem::space_info si = std::filesystem::space(dev.mount);

		rows(dev.dev, size_units(si.capacity), size_units(si.capacity - si.available), size_units(si.available),
				decimal_precision(percentage(si.capacity - si.available, si.capacity), 2), dev.mount);

		size += si.capacity;
		used += (si.capacity - si.available);
		available += si.available;
	}

	line();
	rows("total", size_units(size), size_units(used), size_units(available), decimal_precision(percentage(used, size), 2), "-");
	line();
}
