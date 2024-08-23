#ifndef LUNA_LOG
#define LUNA_LOG

#include <string>
#include <cstdlib>
#include <cstring>

#define NO_EXIT -1

namespace llog{
	void error(const std::string& msg) noexcept;

	void print(const std::string& msg) noexcept;

	void local_error(const std::string& path, const std::string& msg, const int& exit_code);
}

#endif // LUNA_LOG
