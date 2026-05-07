
#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	private:
		AForm* makeShrubbery(std::string target) const;
		AForm* makeRobotomy(std::string target) const;
		AForm* makePresidential(std::string target) const;

	public:
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &rhs);
		~Intern();

		AForm* makeForm(std::string formName, std::string target);
};

#endif
