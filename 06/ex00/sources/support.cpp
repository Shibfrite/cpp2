#include "support.hpp"

std::string to_str(int v) {
	std::ostringstream ss;
	ss << v;
	return ss.str();
}

std::string to_str(float v) {
	std::ostringstream ss;
	ss << v;
	return ss.str();
}

std::string to_str(double v) {
	std::ostringstream ss;
	ss << v;
	return ss.str();
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}

bool isPrintable(char c){
	return c >= 32 && c <= 126;
}
