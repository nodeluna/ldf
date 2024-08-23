#ifndef CONFIG
#define CONFIG

#include <string>

namespace options{
	inline bool devices = true;
	inline bool ram = true;
	inline bool swap = true;
	inline std::string color_error = "\x1b[1;31m";
	inline std::string reset_color = "\x1b[0m";
}

#endif // CONFIG
