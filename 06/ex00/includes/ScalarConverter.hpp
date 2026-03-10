#pragma once

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<limits>

#define ERR_MSG_OUT_OF_RANGE "out of range"
#define ERR_MSG_IMPOSSIBLE "impossible"
#define ERR_MSG_UNPRINTABLE "unprintable"
#define ERR_TOO_EARLY "Early error:"

enum e_types{
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  NUM_TYPES
};

union u_values{
  char    c;
  int     i;
  float   f;
  double  d;
};

typedef struct s_data{
  enum e_types type;
  union u_values value;
} t_data;

class Exception : public std::exception {
  private:
    std::string msg;
  public:
    Exception(const std::string& m) : msg(m) {}
    const char* what() const throw() { return msg.c_str(); }
    virtual ~Exception() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {}
};

class ScalarConverter
{
	private:
    //t_data      _convertedData;
    std::string _char;
    std::string _int;
    std::string _float;
    std::string _double;
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter(void);
	public:
    static void convert(std::string literal);
};
