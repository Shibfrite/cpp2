#include "support.hpp"

bool is_sorted(std::deque<int> list)
{
  for (std::deque<int>::iterator it = list.begin();it != list.end(); it++)
    if (it != list.begin() && *it < *(it - 1))
      return false;
  return true;
}

void fillDequeWithRandom(std::deque<int>& dq, int min, int max, std::size_t count) {
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

