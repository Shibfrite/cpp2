#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(const std::string& target);
    void execute(Bureaucrat const& executor) const;
private:
    std::string _target;
};
