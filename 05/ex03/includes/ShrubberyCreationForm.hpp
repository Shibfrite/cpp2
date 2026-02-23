#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(const std::string& target);
    void execute(Bureaucrat const& executor) const;
private:
    std::string _target;
};
