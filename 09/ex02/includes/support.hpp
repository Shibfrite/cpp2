#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <deque>
#include <cstdlib>
#include <ctime>

typedef struct s_current_jacob_data
{
  int previous_jacob_number;
  int jacob_number;
  int insertions_left;
  int maximal_insertion_index;
} t_current_jacob_data;

typedef struct s_loop_data
{
 int index_of_pair;
 int greatest_loser;
} t_loop_data;

std::string	to_str(int n);
std::string to_str(float n);
void		print(std::string str);
void    print(const char* s);
void		print(int n);
void	  print(char c);
void	  print_bool(bool value);
void		print_error(std::string str);

template <typename Container>
bool    is_sorted(Container list);
template <typename Container>
void    fillDequeWithRandom(Container& dq, int min, int max, std::size_t count);

//algo support
template <typename Container>
size_t  binary_search(Container *main, int greatest_loser, unsigned long pair_size, int min, int max);
template <typename Container>
void    init_pend(Container *main, Container *pend, unsigned long pair_size);
void    set_current_jacob_data(bool is_first, t_current_jacob_data *current_jacob_data);
template <typename Container>
void    set_loop_data(t_loop_data *loop_data, Container *pend, int insertions_left, unsigned int pair_size);
template <typename Container>
void    transfer_range(Container *source, size_t source_start_index, unsigned int source_size,
                      Container *destination, size_t destination_index);

template <typename Container>
void print(const Container& c) {
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
