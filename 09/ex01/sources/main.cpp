#include "RPN.hpp"

bool  is_token_valid(std::string token)
{
  if (isdigit(token[0]))
    return SUCCESS;
  else if (OPERATORS.find(token[0]) != std::string::npos)
    return SUCCESS;
  return FAILURE;
}

std::stack<char> parse_expression(std::string input)
{
  std::stack<char>       expression;
  //std::reverse(input.begin(), input.end());
  std::string::iterator it = input.begin();

  while (it <= input.end())
  {
    std::string token = std::string(it, it + 1);
    if (is_token_valid(token) == SUCCESS)
      expression.push(token[0]);
    it++;
  }
  return expression;
}

int calculate_expression(int operand_a, int operand_b, char operator_c)
{
  int result;

  switch (operator_c)
  {
    case '+':
      result = operand_a + operand_b;
      break ;
    case '-':
      result = operand_a - operand_b;
      break ;
    case '*':
      result = operand_a * operand_b;
      break ;
    case '/':
      result = operand_a / operand_b;
      break ;
  }
  return result;
}

int process_expression(std::stack<char> &expression)
{
  char token = expression.top();
  expression.pop();
  print(token);
  if (isdigit(token))
    return token - '0';
  int operand_b = process_expression(expression);
  int operand_a = process_expression(expression);
  return calculate_expression(operand_a, operand_b, token);
}

int main(int argc, char **argv)
{
  if (argc != 2)
    return FAILURE;
  std::stack<char> expression = parse_expression(std::string(argv[1]));
  int result = process_expression(expression);
  print(to_str(result));
  return SUCCESS;
}
