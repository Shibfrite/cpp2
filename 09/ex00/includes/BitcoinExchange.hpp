#pragma once

#include "support.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <exception>
#include <map>
#include <cerrno>

#define CSV_FILE "includes/data.csv"
#define DATE_SEPARATOR '-'
#define VALUES_SEPARATOR ','
#define SUCCESS 0
#define FAILURE 1

enum timeUnit {
  YEAR,
  MONTH,
  DAY
};

class MyException : public std::exception {
  std::string _msg;
public:
  MyException(std::string msg);
  ~MyException() throw();
  const char *what() const throw();
};

std::map<std::string, float> parseCsv(std::string csv_file);
