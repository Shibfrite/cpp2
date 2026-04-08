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
  if (t != DAY && (*line)[pos] != DATE_SEPARATOR)
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
  int           year;
  unsigned int  month;
  unsigned int  day;

  year = getNumber(&line, YEAR);
  month = static_cast<unsigned int>(getNumber(&line, MONTH));
  day = static_cast<unsigned int>(getNumber(&line, DAY));

  if (!isDateValid(year, month, day))
    throw std::invalid_arguements();

  return line.substr(0, line.find(' '));
}

//function can throw error, catch higher
T getRate(std::string line)
{
  std::string value = line.substr(line.find('|') + 1);
  return std::stof(value);
}

template<typename T>
bool parseLine(std::string line, std::string *date, T *rate)
{
  *date = getDate(line);
  *rate = getRate(line);

    return FAILURE;
  return SUCCESS;
}

template<typename T>
std::map parseCsv(void)
{
  std::map    result;
  std::string line;
  std::string date;
  T           rate;

  std::ifstream file(CSV_FILE);
  while (std::getline(file, line) && parseLine(line, &date, &rate) == SUCCESS)
    result.insert(date, rate);
  return (result);
}

int main(void)
{

	return (0);
}
