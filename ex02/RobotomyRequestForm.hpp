#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> // For rand()

class RobotomyRequestForm : public AForm
{
private:
    const std::string _target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &src);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
};

#endif