#include "BitcoinExchange.hpp"

double getNumber(std::string *line, enum timeUnit t)
{
  double number;
  char   sep;
  int    digits;

  number = atoi(line->c_str());
  if (t == YEAR)
    digits = 4;
  else
    digits = 2;
  sep = (t == DAY) ? VALUES_SEPARATOR : DATE_SEPARATOR;
  if ((*line)[digits] != sep)
    throw std::exception();
  *line = line->substr(digits + 1);
  return number;
}

bool isDateValid(int year, unsigned int month, unsigned int day)
{
    if (month < 1 || month > 12 || day < 1)
      return FAILURE;

    unsigned int  daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int     february = 2;

    if (month == february)
    {
        bool isLeap = (!(year % 4) && year % 100) || !(year % 400);
        if (isLeap)
          daysInMonth[february - 1] = 29;
    }
    return day <= daysInMonth[month - 1] ? SUCCESS : FAILURE;
}

std::string getDate(std::string line)
{
  int         year;
  int         month;
  int         day;
  std::string date;

  date = line.substr(0, line.find(VALUES_SEPARATOR));

  try{
    year = getNumber(&line, YEAR);
    month = static_cast<unsigned int>(getNumber(&line, MONTH));
    day = static_cast<unsigned int>(getNumber(&line, DAY));

    if (isDateValid(year, month, day) == FAILURE)
      throw std::exception();
  } catch(std::exception& e){
    throw MyException(line + " date is ill-formated.");
  }
  return date;
}

float getRate(std::string line)
{
  float rate;
  std::string token = line.substr(line.find(VALUES_SEPARATOR) + 1);

  rate = atof(token.c_str());
  return rate;
}

void  parseLine(std::string line, std::string *date, float *rate)
{
  *date = getDate(line);
  *rate = getRate(line);
}

std::map<std::string, float> parseCsv(std::string csv_file)
{
  std::map<std::string, float>  result;
  std::string                   line;
  std::string                   date;
  float                         rate;

  std::ifstream file(csv_file.c_str());
  if (!file)
    throw MyException(csv_file + " isn't a valid file.");
  std::getline(file, line);
  while (std::getline(file, line))
  {
    parseLine(line, &date, &rate);
    result.insert(std::make_pair(date, rate));
  }
  return (result);
}
