#pragma once

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<numeric>

class Span
{
	private:
    unsigned int      _n;
    std::vector<int>  _vec;
	public:
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span(void);
    void  addNumber(int number);
    template<typename InputIterator>
    void  addRange(InputIterator first, InputIterator last);
    int  shortestSpan(void);
    int  longestSpan(void);
};

template<typename InputIterator>
void Span::addRange(InputIterator first, InputIterator last) {
  if (_vec.size() + std::distance(first, last) > _n)
      throw std::exception();
  _vec.insert(_vec.end(), first, last);
}
