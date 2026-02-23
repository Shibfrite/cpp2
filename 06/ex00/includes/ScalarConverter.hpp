#pragma once

#include<iostream>
#include<string>

class ScalarConverter
{
	private:
	public:
		virtual ScalarConverter(void) = 0;
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter(void);
    convert(std::string literal) const;
};
