#include <string>
#include <cstring>
#include <iostream>
#include "config.h"
#include "log.h"

namespace llog{
	void error(const std::string& msg) noexcept{
		std::cerr << options::color_error << "-[X] " << msg << options::reset_color << "\n";
	}

	void print(const std::string& msg) noexcept{
		std::cout << msg << "\n";
	}

	void local_error(const std::string& path, const std::string& msg, const int& exit_code){
		llog::error(msg + " '" + path + "', " + std::strerror(errno));
		if(exit_code != NO_EXIT)
			exit(exit_code);
	}
}
