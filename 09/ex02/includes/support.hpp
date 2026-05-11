#pragma once

#include <string>
#include <iostream>
#include <sstream>

std::string	to_str(int n);
std::string to_str(float n);
void		print(std::string str);
void		print(int n);
void	  print(char c);
void	  print_bool(bool value);
void		print_error(std::string str);

#include <deque>
#include <cstdlib>
#include <ctime>

bool    is_sorted(std::deque<int> list);
void    fillDequeWithRandom(std::deque<int>& dq, int min, int max, std::size_t count);
