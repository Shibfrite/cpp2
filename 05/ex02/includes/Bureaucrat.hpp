//Header-protection
#pragma once

//Headers
#include<iostream>
#include<string>
#include "AForm.hpp"

//Defines
#define GRADE_MIN 1
#define GRADE_MAX 150

//Class
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
    //methods
    void  signForm(AForm& f);
    void  executeForm(AForm const& form) const;
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
