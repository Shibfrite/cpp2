#include "support.hpp"
#include <fstream>
#include <exception>
#include <map>

#define CSV_FILE "../includes/data.csv"
#define DATE_SEPARATOR ':'
#define VALUES_SEPARATOR ' '
#define SUCCESS 0
#define FAILURE 1
#define FEBRUARY 2

enum timeUnit{
  YEAR,
  MONTH,
  DAY
};

double  getNumber(std::string *line, enum timeUnit t)
{
  double  number;
  size_t  pos;

  number = std::stoi(*line, &pos);
  if (t == YEAR && (*line)[pos] != DATE_SEPARATOR)
    throw std::exception();
  else if (t == MONTH && (*line)[pos] != DATE_SEPARATOR)
    throw std::exception();
  else if (t == DAY && (*line)[pos] != VALUES_SEPARATOR)
    throw std::exception();
  *line = line->substr(pos + 1);
  return number;
}

bool isDateValid(int year, unsigned int month, unsigned int day)
{
    if (month < 1 || month > 12 || day < 1)
      return FAILURE;

    unsigned int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2)
    {
        bool isLeap = (!(year % 4) && year % 100) || !(year % 400);
        if (isLeap)
          daysInMonth[1] = 29;
    }
    return day <= daysInMonth[month - 1] ? SUCCESS : FAILURE;
}

std::string getDate(std::string line)
{
  int         year;
  int         month;
  int         day;
  std::string date;

  date = line.substr(0, line.find(' '));

  try{
    year = getNumber(&line, YEAR);
    month = static_cast<unsigned int>(getNumber(&line, MONTH));
    day = static_cast<unsigned int>(getNumber(&line, DAY));

    if (!isDateValid(year, month, day))
      throw std::exception();
  } catch(std::exception& e){
    print("Error: bad input => " + date)
    throw std::exception();
  }
  return date;
}

template<typename T>
T getRate(std::string line)
{
  T rate;
  std::string token = line.substr(line.find('|') + 2);

  try {
    rate = std::stof(token);
  } catch(std::exception& e) {
    print("Error: too large a number => " + token);
    throw e;
  }
  if (rate <= 0 || rate >= 1000)
  {
    if (rate <= 0)
      print("Error: too low a number => " + token);
    else
      print("Error: too large a number => " + token);
    throw std::exception();
  }
  return rate;
}

template<typename T>
bool parseLine(std::string line, std::string *date, T *rate)
{
  try {
    *date = getDate(line);
    *rate = getRate(line);
  } catch (std::exception& e) {
    return FAILURE;
  }
  return SUCCESS;
}

//would print errors before showing the new map
//correct behaviour is showing errors while printing result
template<typename T>
std::map<std::string, T> parseCsv(void)
{
  std::map<std::string, T>  result;
  std::string               line;
  std::string               date;
  T                         rate;

  std::ifstream file(CSV_FILE);
  if (!file)
    throw std::exception();
  while (std::getline(file, line))
    if (parseLine(line, &date, &rate) == SUCCESS)
      result.insert({date, rate});
  return (result);
}

int main(void)
{

	return (0);
}
