#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!isSigned())
        throw AForm::Unsigned();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    
    std::ofstream file((_target + "_shrubbery").c_str());
    file << "  *  " << std::endl;
    file << " *** " << std::endl;
    file << "*****" << std::endl;
    file << "  |  " << std::endl;
}
