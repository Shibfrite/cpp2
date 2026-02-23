#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int sign_grade, int exec_grade) 
    : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
    if (sign_grade < GRADE_MIN || exec_grade < GRADE_MIN)
        throw GradeTooHighException();
    if (sign_grade > GRADE_MAX || exec_grade > GRADE_MAX)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade) {
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->_is_signed = other._is_signed;
    return *this;
}

AForm::~AForm(void) {
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _is_signed;
}

int AForm::getSignGrade() const {
    return _sign_grade;
}

int AForm::getExecGrade() const {
    return _exec_grade;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _sign_grade)
        throw GradeTooLowException();
    _is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName() << ", form sign grade " << f.getSignGrade() 
       << ", exec grade " << f.getExecGrade() 
       << ", signed: " << (f.isSigned() ? "yes" : "no") << ".";
    return os;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low!";
}

const char* AForm::Unsigned::what() const throw() {
    return "AForm isn't signed!";
}
