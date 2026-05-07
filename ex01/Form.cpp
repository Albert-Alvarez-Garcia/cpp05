#include "Form.hpp"

// Default constructor
Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

// Parameterized constructor
Form::Form(const std::string name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

// Copy constructor
Form::Form(const Form &src) 
    : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

// Assignment operator
Form &Form::operator=(const Form &src)
{
    if (this != &src)
    {
        // Only _signed can be copied, others are const
        this->_signed = src._signed;
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getters
std::string Form::getName() const { return this->_name; }
bool        Form::getIsSigned() const { return this->_signed; }
int         Form::getGradeToSign() const { return this->_gradeToSign; }
int         Form::getGradeToExecute() const { return this->_gradeToExecute; }

// Member function
void        Form::beSigned(const Bureaucrat &b)
{
    // If bureaucrat's grade is higher than required (numerically lower)
    if (b.getGrade() <= this->_gradeToSign)
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &o, const Form &rhs)
{
    o << "Form: " << rhs.getName() 
      << " | Status: " << (rhs.getIsSigned() ? "Signed" : "Unsigned")
      << " | Grade to Sign: " << rhs.getGradeToSign()
      << " | Grade to Execute: " << rhs.getGradeToExecute();
    return o;
}