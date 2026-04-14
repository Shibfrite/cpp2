#include "BitcoinExchange.hpp"

int main()
{
  try {
    parseCsv(CSV_FILE);
  } catch (MyException& e) {
    print_error("Error: CSV file isn't valid");
    print_error(e.what());
  }

	return (0);
}
