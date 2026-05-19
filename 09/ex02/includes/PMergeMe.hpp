#include <algorithm>
#include <deque>
#include <string>
#include <cerrno>

#include "support.hpp"

#define SUCCESS 0
#define FAILURE 1

extern int total_comparaisons;

template <typename Container>
void	  swap_pair(typename Container::iterator pair_start, int element_size);
template <typename Container>
size_t  sort_pairs(Container *list, unsigned long pair_size);

int     compute_insertion_number(bool is_first);
template <typename Container>
void	  jacob_sort(Container *main, unsigned long pair_size);
