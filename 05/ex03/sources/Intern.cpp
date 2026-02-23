#include "Intern.hpp"
#include "ShrubberyCreationForm.cpp.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern& other) {}
Intern& Intern::Intern(const Intern& other) {return *this;}
Intern::~Intern() {}

AForm* makeForm(const std::string& name, const std::string& target);
