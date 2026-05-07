#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration

class Form
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExecute;

public:
    // Orthodox Canonical Form
    Form();
    Form(const std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &src);
    Form &operator=(const Form &src); // Corregido de + a =
    ~Form();

    // Getters
    std::string getName() const;
    bool        getIsSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    // Member function
    void        beSigned(const Bureaucrat &b); // Corregido typo beSigend

    // Exceptions
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Form grade is too high!";
        }
    }; // Añadido ;

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Form grade is too low!";
        }
    }; // Añadido ;
};

// Insertion operator overload
std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif