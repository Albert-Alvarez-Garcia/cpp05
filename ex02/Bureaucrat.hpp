#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

// Updated: Now using AForm (Abstract)
class AForm;

class Bureaucrat 
{
private:
    const std::string   _name;  
    int                 _grade; 

public:
    // Orthodox Canonical Form 
    Bureaucrat();                               
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &src);
    ~Bureaucrat();                              

    // Getters
    std::string getName() const;
    int         getGrade() const;

    // Grade modification functions 
    void        incrementGrade(); 
    void        decrementGrade();

    // New methods for EX01 and EX02
    void        signForm(AForm &f);
    void        executeForm(AForm const & form); // Added for EX02

    // Exception classes 
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw() { return "Grade is too high!"; }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw() { return "Grade is too low!"; }
    };
};

// Insertion (<<) operator overload
std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif