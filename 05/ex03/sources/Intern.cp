#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

static AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
static AForm* createRobotomy(const std::string& target)  { return new RobotomyRequestForm(target); }
static AForm* createPardon(const std::string& target)    { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    struct FormEntry {
        std::string name;
        AForm* (*create)(const std::string&);
    };

    FormEntry table[] = {
        {"shrubbery creation",  createShrubbery},
        {"robotomy request",    createRobotomy},
        {"presidential pardon", createPardon}
    };

    for (int i = 0; i < 3; i++) {
        if (table[i].name == name) {
            std::cout << "Intern creates " << name << std::endl;
            return table[i].create(target);
        }
    }
    std::cerr << "Error: form '" << name << "' does not exist" << std::endl;
    return NULL;
}
