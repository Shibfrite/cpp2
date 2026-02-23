#pragma once
#include <iostream>
#include <string>

#define GRADE_MIN 1
#define GRADE_MAX 150

class Bureaucrat;
class AForm
{
    private:
        const std::string   _name;
        bool                _is_signed;
        const int           _sign_grade;
        const int           _exec_grade;
    public:
        AForm(const std::string& name, int sign_grade, int exec_grade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm(void);

        const std::string&  getName() const;
        bool                isSigned() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;

        void beSigned(const Bureaucrat& b);
        virtual void execute(Bureaucrat const& executor) const = 0;
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class Unsigned : public std::exception { public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);
