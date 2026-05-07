
#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeSigned;
		const int _gradeExec;

	public:
		AForm();
		AForm(const std::string name, int gradeSigned, int gradeExec);
		AForm(const AForm &obj);
		AForm &operator=(const AForm &obj);
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeSigned() const;
		int getGradeExec() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor) const;
		virtual void performAction() const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
