#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string& target);
    void execute(Bureaucrat const& executor) const;
private:
    std::string _target;
};
