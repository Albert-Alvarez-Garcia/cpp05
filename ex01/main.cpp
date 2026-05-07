#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "            _,,,,_" << std::endl;
    std::cout << "           .(((()()()(" << std::endl;
    std::cout << "           ())()()))())" << std::endl;
    std::cout << "          ((,.\"\"-,(()())" << std::endl;
    std::cout << "          \\ @ ) @  )/)()" << std::endl;
    std::cout << "          .'-. -   (C))" << std::endl;
    std::cout << "          (  (_. ` .))" << std::endl;
    std::cout << "          \\ .___.   .'" << std::endl;
    std::cout << "         __`.____.' \\_____" << std::endl;
    std::cout << "       /(  \" /))_\\.-'  (  `\\" << std::endl;
    std::cout << "      / ( _  o/(o \"  _ \\   `." << std::endl;
    std::cout << "     (  /. . o)/o       (    \\" << std::endl;
    std::cout << "    /   ( . o/(o .  \"  .)\\    )" << std::endl;
    std::cout << "   (   )( _ o)\\o  _   . )(    )" << std::endl;
    std::cout << "   (   (.' o)/o    `.   )/   /" << std::endl;
    std::cout << "    \\ ( . \"o((o .  . ` _/   )" << std::endl;
    std::cout << "     (/)____o)/o______(c`-.)" << std::endl;
    std::cout << "      |)_|__[H]___|___(//)'" << std::endl;
    std::cout << "      (   )  : \\  )    `''" << std::endl;
    std::cout << "      (_)  (  )    \\ (_ )" << std::endl;
    std::cout << "      (      .   (      )" << std::endl;
    std::cout << "     (  ( )   (\\  /  )  )" << std::endl;
    std::cout << "      (    (   (       )" << std::endl;
    std::cout << "      (  ( ) ./ \\ ( .( )" << std::endl;
    std::cout << "       (     )  (     )" << std::endl;
    std::cout << "       |\"^\"\")    (\"^\"\")" << std::endl;
    std::cout << "       |    /    \\    |" << std::endl;
    std::cout << "       ),,,,)    |,,,,/" << std::endl;
    std::cout << "       /,,,,(    ),,,,(" << std::endl;
    std::cout << "    .-',,,,,)    /,,,,\\" << std::endl;
    std::cout << "   ((((_).-'    (_)())))" << std::endl << std::endl;

    std::cout << "--- TEST 1: Form Creation & Limits ---" << std::endl;
    try {
        Form f1("Top Secret Document", 0, 50); // Grade too high
    } catch (std::exception &e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Legolas signs an Elven Scroll ---" << std::endl;
    try {
        Bureaucrat legolas("Legolas", 5);
        Form scroll("Mirkwood Entry Permit", 10, 20);
        
        std::cout << scroll << std::endl;
        legolas.signForm(scroll);
        std::cout << scroll << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Gimli tries to sign a Royal Decree ---" << std::endl;
    try {
        Bureaucrat gimli("Gimli", 45);
        Form decree("Iron Hills Constitution", 1, 1);
        
        std::cout << decree << std::endl;
        gimli.signForm(decree); // This should fail and print the "couldn't sign" message
        std::cout << decree << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}