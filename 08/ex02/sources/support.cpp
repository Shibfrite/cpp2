#include "support.hpp"

std::string to_str(int v) {
    std::ostringstream ss;
    ss << v;
    return ss.str();
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}
