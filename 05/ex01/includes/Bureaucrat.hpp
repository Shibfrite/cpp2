#pragma once

#include<iostream>
#include<string>
#include "Form.hpp"

#define GRADE_MIN 1
#define GRADE_MAX 150

//grade ranges from 1 to 150
class Bureaucrat
{
	private:
    const std::string _name;
    int               _grade;
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

    //changes the grade through precrementation
		Bureaucrat& operator++();
		Bureaucrat& operator--();
    const std::string& getName() const;
    int getGrade() const;
		~Bureaucrat(void);

    void  signForm(Form& f);
    class GradeTooHighException : public std::exception {
      public:
          const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
          const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
