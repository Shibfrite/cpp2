#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	/*
    ScalarConverter::convert("'a'");
    ScalarConverter::convert("999999999999999999942");
    ScalarConverter::convert("-7");
    ScalarConverter::convert("3.14f");
    ScalarConverter::convert("3.14");
    ScalarConverter::convert("3.0");
    ScalarConverter::convert("0");
    ScalarConverter::convert("42");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("inf");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("inff");
    ScalarConverter::convert("1e308");
    ScalarConverter::convert("garbage");*/
    if (ac != 2)
        return 1;
    ScalarConverter::convert(av[1]);
    return 0;
}
