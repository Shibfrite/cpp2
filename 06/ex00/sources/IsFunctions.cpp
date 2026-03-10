#include "ScalarConverter.hpp"
#include "support.hpp"

bool isChar(const std::string& s) {
  return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

bool isInt(const std::string& s) {
  char* end;
  strtol(s.c_str(), &end, 10);
  return *end == '\0';
}

bool isFloat(const std::string& s) {
  char* end;
  strtof(s.c_str(), &end);
  return *end == 'f' && *(end + 1) == '\0';
}

bool isDouble(const std::string& s) {
  char* end;
  strtod(s.c_str(), &end);
  return *end == '\0';
}

/*
bool isPseudo(const std::string& s) {
    return s == "nan" || s == "nanf"
        || s == "+inf" || s == "-inf"
        || s == "+inff" || s == "-inff";
}*/
