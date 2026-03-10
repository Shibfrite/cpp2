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

static enum e_types determinType(const std::string literal){
  bool (*typeDetectionFunctions[])(const std::string&) = {isChar, isInt, isDouble, isFloat};

  if (!literal.empty())
    for (int i = 0; i < NUM_TYPES; i++)
      if (typeDetectionFunctions[i](literal))
        return (e_types)i;
  throw Exception(ERR_MSG_OUT_OF_RANGE);
}

bool isPrintable(char c){
    return c >= 32 && c <= 126;
}

union u_values  fromChar(const std::string literal){
  union u_values  result;
  result.c = literal[1];
  return result;
}

union u_values  fromInt(const std::string literal){
  union u_values  result;

  errno = 0;
  result.i = (int)strtol(literal.c_str(), NULL, 10);
  if (errno == ERANGE)
    throw Exception(ERR_MSG_OUT_OF_RANGE);
  return result;
}

union u_values  fromFloat(const std::string literal){
  union u_values  result;

  errno = 0;
  result.f = strtof(literal.c_str(), NULL);
  if (errno == ERANGE)
    throw Exception(ERR_MSG_OUT_OF_RANGE);
  return result;
}

union u_values  fromDouble(const std::string literal){
  union u_values  result;

  errno = 0;
  result.d = strtod(literal.c_str(), NULL);
  if (errno == ERANGE)
    throw Exception(ERR_MSG_OUT_OF_RANGE);
  return result;
}

std::string toChar(t_data data) {
    long val = -1;
    switch (data.type) {
        case CHAR:   val = static_cast<long>(data.value.c); break;
        case INT:    val = static_cast<long>(data.value.i); break;
        case FLOAT:  val = static_cast<long>(data.value.f); break;
        case DOUBLE: val = static_cast<long>(data.value.d); break;
        default: break;
    }
    if (val < 0 || val > 127)
        return ERR_MSG_IMPOSSIBLE;
    if (!isPrintable(static_cast<char>(val)))
        return ERR_MSG_UNPRINTABLE;
    return std::string(1, static_cast<char>(val));
}

std::string toInt(t_data data) {
    long val = -1;
    switch (data.type) {
        case CHAR:   val = static_cast<long>(data.value.c); break;
        case INT:    val = static_cast<long>(data.value.i); break;
        case FLOAT:  val = static_cast<long>(data.value.f); break;
        case DOUBLE: val = static_cast<long>(data.value.d); break;
        default: break;
    }
    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        return ERR_MSG_IMPOSSIBLE;
    return to_str(static_cast<int>(val));
}

std::string toFloat(t_data data) {
    float val = -1;
    switch (data.type) {
        case CHAR:   val = static_cast<float>(data.value.c); break;
        case INT:    val = static_cast<float>(data.value.i); break;
        case FLOAT:  val = data.value.f; break;
        case DOUBLE: val = static_cast<float>(data.value.d); break;
        default: break;
    }
    return to_str(static_cast<float>(val));
}

std::string toDouble(t_data data) {
    double val = -1;
    switch (data.type) {
        case CHAR:   val = static_cast<double>(data.value.c); break;
        case INT:    val = static_cast<double>(data.value.i); break;
        case FLOAT:  val = static_cast<double>(data.value.f); break;
        case DOUBLE: val = data.value.d; break;
        default: break;
    }
    return to_str(static_cast<double>(val));
}

static void printConvertedValues(std::string outputs[NUM_TYPES]) {
    print("char: " + outputs[CHAR]);
    print("int: " + outputs[INT]);
    print("float: " + outputs[FLOAT]);
    print("double: " + outputs[DOUBLE]);
}

void  ScalarConverter::convert(std::string literal){
  t_data      convertedData;
  std::string outputs[NUM_TYPES];

  u_values    (*convertFrom[])(const std::string) = {fromChar, fromInt, fromDouble, fromFloat};
  std::string (*convertTo[])(t_data) = {toChar, toInt, toDouble, toFloat};

  try{
    convertedData.type = determinType(literal);
    convertedData.value = convertFrom[convertedData.type](literal);
  } catch (const std::exception& e){
    print(std::string(ERR_TOO_EARLY) + e.what());
    return ;
  }
  for (int i = 0; i < NUM_TYPES; i++)
    outputs[i] = convertTo[i](convertedData);
  printConvertedValues(outputs);
}
