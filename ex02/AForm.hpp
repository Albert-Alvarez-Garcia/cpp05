#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExecute;

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &src);
    AForm &operator=(const AForm &src);
    virtual ~AForm(); // Virtual destructor is mandatory for abstract classes

    // Getters
    std::string getName() const;
    bool        getIsSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    // Member functions
    void        beSigned(const Bureaucrat &b);
    
    // Pure virtual function: makes the class abstract
    virtual void execute(Bureaucrat const & executor) const = 0;

    // Helper to check if execution is possible (used by children)
    void        checkExecution(Bureaucrat const & executor) const;

    // Exceptions
    class GradeTooHighException : public std::exception {
        public: virtual const char* what() const throw() { return "Form grade is too high!"; }
    };
    class GradeTooLowException : public std::exception {
        public: virtual const char* what() const throw() { return "Form grade is too low!"; }
    };
    class FormNotSignedException : public std::exception {
        public: virtual const char* what() const throw() { return "Form is not signed yet!"; }
    };
};

std::ostream &operator<<(std::ostream &o, const AForm &rhs);

#endif