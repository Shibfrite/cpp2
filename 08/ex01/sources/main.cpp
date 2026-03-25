#include "Span.hpp"

int main(void)
{
  Span s(100000);
  //s.addNumber(2);
  //s.addNumber(7);
  //s.addNumber(21);
  //s.addNumber(211);
  //std::cout << s.shortestSpan() << std::endl;
  //std::cout << s.longestSpan() << std::endl;
  std::vector<int> v;
  for (int i = 0; i <= 10000; i++)
    v.push_back(i);
  try {
    s.addRange(v.begin(), v.end());
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << s.shortestSpan() << std::endl;
  std::cout << s.longestSpan() << std::endl;
	return (0);
}
