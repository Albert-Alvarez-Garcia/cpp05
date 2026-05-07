#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    // Semilla para la aleatoriedad de la robotomía
    std::srand(std::time(NULL));

// --- ARTE ASCII DE PIPPIN CORREGIDO PARA C++98 ---
    std::cout << "                        \\\\ : /" << std::endl;
    std::cout << "                    '-: __ :-'" << std::endl;
    std::cout << "                    -: )(_ :--" << std::endl;
    std::cout << "                    -' |r-_i'-" << std::endl;
    std::cout << "            ,sSSSSs, (2-,7" << std::endl;
    std::cout << "            sS';:'`Ss )-j" << std::endl;
    std::cout << "           ;K e (e s7 / (" << std::endl;
    std::cout << "            S, '' SJ ( ;/" << std::endl;
    std::cout << "            sL_~~_;(S_) _7" << std::endl;
    std::cout << "|, 'J)_.-' />'-' `Z" << std::endl;
    std::cout << "j J /-;-A'-'|'--'-j\\\\" << std::endl;
    std::cout << " LL ) |/ : / \\\\" << std::endl;
    std::cout << "  \\\\ \\\\ | | | '._.'| L" << std::endl;
    std::cout << "   \\\\ \\\\ | | | | \\\\ J" << std::endl;
    std::cout << "    \\\\ \\\\ _/ | | | ',|" << std::endl;
    std::cout << "     \\\\ L.,' | | | | |/" << std::endl;
    std::cout << "    _;-r-<_.| \\\\=\\\\ __.; _/" << std::endl; // Línea 29 corregida
    std::cout << "      {_}\" L-' '--' / /|" << std::endl;
    std::cout << "            | , | \\\\|" << std::endl;
    std::cout << "            | | | \")" << std::endl;
    std::cout << "            L ;| | /|" << std::endl;
    std::cout << "           /| ; | / |" << std::endl;
    std::cout << "          | | ; | ) |" << std::endl;
    std::cout << "         | | ;| | / |" << std::endl;
    std::cout << "         | ;| || | | |" << std::endl;
    std::cout << "         L-'|____|| )/ |" << std::endl;
    std::cout << "             % %/ '-,- / /" << std::endl;
    std::cout << "     AAG |% | \\\\%/_ |" << std::endl;
    std::cout << "          ___% ( )% |'-; |" << std::endl;
    std::cout << "        C;.---..' >%,( \"'" << std::endl;
    std::cout << "                   /%% /" << std::endl;
    std::cout << "                  Cccc'" << std::endl << std::endl;
    // Pippin es el Intern (el becario)
    Intern      pippin; 
    Bureaucrat  legolas("Legolas", 1);

    AForm* shrub;
    AForm* robot;
    AForm* pardon;

    std::cout << "\n[ STEP 1: Pippin makes forms for the Fellowship ]" << std::endl;
    shrub = pippin.makeForm("shrubbery creation", "Lothlorien");
    robot = pippin.makeForm("robotomy request", "Uruk-hai");
    pardon = pippin.makeForm("presidential pardon", "Gollum");

    std::cout << "\n[ STEP 2: Legolas reviews the paperwork ]" << std::endl;
    
    if (shrub) {
        legolas.signForm(*shrub);
        legolas.executeForm(*shrub);
        delete shrub;
    }

    std::cout << "--------------------------------------------" << std::endl;

    if (robot) {
        legolas.signForm(*robot);
        legolas.executeForm(*robot);
        delete robot;
    }

    std::cout << "--------------------------------------------" << std::endl;

    if (pardon) {
        legolas.signForm(*pardon);
        legolas.executeForm(*pardon);
        delete pardon;
    }

    std::cout << "\n[ STEP 3: Pippin tries to order Second Breakfast ]" << std::endl;
    AForm* unknown = pippin.makeForm("second breakfast", "The Shire");
    if (unknown) {
        delete unknown;
    }

    std::cout << "\n--- END OF MODULE 05 ---" << std::endl;

    return 0;
}