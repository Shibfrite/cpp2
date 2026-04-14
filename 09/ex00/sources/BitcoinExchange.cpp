#include "BitcoinExchange.hpp"
#include "support.hpp"

MyException::MyException(std::string msg) : _msg(msg) {}
MyException::~MyException() throw() {}
const char *MyException::what() const throw() { return _msg.c_str(); }
