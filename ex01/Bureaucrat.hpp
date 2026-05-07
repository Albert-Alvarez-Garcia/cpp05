#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

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

    // Getters [cite: 136]
    std::string getName() const;
    int         getGrade() const;

    // Grade modification functions 
    void        incrementGrade(); // Increments grade (e.g., 3 becomes 2) 
    void        decrementGrade(); // Decrements grade (e.g., 2 becomes 3)

    //EX01
    void        signForm(Form &f);

    // Exception classes 
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Grade is too low!";
        }
    };
};

// Insertion (<<) operator overload [cite: 150]
std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif