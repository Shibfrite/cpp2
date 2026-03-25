template<typename T>
typename T::iterator easyfind(T container, int target){
  typename T::iterator iterator;

  iterator = std::find(container.begin(), container.end(), target);
  if (iterator == container.end())
    throw std::exception();
  return iterator;
}
