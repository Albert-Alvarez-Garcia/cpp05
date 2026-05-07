
#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeSigned(150), _gradeExec(150) {}

AForm::AForm(const std::string name, int gradeSigned, int gradeExec) :
	_name(name), _isSigned(false), _gradeSigned(gradeSigned), _gradeExec(gradeExec) 
{
	if (gradeSigned < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeSigned > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : 
	_name(src._name), _isSigned(src._isSigned), _gradeSigned(src._gradeSigned), _gradeExec(src._gradeExec) {}

AForm &AForm::operator=(const AForm &rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

int AForm::getGradeSigned() const {
	return this->_gradeSigned;
}

int AForm::getGradeExec() const {
	return this->_gradeExec;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeSigned)
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!this->_isSigned)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
	this->performAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::NotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &obj) {
	os << "AForm: " << obj.getName();
	if (obj.getIsSigned())
		os << " | Signed: Yes";
	else
		os << " | Signed: No";
	os << " | Req. sign: " << obj.getGradeSigned()
	   << " | Req. exec: " << obj.getGradeExec();
	return os;
}
