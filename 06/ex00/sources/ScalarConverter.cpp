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

static enum e_types determinType(std::string literal){
  bool (*typeDetectionFunctions[])(std::string) = {isChar, isInt, isDouble, isFloat};

  if (!literal.empty())
    for (int i = 0; i < NUM_TYPES; i++)
      if (typeDetectionFunctions[i](literal))
        return (e_types)i;
  throw Exception(ERR_MSG_OUT_OF_RANGE);
}

bool isPrintable(char c){
    return c >= 32 && c <= 126;
}

union u_values  fromChar(std::string literal){
  return (u_values){.c = literal[1]};
}

union u_values  fromInt(std::string literal){
  union u_values  result;

  result.i = (int)strtol(literal.c_str(), NULL, 10);
  if (errno == ERANGE)
  {
    errno = 0;
    throw Exception(ERR_MSG_OUT_OF_RANGE);
  }
  return result.i;
}

union u_values  fromFloat(){
  union u_values  result;

  result.f = strtof(literal.c_str(), NULL);
  if (errno == ERANGE)
  {
    errno = 0;
    throw Exception(ERR_MSG_OUT_OF_RANGE);
  }
  return result.f;
}

union u_values  fromDouble(std::string literal){
  union u_values  result;

  result.d = strtod(literal.c_str(), NULL);
  if (errno == ERANGE)
  {
    errno = 0;
    throw Exception(ERR_MSG_OUT_OF_RANGE);
  }
  return result.d;
}

std::string toChar(t_data data) {
    long val;
    switch (data.type) {
        case CHAR:   val = static_cast<long>(data.value.c); break;
        case INT:    val = static_cast<long>(data.value.i); break;
        case FLOAT:  val = static_cast<long>(data.value.f); break;
        case DOUBLE: val = static_cast<long>(data.value.d); break;
    }
    if (val < 0 || val > 127)
        return ERR_MSG_OUT_OF_RANGE;
    if (!isPrintable(static_cast<char>(val)))
        return ERR_MSG_UNPRINTABLE;
    return std::string(1, static_cast<char>(val));
}

std::string toInt(t_data data) {
    long val;
    switch (data.type) {
        case CHAR:   val = static_cast<long>(data.value.c); break;
        case INT:    val = static_cast<long>(data.value.i); break;
        case FLOAT:  val = static_cast<long>(data.value.f); break;
        case DOUBLE: val = static_cast<long>(data.value.d); break;
    }
    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        return ERR_MSG_OUT_OF_RANGE;
    return std::to_string(static_cast<int>(val));
}

std::string toFloat(t_data data) {
    float val;
    switch (data.type) {
        case CHAR:   val = static_cast<float>(data.value.c); break;
        case INT:    val = static_cast<float>(data.value.i); break;
        case FLOAT:  val = data.value.f; break;
        case DOUBLE: val = static_cast<float>(data.value.d); break;
    }
    return std::to_string(static_cast<float>(val));
}

std::string toDouble(t_data data) {
    double val;
    switch (data.type) {
        case CHAR:   val = static_cast<double>(data.value.c); break;
        case INT:    val = static_cast<double>(data.value.i); break;
        case FLOAT:  val = static_cast<double>(data.value.f); break;
        case DOUBLE: val = data.value.d; break;
    }
    return std::to_string(static_cast<double>(val));
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

void  ScalarConverter::convert(std::string literal){
  t_data      convertedData;
  std::string outputs[NUM_TYPES];

  u_values    (*convertFrom[])(std::string) = {fromChar, fromInt, fromDouble, fromFloat};
  std::string (*convertTo[])(std::string) = {toChar, toInt, toDouble, toFloat};

  try{
    convertedData.type = determinType(literal);
    convertedData.value = convertFrom[convertedData.type](literal);
  } catch (const std::exception& e){
    print(ERR_TOO_EARLY + e.what());
    return ;
  }
  for (int i = 0; i < NUM_TYPES; i++)
    outputs[i] = convertTo[i](convertedData);
  printConvertedValues(outputs);
}
