#include "support.hpp"

std::string to_str(int v)
{
    std::ostringstream ss;
    ss << v;
    return ss.str();
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}

void	print_error(std::string str)
{
	std::cerr << str << std::endl;
}
