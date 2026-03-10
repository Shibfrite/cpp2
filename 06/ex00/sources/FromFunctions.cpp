#include "ScalarConverter.hpp"
#include "support.hpp"

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

/*
t_data fromPseudo(const std::string& s) {
    t_data result;
    if (s[s.length() - 1] == 'f') {
        result.type = FLOAT;
        result.value.f = strtof(s.c_str(), NULL);
    } else {
        result.type = DOUBLE;
        result.value.d = strtod(s.c_str(), NULL);
    }
    return result;
}*/
