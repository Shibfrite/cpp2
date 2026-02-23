#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat high("High", 1);
        Bureaucrat low("Low", 150);

        ShrubberyCreationForm s("garden");
        RobotomyRequestForm r("Bender");
        PresidentialPardonForm p("Ford");

        std::cout << s << std::endl;
        std::cout << r << std::endl;
        std::cout << p << std::endl;

        // try executing unsigned form
        try { high.executeForm(s); } catch (std::exception& e) { std::cout << e.what() << std::endl; }

        // sign and execute with high grade
        high.signForm(s);
        high.signForm(r);
        high.signForm(p);

        high.executeForm(s);
        high.executeForm(r);
        high.executeForm(p);

        std::cout << s << std::endl;
        // try executing with too low grade
        try { low.executeForm(p); } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    } catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }
    return 0;
}
