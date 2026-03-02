#pragma once

#include<iostream>
#include<string>

enum e_types{
  CHAR,
  INT,
  FLOAT,
  DOUBLE
};

class ScalarConverter
{
	private:
    e_types     _type;
    std::string _char;
    std::string _int;
    std::string _float;
    std::string _double;
	public:
		virtual ScalarConverter(void) = 0;
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter(void);
    convert(std::string literal) const;
    class Exception : public std::exception {
      private:
        std::string msg;
      public:
        Exception(const std::string& m) : msg(m) {}
        const char* what() const noexcept override { return msg.c_str(); }
    };
};
