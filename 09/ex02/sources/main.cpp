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

int main(int argc, char **argv)
{
  (void)argc;
  std::deque<int> result;
  size_t          biggest_pair_size;
  int             tries = 0;
  bool            error_found = false;

  if (argc > 1) {
    result = parse_input(argv + 1);
    print_deque(result);
    biggest_pair_size = sort_pairs(&result, 1);
    jacob_sort(&result, biggest_pair_size / 2);
    print_deque(result);
    if (is_sorted(result))
      print("Sorted");
    else
      print("Unsorted");
    return (SUCCESS);
  }

  while (tries < 100 && !error_found) {
    fillDequeWithRandom(result, 0, 10, 10);
    print_deque(result);
    biggest_pair_size = sort_pairs(&result, 1);
    jacob_sort(&result, biggest_pair_size / 2);
    print_deque(result);
    
    if (is_sorted(result)) {
      print("Sorted");
      tries++;
    } else {
      print("Unsorted");
      error_found = true;
    }
  }
  
  if (error_found)
    print("ERROR: Sort failed!");
  else
    print("SUCCESS: 100 random sorts passed");
    
  return (SUCCESS);
}
