#include "Bureaucrat.hpp"

//Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

//Parameterized constructro
Bureaucrat::Bureaucrat(const std::string name, int grade) :_name(name)
{
    if (grade <1)
        throw Bureaucrat::GradeTooHighException();
    if (grade >150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

//Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade){}

//Assigment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
    {
        this->_grade = src._grade;
    }
    return *this;
}

//Destructor
Bureaucrat::~Bureaucrat(){}

//Getters
std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

//Grade mod
void Bureaucrat::incrementGrade()
{
    if (this->_grade -1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

//Insertion operator overload

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " <<rhs.getGrade() << ".";
    return o;
}