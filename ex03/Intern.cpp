
#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern &Intern::operator=(const Intern &rhs) {
	if (this != &rhs) {
		(void)rhs;
	}
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeShrubbery(std::string target) const {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(std::string target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(std::string target) const {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string names[] = {
		"shrubbery creation", 
		"robotomy request", 
		"presidential pardon"
	};
	AForm* (Intern::*funcs[])(std::string) const = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};
	for (int i = 0; i < 3; i++) {
		if (names[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*funcs[i])(target);
		}
	}
	std::cout << "Intern could not create form: '" << formName << "' because it does not exist." << std::endl;
	return NULL;
}
