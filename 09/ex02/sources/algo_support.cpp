#include "PMergeMe.hpp"

template <typename Container>
size_t  binary_search(Container *main, int greatest_loser,
                      unsigned long pair_size, int min, int max)
{
  int mid_pair_index = ((min + max) / 2);
  int mid_element_index  = mid_pair_index * pair_size + (pair_size - 1);
  
  if (greatest_loser < (*main)[mid_element_index] || mid_element_index >= (int)main->size())
  {
    total_comparaisons++;
    max = mid_pair_index - 1;
  }
  else
    min = mid_pair_index + 1;
  if (min > max)
    return min * pair_size;
  return binary_search(main, greatest_loser, pair_size, min, max);
}

template <typename Container>
void  init_pend(Container *main, Container *pend, unsigned long pair_size)
{
  for (size_t pair_start_index = pair_size * 2;
      pair_start_index + pair_size <= main->size();
      pair_start_index += pair_size)
    transfer_range(main, pair_start_index, pair_size, pend, pend->size());
}

void set_current_jacob_data(bool is_first, t_current_jacob_data *current_jacob_data)
{
  current_jacob_data->previous_jacob_number = is_first ? 1 : current_jacob_data->jacob_number;
  current_jacob_data->jacob_number = compute_insertion_number(is_first);
  current_jacob_data->insertions_left = current_jacob_data->jacob_number - current_jacob_data->previous_jacob_number;
  current_jacob_data->maximal_insertion_index = current_jacob_data->jacob_number + current_jacob_data->previous_jacob_number - 1;
}

template <typename Container>
void set_loop_data(t_loop_data *loop_data, Container *pend, int insertions_left, unsigned int pair_size)
{
  loop_data->index_of_pair = (insertions_left - 1) * pair_size;
  if ((int)pend->size() <= loop_data->index_of_pair)
  {
    if (pend->size() == 0)
      loop_data->index_of_pair = 0;
    else
      loop_data->index_of_pair = pend->size() - pair_size;
  }
  loop_data->greatest_loser = (*pend)[loop_data->index_of_pair + pair_size - 1];
}

//insert at destination_index - 1
template <typename Container>
void  transfer_range(Container *source, size_t source_start_index, unsigned int source_size,
                      Container *destination, size_t destination_index)
{
  typename Container::iterator it = source->begin() + source_start_index;
  destination->insert(destination->begin() + destination_index, it, it + source_size);
  source->erase(it, it + source_size);
}
