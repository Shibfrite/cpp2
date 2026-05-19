#include "support.hpp"

template <typename Container>
bool is_sorted(Container list)
{
  for (typename Container::iterator it = list.begin();it != list.end(); it++)
    if (it != list.begin() && *it < *(it - 1))
      return false;
  return true;
}

template <typename Container>
void fillDequeWithRandom(Container& dq, int min, int max, std::size_t count) {
    dq.clear();
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        seeded = true;
    }
    dq.resize(count);
    for (std::size_t i = 0; i < count; ++i) {
        int range = max - min + 1;
        int randomValue = min + (std::rand() % range);
        dq[i] = randomValue;
    }
}

template <typename Container>
void	print(Container list)
{
	for (size_t i = 0; i < list.size(); i++)
    std::cout << to_str(list[i]) << " ";
  print("");
}
