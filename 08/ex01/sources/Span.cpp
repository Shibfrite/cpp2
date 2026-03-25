#include "Span.hpp"
#include "support.hpp"

Span::Span(unsigned int n) : _n(n) {
  _vec.reserve(n);
}

Span::Span(const Span& other) {
  if (this != &other)
  {
    _n = other._n;
    _vec.reserve(_n);
  }
}

Span& Span::operator=(const Span& other) {
  if (this != &other)
  {
    _n = other._n;
    _vec.reserve(_n);
  }
  return *this;
}

Span::~Span(void) {}

void  Span::addNumber(int number) {
  if (_vec.size() >= _n)
    throw std::exception();
  _vec.push_back(number);
}

int  Span::shortestSpan(void) {
  size_t  smallest_difference;

  if (_vec.size() < 2)
    throw std::exception();
  std::vector<int> differences(_vec.size());

  std::sort(_vec.begin(), _vec.end());
  std::adjacent_difference(_vec.begin(), _vec.end(), differences.begin());
  smallest_difference = *std::min_element(differences.begin() + 1, differences.end());

  return (smallest_difference);
}

int  Span::longestSpan(void) {
  int     smallest_value, largest_value;
  size_t  largest_difference;

  if (_vec.size() < 2)
    throw std::exception();
  
  smallest_value = *std::min_element(_vec.begin(), _vec.end());
  largest_value = *std::max_element(_vec.begin(), _vec.end());
  largest_difference = largest_value - smallest_value;

  return (largest_difference);
}
