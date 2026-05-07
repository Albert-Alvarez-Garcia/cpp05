#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    (void)src;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    this->checkExecution(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}