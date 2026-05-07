#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    // Seed for Robotomy random success
    std::srand(std::time(NULL));

    std::cout << "           .;;;,.," << std::endl;
    std::cout << "         ;sXs=SV2;" << std::endl;
    std::cout << "        ;;Y; _ ^_;" << std::endl;
    std::cout << "        :LS  a (a(" << std::endl;
    std::cout << "       ;;;;   .. ;" << std::endl;
    std::cout << "       ;';)'. ==/;" << std::endl;
    std::cout << "     _.-';   '-';-;_" << std::endl;
    std::cout << "    /\\\\  ;;    ;; //'. " << std::endl;
    std::cout << "   | ,\\_;_____; '/,  \\" << std::endl;
    std::cout << "   | | ';;--- ;;-' |   \\" << std::endl;
    std::cout << "   F |  ;     ;    |\\   \\" << std::endl;
    std::cout << "  J  .\\';    ;     | ;--t" << std::endl;
    std::cout << "  |__/ )      ;   / .'';|" << std::endl;
    std::cout << "  j  '-,__   __.---;    (" << std::endl;
    std::cout << "   )  ( =r'-| ' .  \\  '; )" << std::endl;
    std::cout << "   | : \"-s=-|   '  |   ; |" << std::endl;
    std::cout << "   | : ; \\  |   |  |     |" << std::endl;
    std::cout << "    L; :  L |      ;     |" << std::endl;
    std::cout << "   J ;    | |   :  ;     |" << std::endl;
    std::cout << "   | ;    J |   :   ;    |" << std::endl;
    std::cout << "   L.'     L|       (    |" << std::endl;
    std::cout << "  J ;  :   ||  '    ;    |" << std::endl;
    std::cout << "  | ;      ||  :    ;    |" << std::endl;
    std::cout << "  |,/  ;   ||       ;    \\" << std::endl;
    std::cout << "  |(   :   ||   __.'     |" << std::endl;
    std::cout << "  | >  |   ||,-'         |" << std::endl;
    std::cout << "  |/   ;   |Z_,          |" << std::endl;
    std::cout << "  (,  _L---J   '.        |" << std::endl;
    std::cout << "   '-'|       |  '--._   |" << std::endl;
    std::cout << "      |       :     ; '-r" << std::endl;
    std::cout << "      |   ;   |     |; ||-._____" << std::endl;
    std::cout << "aag __/ | ;   '|    |; ;(-'.--' ';" << std::endl;
    std::cout << "  ,'_'/;  ',   ; \\ ( _L_.'-._'---,;" << std::endl;
    std::cout << " '-----L___;--.,__;-' --''-.'---'" << std::endl << std::endl;

    std::cout << "--- THE FELLOWSHIP OF THE FORM ---" << std::endl;

    try 
    {
        Bureaucrat legolas("Legolas", 1);
        Bureaucrat pippin("Pippin", 150);

        ShrubberyCreationForm shrub("Lothlorien");
        RobotomyRequestForm robot("Uruk-hai");
        PresidentialPardonForm pardon("Gollum");

        std::cout << "\n[TEST 1: Shrubbery]" << std::endl;
        pippin.executeForm(shrub); // Fails: Not signed
        legolas.signForm(shrub);
        pippin.executeForm(shrub); // Fails: Grade too low
        legolas.executeForm(shrub); // Success: Creates Lothlorien_shrubbery

        std::cout << "\n[TEST 2: Robotomy]" << std::endl;
        legolas.signForm(robot);
        legolas.executeForm(robot);
        legolas.executeForm(robot);
        legolas.executeForm(robot);

        std::cout << "\n[TEST 3: Pardon]" << std::endl;
        legolas.signForm(pardon);
        legolas.executeForm(pardon);

    } 
    catch (std::exception &e) 
    {
        std::cout << "Critical error: " << e.what() << std::endl;
    }

    return 0;
}