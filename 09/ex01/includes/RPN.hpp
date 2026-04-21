#pragma once

#include "support.hpp"
//#include <iostream>
//#include <string>
#include <algorithm>
//#include <cstdlib>
//#include <fstream>
//#include <exception>
//#include <cerrno>
#include <stack>

#define SUCCESS 0
#define FAILURE 1

#define OPERATORS std::string("+-*/")

enum e_token_type
{
  INVALID,
  EMPTY,
  SPACE,
  DIGIT,
  OPERATOR
};
