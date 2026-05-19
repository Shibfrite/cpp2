#include "PMergeMe.hpp"

template <typename Container>
void  parse_input(Container &output, char **input)
{
	int				      number;
	char				    *endptr;
	errno = 0;
	while (*input)
	{
		number = std::strtol(*input, &endptr, 10);
		if (errno != 0 || endptr == *input || *endptr != '\0')
			throw std::exception();
		output.push_back(number);
		input++;
	}
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
    std::deque<int>                   output;
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
            fillDequeWithRandom(output, 0, test_size, test_size);
            new_list = output;
            biggest_pair_size = sort_pairs(&output, 1);
            jacob_sort(&output, biggest_pair_size / 2);

            if (!is_sorted(output))
            {
                print("ERROR: Sort failed at size " + to_str(test_size));
                print(new_list);
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

#include <iomanip>
#include <sys/time.h>

// Returns current time in microseconds as a double
double get_time_us() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

template <typename Container>
void  sort(Container output, char **argv)
{
  Container input;
  size_t    biggest_pair_size;

  double start = get_time_us();
  parse_input(input, argv + 1);
  output = input;
  biggest_pair_size = sort_pairs(&output, 1);
  jacob_sort(&output, biggest_pair_size / 2);

  double end = get_time_us();
  double duration_us = end - start;
  std::cout << "Before:  " << std::endl;
  print(input);
  std::cout << "After:   " << std::endl;
  print(output);
  std::cout << std::fixed << std::setprecision(5)
            << duration_us << " us" << std::endl;
}

int main(int argc, char **argv)
{
  std::deque<int> output_d;
  std::vector<int> output_v;

  if (argc == 1) {
    tester();
    return (SUCCESS);
  }
  sort(output_d, argv);
  sort(output_v, argv);
  return (SUCCESS);
}
