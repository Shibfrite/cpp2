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

#include <vector>
#include <cmath>

int ford_johnson_bound(int n) {
    double log_factorial = 0;
    for (int i = 2; i <= n; i++)
        log_factorial += std::log(i) / std::log(2.0);
    return (int)std::ceil(log_factorial);
}

void tester()
{
    std::deque<int>                   result;
    size_t                            biggest_pair_size;
    int                               max_tries    = 100;
    int                               max_list_size = 100;
    int                               list_size    = 2;
    std::vector<std::vector<int> >    stats;

    while (list_size <= max_list_size)
    {
        int bound     = ford_johnson_bound(list_size);
        int old_bound = bound;
        int max_comp  = 0;
        int avg_comp  = 0;
        int tries     = 0;
        std::deque<int> new_list;

        while (list_size <= max_list_size && ford_johnson_bound(list_size) == old_bound)
            list_size++;
        int test_size = list_size - 1;

        while (tries < max_tries)
        {
            total_comparaisons = 0;
            fillDequeWithRandom(result, 0, test_size, test_size);
            new_list = result;
            biggest_pair_size = sort_pairs(&result, 1);
            jacob_sort(&result, biggest_pair_size / 2);

            if (!is_sorted(result))
            {
                print("ERROR: Sort failed at size " + to_str(test_size));
                print_deque(new_list);
                return ;
            }
            if (total_comparaisons > max_comp) max_comp = total_comparaisons;
            avg_comp += total_comparaisons;
            tries++;
        }
        std::vector<int> row(3);
        row[0] = bound;
        row[1] = max_comp;
        row[2] = avg_comp / max_tries;
        stats.push_back(row);
    }

    bool crossed = false;
    print("bound | max | avg");
    for (size_t i = 0; i < stats.size(); i++)
    {
        if (stats[i][1] > stats[i][0])
        {
          crossed = true;
          print("WARNING: bound was crossed.");
        }
        print(to_str(stats[i][0]) + " | " + to_str(stats[i][1]) + " | " + to_str(stats[i][2]));
    }
    if (!crossed)
      print("SUCCESS: bound never crossed.");
}
int total_comparaisons = 0;

int main(int argc, char **argv)
{
  std::deque<int> result;
  size_t          biggest_pair_size;

  if (argc == 1) {
    tester();
    return (SUCCESS);
  }
  result = parse_input(argv + 1);
  print_deque(result);
  biggest_pair_size = sort_pairs(&result, 1);
  jacob_sort(&result, biggest_pair_size / 2);
  print_deque(result);
  if (is_sorted(result))
    print("Sorted");
  else
    print("Unsorted");
  print(total_comparaisons);

  
return (SUCCESS);
}
