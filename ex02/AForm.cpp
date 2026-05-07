#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) 
    : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm &AForm::operator=(const AForm &src)
{
    if (this != &src)
        this->_signed = src._signed;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool        AForm::getIsSigned() const { return _signed; }
int         AForm::getGradeToSign() const { return _gradeToSign; }
int         AForm::getGradeToExecute() const { return _gradeToExecute; }

void        AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw AForm::GradeTooLowException();
}

// Validation before execution
void        AForm::checkExecution(Bureaucrat const & executor) const
{
    if (!this->_signed)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, const AForm &rhs)
{
    o << "Form: " << rhs.getName() 
      << " | Signed: " << (rhs.getIsSigned() ? "Yes" : "No")
      << " | S-Grade: " << rhs.getGradeToSign()
      << " | E-Grade: " << rhs.getGradeToExecute();
    return o;
}