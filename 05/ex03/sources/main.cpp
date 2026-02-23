#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;
    Bureaucrat boss("Boss", 1);
    AForm* form;

    // Valid forms
    form = intern.makeForm("shrubbery creation", "garden");
    //boss.signForm(*form);
    boss.executeForm(*form);

    form = intern.makeForm("robotomy request", "Bender");
    boss.signForm(*form);
    boss.executeForm(*form);

    form = intern.makeForm("presidential pardon", "Zaphod");
    boss.signForm(*form);
    boss.executeForm(*form);

    // Invalid form
    form = intern.makeForm("does not exist", "nobody");
    if (!form)
        std::cout << "No form created as expected" << std::endl;

    return 0;
}
