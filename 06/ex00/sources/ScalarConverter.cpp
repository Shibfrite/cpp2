#include "ScalarConverter.hpp"
#include "support.hpp"

ScalarConverter::ScalarConverter(void){}
ScalarConverter::ScalarConverter(const ScalarConverter& other){(void)other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){(void)other;return *this;}
ScalarConverter::~ScalarConverter(void){}

static bool isChar(const std::string& s) {
  return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

static bool isInt(const std::string& s) {
  char* end;
  strtol(s.c_str(), &end, 10);
  return *end == '\0';
}

static bool isFloat(const std::string& s) {
  char* end;
  strtof(s.c_str(), &end);
  return *end == 'f' && *(end + 1) == '\0';
}

static bool isDouble(const std::string& s) {
  char* end;
  strtod(s.c_str(), &end);
  return *end == '\0';
}

static enum e_types determinType(std::string literal){
  bool (*typeDetectionFunctions[])(const std::string&) = {isChar, isInt, isFloat, isDouble};

  if (!literal.empty())
      for (int i = 0; i < NUM_TYPES; i++)
          if (typeDetectionFunctions[i](literal))
              return (e_types)i;
  throw Exception(ERR_MSG_OUT_OF_RANGE);
}

void ScalarConverter::convert(std::string literal){
  enum e_types type;
  try {
      type = determinType(literal);
      print("Detected type: " + to_str((int)type));
  } catch (const std::exception& e){
      print(std::string("Detection failed: ") + e.what());
  }
}
