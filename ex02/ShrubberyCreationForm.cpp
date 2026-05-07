#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    (void)src;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->checkExecution(executor);
    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (outfile.is_open())
    {
        outfile << "      /\\      " << std::endl;
        outfile << "     /\\*\\     " << std::endl;
        outfile << "    /\\O\\*\\    " << std::endl;
        outfile << "   /*/\\/\\/\\   " << std::endl;
        outfile << "  /\\*\\/\\*\\/\\  " << std::endl;
        outfile << "      ||      " << std::endl;
        outfile.close();
    }
}