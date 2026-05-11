#include "PMergeMe.hpp"

std::deque<int>	parse_input(char **input)
{
	std::deque<int>	result;
	int				      number;
	char				    *endptr;
	errno = 0;
	while (*input)
	{
		number = std::strtol(*input, &endptr, 10);
		if (errno != 0 || endptr == *input || *endptr != '\0')
			throw std::exception();
		result.push_back(number);
		input++;
	}
	return (result);
}

void	print_deque(std::deque<int> list)
{
	for (size_t i = 0; i < list.size(); i++)
    std::cout << to_str(list[i]) << " ";
  print("");
}

void	sort_pair(std::deque<int>::iterator pair_start, int element_size)
{
	int greatest_elements[2];
	greatest_elements[0] = pair_start[element_size - 1];
	greatest_elements[1] = pair_start[(2 * element_size) - 1];
	if (greatest_elements[0] > greatest_elements[1])
		std::rotate(pair_start, pair_start + element_size, pair_start + 2 * element_size);
}

size_t  sort_pairs(std::deque<int> *list, unsigned long pair_size)
{
  if (pair_size < 1) return 0;
  else if (pair_size != 1)
    for (size_t pair_start_index = 0; pair_start_index + pair_size <= list->size(); pair_start_index += pair_size)
      sort_pair(list->begin() + pair_start_index, pair_size / 2);

  unsigned int next_pair_size = pair_size * 2;
	if (next_pair_size > list->size())
		return pair_size;
	return sort_pairs(list, next_pair_size);
}

//insert at destination_index - 1
void  transfer_range(std::deque<int> *source, size_t source_start_index, unsigned int source_size,
                      std::deque<int> *destination, size_t destination_index)
{
  std::deque<int>::iterator it = source->begin() + source_start_index;
  destination->insert(destination->begin() + destination_index, it, it + source_size);
  source->erase(it, it + source_size);
}

size_t  binary_search(std::deque<int> *main, int greatest_loser,
                      unsigned long pair_size, int min, int max)
{
  int mid_pair_index = ((min + max) / 2);
  int mid_element_index  = mid_pair_index * pair_size + (pair_size - 1);
  
  bool is_debug = false;
  if (is_debug)
  {
    print("");
    print("--binary_search--");
    print("min: " + to_str(min));
    print("max: " + to_str(max));
    print("mid_element_index: " + to_str(mid_element_index));
    print("mid_element_index value: " + to_str((*main)[mid_element_index]));
    print("main size: " + to_str((int)main->size()));
    print("--binary_search--");
    print("");
  }
  if (mid_element_index >= (int)main->size())
    return min * pair_size;
  if (greatest_loser > (*main)[mid_element_index])
    min = mid_pair_index + 1;
  else if (greatest_loser < (*main)[mid_element_index])
    max = mid_pair_index - 1;
  else
    return mid_element_index + 1;
  if (min > max)
    return min * pair_size;
  return binary_search(main, greatest_loser, pair_size, min, max);
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

//keep remaining numbers in main sequence
void	sort(std::deque<int> *main, unsigned long pair_size)
{
  std::deque<int> pend;
  size_t          insertion_index;
  //int             remains;
  bool is_debug;

  is_debug = true; //pair_size != 4;
  if (is_debug)
  {
    print("main");
    print_deque(*main);
  }
  for (size_t pair_start_index = pair_size * 2;
      pair_start_index + pair_size <= main->size();
      pair_start_index += pair_size)
    transfer_range(main, pair_start_index, pair_size, &pend, pend.size());
  int previous_jacob_number = 1;
  int jacob_number = compute_insertion_number(true);
  int number_of_insertion = jacob_number - previous_jacob_number;
  int maximal_insertion_index = jacob_number - 1;
  int index_of_pair_to_insert = (number_of_insertion - 1) * pair_size;
  int greatest_loser = pend[index_of_pair_to_insert + pair_size - 1];
  while (pend.size() >= pair_size)
  {
    if (!number_of_insertion)
    {
      previous_jacob_number = jacob_number;
      jacob_number = compute_insertion_number(false);
      number_of_insertion = jacob_number - previous_jacob_number;
    }
    if (is_debug)
    {
      print("main");
      print_deque(*main);
      print("pend");
      print_deque(pend);
    }
    index_of_pair_to_insert = (number_of_insertion - 1) * pair_size;
    if ((size_t)index_of_pair_to_insert >= pend.size())
      index_of_pair_to_insert = pend.size() - pair_size;
    else if ((size_t)index_of_pair_to_insert < 0)
      index_of_pair_to_insert = 0;
    greatest_loser = pend[index_of_pair_to_insert + pair_size - 1];
    if (is_debug)
    {
      print("pair_size:               " + to_str((int)pair_size));
      print("number_of_insertion:     " + to_str(number_of_insertion));
      print("index_of_pair_to_insert: " + to_str(index_of_pair_to_insert));
      print("greatest_loser:          " + to_str(greatest_loser));
      print("maximal_insertion_index: " + to_str(maximal_insertion_index));
    }
    insertion_index = binary_search(main, greatest_loser, pair_size, 0, maximal_insertion_index);
    if (is_debug)
      print("insertion_index:         " + to_str((int)insertion_index));
    transfer_range(&pend, index_of_pair_to_insert, pair_size, main, insertion_index);
    number_of_insertion--;
    if ((int)insertion_index != maximal_insertion_index)
      maximal_insertion_index++;
  }
  if (pair_size == 1) return ;
  sort(main, pair_size / 2);
}

int main(int argc, char **argv)
{
  (void)argc;
  std::deque<int> result;
  size_t          biggest_pair_size;

  if (argc > 1)
    result = parse_input(argv + 1);
  else
    fillDequeWithRandom(result, 0, 10, 10);
  print_deque(result);
  biggest_pair_size = sort_pairs(&result, 1);
  sort(&result, biggest_pair_size / 2);
  print_deque(result);
  if (is_sorted(result))
    print("Sorted");
  else
    print("Unsorted");
  return (SUCCESS);
}
