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

size_t  binary_search(std::deque<int> *main, int greatest_loser, unsigned long pair_size, int min, int max)
{
  if (min > max)
    return min;
  int mid = ((max + min) / (2 * pair_size)) * pair_size;
  
  if (greatest_loser > (*main)[mid])
    min = mid + pair_size;
  else if (greatest_loser < (*main)[mid])
    max = mid - pair_size;
  else
    return mid;
  return binary_search(main, greatest_loser, pair_size, min, max);
}

int jacob_number_generator(int i)
{
  static int jacob_number = 3;
  static int power_of_two = 4;
  if (i == 1)
  {
   jacob_number = 3;
   power_of_two = 4;
  }
  power_of_two *= 2;
  jacob_number = power_of_two - jacob_number;
  return jacob_number;
}

void	sort(std::deque<int> *main, unsigned long pair_size)
{
  std::deque<int> pend;
  int             remains;
  //print(to_str((int)pair_size));
  if (pair_size <= 1) return ;
  for (size_t pair_start_index = pair_size * 2;
      pair_start_index + pair_size <= main->size();
      pair_start_index += pair_size)
    transfer_range(main, pair_start_index, pair_size, &pend, pend.size());
  remains = main->size() % pair_size;
  if (remains)
    transfer_range(main, main->size() - remains, remains, &pend, pend.size());
  //print("pend");
	//print_deque(pend);
  for (int i = 1; pend.size() >= pair_size; i++)
  {
    print("pend");
    print_deque(pend);
    print("main");
    print_deque(*main);
    print("insert at:");
    print((int)binary_search(main, pend[pair_size - 1], pair_size, 0, main->size() - 1));
    print((int)(jacob_number_generator(i) * pair_size));
    int start = jacob_number_generator(i) * pair_size;
    if ((size_t)start > pend.size())
      start = pend.size() - pair_size;
    transfer_range(&pend, start, pair_size, main, binary_search(main, pend[pair_size - 1], pair_size, 0, main->size() - 1));
  }
  //print("main");
	//print_deque(*main);
  sort(main, pair_size / 2);
}

int main(int argc, char **argv)
{
	(void)argc;
  print(15/8);
	std::deque<int> result = parse_input(argv + 1);
  size_t biggest_pair_size = sort_pairs(&result, 1);
	//std::deque<int>::iterator it = result.begin();
  //print("post parsing");
	//print_deque(result);
  sort(&result, biggest_pair_size / 4);
	//print_deque(result);
	return (SUCCESS);
}
