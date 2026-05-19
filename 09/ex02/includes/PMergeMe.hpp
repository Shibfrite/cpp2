#include <algorithm>
#include <deque>
#include <string>
#include <cerrno>

#include "support.hpp"

#define SUCCESS 0
#define FAILURE 1

extern int total_comparaisons;

void	  swap_pair(std::deque<int>::iterator pair_start, int element_size);
size_t  sort_pairs(std::deque<int> *list, unsigned long pair_size);

int     compute_insertion_number(bool is_first);
void	  jacob_sort(std::deque<int> *main, unsigned long pair_size);
