#include "ScalarConverter.hpp"

int main() {
    ScalarConverter::convert("'a'");
    ScalarConverter::convert("999999999999999999942");
    ScalarConverter::convert("-7");
    ScalarConverter::convert("3.14f");
    ScalarConverter::convert("3.14");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("inf");
    ScalarConverter::convert("garbage");
}
