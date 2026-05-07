
/*
 * A Bureaucrat must have:
	• A constant name.
	• A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).
   Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception:
   either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

   You will provide getters for both attributes: getName() and getGrade().
   You must also implement two member functions to increment or decrement the bureaucrat’s grade.
   If the grade goes out of range, both functions must throw the same exceptions as the
   constructor.
 *
 * */
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
# include <exception>
# include <iostream>
# include <string>

class AForm;

class Bureaucrat {
	private:
		const std::string   _name;
		int                 _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void    setGrade(int value);
		
		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &form);
		void executeForm(AForm const &form) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
