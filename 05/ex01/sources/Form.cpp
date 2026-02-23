#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int sign_grade, int exec_grade) 
    : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
    if (_sign_grade < GRADE_MIN || _exec_grade < GRADE_MIN)
        throw GradeTooHighException();
    if (_sign_grade > GRADE_MAX || _exec_grade > GRADE_MAX)
        throw GradeTooLowException();
}

Form::Form(const Form& other) 
    : _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade) {
}

Form& Form::operator=(const Form& other) {
    if (this != &other)
        this->_is_signed = other._is_signed;
    return *this;
}

Form::~Form(void) {
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _is_signed;
}

int Form::getSignGrade() const {
    return _sign_grade;
}

int Form::getExecGrade() const {
    return _exec_grade;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _sign_grade)
        throw GradeTooLowException();
    _is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << ", form sign grade " << f.getSignGrade() 
       << ", exec grade " << f.getExecGrade() 
       << ", signed: " << (f.isSigned() ? "yes" : "no") << ".";
    return os;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}
