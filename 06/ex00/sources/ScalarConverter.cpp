#include "ScalarConverter.hpp"
#include "support.hpp"

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){}

ScalarConverter::~ScalarConverter(void){}

static std::string trimQuotes(const std::string& literal) {
    size_t len = literal.length();
    bool isntQuoted = (len < 2 || literal[0] != literal[len - 1] || (literal[0] != '\'' && literal[0] != '"'));
    if (isntQuoted)
        return literal;
    return literal.substr(1, len - 2);
}

static bool isChar(const std::string& s) {
    return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

static bool isInt(const std::string& s) {
    bool sign = (s[0] == '+' || s[0] == '-');
    if (sign && s.length() == 1) return false;
    for (size_t i = (size_t)sign; i < s.length(); ++i)
        if (s[i] < '0' || s[i] > '9') return false;
    return true;
}

static enum e_types determinType(std::string literal) const{
  bool (*typeDetectionFunctions[])(std::string) = {isChar, isInt, isDouble, isFloat};

  if (!s.empty())
    for (int i = 0; i < sizeof(typeDetectionFunctions); i++)
      if (typeDetectionFunctions[i](literal))
        return (e_types)i;
  throw ScalarConverter::Exception(ERROR_MSG_NO_VALID_TYPE);
}

static void  fromChar(std::string){
  char  charValue;
  
}

static void  printConvertedValues(void){
  print("char: " + _char);
  print("int: " + _int);
  print("float: " + _float);
  print("double: " + _double);
}

void  ScalarConverter::convert(std::string literal){
  enum e_types type;
  void (*convertionFunctions[])(std::string) = {fromChar, fromInt, fromDouble, fromFloat};

  literal = trimQuotes(literal);
  type = determinType(literal);
  convertionFunctions[(size_t)type](literal);
  printConvertedValues();
}
