#include "RPN.hpp"

enum e_token_type get_token_type(char token)
{
  if (token == ' ')
    return SPACE;
  else if (isdigit(token))
    return DIGIT;
  else if (OPERATORS.find(token) != std::string::npos)
    return OPERATOR;
  else if (token == EMPTY)
    return EMPTY;
  return INVALID;
}

bool  is_token_valid(char token, char previous_token, size_t &digit_operator_ratio)
{
  bool          token_should_be_space;
  e_token_type  t_previous_token;
  e_token_type  t_token;

  t_token = get_token_type(token);
  t_previous_token = get_token_type(previous_token);
  if (t_previous_token == INVALID || t_token == INVALID)
    return FAILURE;
  token_should_be_space = (t_previous_token == DIGIT || t_previous_token == OPERATOR);
  switch (t_token)
  {
    case SPACE:
      if (token_should_be_space)
        return SUCCESS;
      break ;
    case DIGIT:
      if (!token_should_be_space)
      {
        digit_operator_ratio++;
        return SUCCESS;
      }
      break ;
    case OPERATOR:
      if (!token_should_be_space && digit_operator_ratio-- > 0)
        return SUCCESS;
      break ;
    default:
      break ;
  }
  return FAILURE;
}

std::stack<char> parse_expression(std::string input)
{
  std::stack<char>  expression;
  size_t            i = 0;
  char              previous_token = EMPTY;
  size_t            digit_operator_ratio = 0;
  char              token;

  while (input[i])
  {
    token = input[i];
    //print(token);
    if (is_token_valid(token, previous_token, digit_operator_ratio) == FAILURE)
      throw std::exception();
    if (get_token_type(token) != SPACE)
      expression.push(token);
    i++;
    previous_token = token;
  }
  if (digit_operator_ratio != 1 || get_token_type(token) != OPERATOR)
      throw std::exception();
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
  if (get_token_type(token) == DIGIT)
    return token - '0';
  int operand_b = process_expression(expression);
  int operand_a = process_expression(expression);
  return calculate_expression(operand_a, operand_b, token);
}

int main(int argc, char **argv)
{
  if (argc != 2)
    return FAILURE;
  std::stack<char> expression;
  try {
    expression = parse_expression(std::string(argv[1]));
  } catch (std::exception& e) {
    print_error("parsing failure");
    return FAILURE;
  }
  int result = process_expression(expression);
  print(to_str(result));
  return SUCCESS;
}
