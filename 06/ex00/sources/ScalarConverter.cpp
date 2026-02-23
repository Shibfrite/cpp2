#include "ScalarConverter.hpp"
#include "support.hpp"

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){}

ScalarConverter::~ScalarConverter(void){}

int  isValidQuote(std::string literal) const{
  if (literal.length() != 3)
    return (0);
}
static std::string toChar(std::string literal) const{
  if (literal.length() > 1 && !isValidQuote())
      return (IMPOSSIBLE);
  
}
static std::string toDigit(std::string literal) const;
static std::string toFloat(std::string literal) const;
static std::string toDouble(std::string literal) const;

void  ScalarConverter::convert(std::string literal) const{
  enum type = checkType
  print("char: ");
  print(toChar(literal));
  print("int: ");
  print(toDigit(literal));
  print("float: ");
  print(toFloat(literal));
  print("double: ");
  print(toDouble(literal));
}
