#include "Bureaucrat.hpp"
#include "Form.hpp" // Required here to access Form's member functions

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {}

// Assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
    {
        // _name is const, only _grade can be updated
        this->_grade = src._grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getters
std::string Bureaucrat::getName() const { return this->_name; }
int         Bureaucrat::getGrade() const { return this->_grade; }

// Grade modification
void Bureaucrat::incrementGrade()
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

// New method for Exercise 01
void Bureaucrat::signForm(Form &f)
{
    try
    {
        // Attempt to sign the form
        f.beSigned(*this);
        // If no exception is thrown, printing success message
        std::cout << this->_name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        // If grade is too low, catch the exception and print the reason
        std::cout << this->_name << " couldn't sign " << f.getName() 
                  << " because " << e.what() << std::endl;
    }
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return o;
}