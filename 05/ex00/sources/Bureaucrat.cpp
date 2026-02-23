#include "Bureaucrat.hpp"
#include "support.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade){
  if (_grade > GRADE_MAX)
    throw GradeTooLowException();
  else if (_grade < GRADE_MIN)
    throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade){
}

//operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

Bureaucrat& Bureaucrat::operator++(){
    if (_grade - 1 < GRADE_MIN)
      throw GradeTooHighException();
    _grade--;
    return *this;
}

Bureaucrat& Bureaucrat::operator--(){
    if (_grade + 1 > GRADE_MAX)
      throw GradeTooLowException();
    _grade++;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat _grade " << b.getGrade() << ".";
    return os;
}

const std::string& Bureaucrat::getName() const{
  return _name;
}

int Bureaucrat::getGrade() const{
  return _grade;
}

Bureaucrat::~Bureaucrat(void){
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "_grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "_grade is too low!";
}
