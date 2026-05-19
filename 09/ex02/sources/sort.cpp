#include "PMergeMe.hpp"

void	swap_pair(std::deque<int>::iterator pair_start, int element_size)
{
	int greatest_elements[2];
	greatest_elements[0] = pair_start[element_size - 1];
	greatest_elements[1] = pair_start[(2 * element_size) - 1];
  total_comparaisons++;
	if (greatest_elements[0] > greatest_elements[1])
		std::rotate(pair_start, pair_start + element_size, pair_start + 2 * element_size);
}

size_t  sort_pairs(std::deque<int> *list, unsigned long pair_size)
{
  if (pair_size < 1) return 0;
  else if (pair_size != 1)
    for (size_t pair_start_index = 0; pair_start_index + pair_size <= list->size(); pair_start_index += pair_size)
      swap_pair(list->begin() + pair_start_index, pair_size / 2);

  unsigned int next_pair_size = pair_size * 2;
	if (next_pair_size > list->size())
		return pair_size;
	return sort_pairs(list, next_pair_size);
}

int compute_insertion_number(bool is_first)
{
  static int jacob_number = 1;
  static int power_of_two = 2;
  if (is_first)
  {
   jacob_number = 1;
   power_of_two = 2;
  }
  power_of_two *= 2;
  jacob_number = power_of_two - jacob_number;
  return jacob_number;
}

void	jacob_sort(std::deque<int> *main, unsigned long pair_size)
{
  std::deque<int>       pend;
  t_current_jacob_data  current_jacob_data;
  t_loop_data           loop_data;
  size_t                insertion_index;
  int                   number_of_insertions = 1;

  init_pend(main, &pend, pair_size);

  set_current_jacob_data(true, &current_jacob_data);
  set_loop_data(&loop_data, &pend, current_jacob_data.insertions_left, pair_size);

  while (pend.size() >= pair_size)
  {
    if (!current_jacob_data.insertions_left)
      set_current_jacob_data(false, &current_jacob_data);
    set_loop_data(&loop_data, &pend, current_jacob_data.insertions_left, pair_size);
    insertion_index = binary_search(main, loop_data.greatest_loser, pair_size, 0, current_jacob_data.maximal_insertion_index);

    transfer_range(&pend, loop_data.index_of_pair, pair_size, main, insertion_index);

    if ((unsigned long)insertion_index == current_jacob_data.maximal_insertion_index * pair_size)
      current_jacob_data.maximal_insertion_index--;
    current_jacob_data.insertions_left--;
    number_of_insertions++;
  }
  if (pair_size == 1) return ;
  jacob_sort(main, pair_size / 2);
}
