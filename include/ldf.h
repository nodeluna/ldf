#ifndef LDF
#define LDF

#include <string>
#include <vector>

struct mnt{
	std::string dev;
	std::string mount;
};

std::vector<mnt> get_devices(void);

void line(void);

void rows(const std::string& dev, const std::string& size, const std::string& used, const std::string& available, 
		const std::string& usage, const std::string& mounted_on);

void ldf(const std::vector<mnt>& devs);

#endif // LDF
