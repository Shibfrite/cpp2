#include "easyfind.hpp"

template<typename T>
typename T::const_iterator easyfind(T container, int target){
  typename T::const_iterator iterator;

  iterator = std::find(container.begin(), container.end(), target);
  if (iterator == container.end())
    throw std::exception();
  return iterator;
}
