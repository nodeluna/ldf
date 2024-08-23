#ifndef UNITS
#define UNITS

#include <string>
#include <cstdint>

std::string decimal_precision(const double& number, const int& percision);

std::string size_units(const std::uintmax_t& bytes);

double percentage(const std::uintmax_t& x, const std::uintmax_t t);

#endif // UNITS
