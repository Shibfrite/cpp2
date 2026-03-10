#include "ScalarConverter.hpp"
#include "support.hpp"

ScalarConverter::ScalarConverter(void){}
ScalarConverter::ScalarConverter(const ScalarConverter& other){(void)other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){(void)other;return *this;}
ScalarConverter::~ScalarConverter(void){}

static enum e_types determinType(const std::string literal){
  bool (*typeDetectionFunctions[])(const std::string&) = {isChar, isInt, isFloat, isDouble};

  if (!literal.empty())
    for (int i = 0; i < NUM_TYPES; i++)
      if (typeDetectionFunctions[i](literal))
        return (e_types)i;
  throw Exception(ERR_MSG_NO_TYPE);
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

  u_values    (*convertFrom[])(const std::string) = {fromChar, fromInt, fromFloat, fromDouble};
  std::string (*convertTo[])(t_data) = {toChar, toInt, toFloat, toDouble};
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
