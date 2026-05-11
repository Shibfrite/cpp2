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
  int mid = ((min + max) / 2) * pair_size;
  
  if (greatest_loser > (*main)[mid])
    min = mid + pair_size;
  else if (greatest_loser < (*main)[mid])
    max = mid - pair_size;
  else
    return mid;
  if (min > max)
    return mid;
  return binary_search(main, greatest_loser, pair_size, min, max);
}

int compute_insertion_number(bool is_first)
{
  static int jacob_number = 3;
  static int power_of_two = 4;
  int number_of_insertion;
  int previous_jacob_number;
  if (is_first)
  {
   jacob_number = 3;
   power_of_two = 4;
   return jacob_number;
  }
  power_of_two *= 2;
  previous_jacob_number = jacob_number;
  jacob_number = power_of_two - previous_jacob_number;
  number_of_insertion = jacob_number - previous_jacob_number - 1;
  return number_of_insertion;
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
  /*remains = main->size() % pair_size;
  if (remains)
    transfer_range(main, main->size() - remains, remains, &pend, pend.size());
    */ //We can keep the remaining numbers in main.
  //print("pend");
	//print_deque(pend);
  int number_of_insertion = compute_insertion_number(true);
  int maximal_insertion_index = number_of_insertion;
  int index_of_pair_to_insert = (number_of_insertion - 2) * pair_size - 1;
  int greatest_loser = pend[index_of_pair_to_insert + pair_size - 1];
  while (pend.size() >= pair_size)
  {
    if (!number_of_insertion)
    {
      number_of_insertion = compute_insertion_number(false);
      maximal_insertion_index = number_of_insertion;
    }
    if (is_debug)
    {
      print("main");
      print_deque(*main);
      print("pend");
      print_deque(pend);
    }
    index_of_pair_to_insert = (number_of_insertion - 2) * pair_size;
    if ((size_t)index_of_pair_to_insert > pend.size())
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
    insertion_index = binary_search(main, greatest_loser, pair_size, 1, maximal_insertion_index);
    if (is_debug)
      print("insertion_index:         " + to_str((int)insertion_index));
    transfer_range(&pend, index_of_pair_to_insert, pair_size, main, insertion_index);
    number_of_insertion--;
  }
  //print("main");
	//print_deque(*main);
  if (pair_size == 1) return ;
  sort(main, pair_size / 2);
}

int main(int argc, char **argv)
{
	(void)argc;
	std::deque<int> result = parse_input(argv + 1);
  size_t biggest_pair_size = sort_pairs(&result, 1);
	//std::deque<int>::iterator it = result.begin();
  //print("post parsing");
	//print_deque(result);
  sort(&result, biggest_pair_size / 2);
	print_deque(result);
	return (SUCCESS);
}
