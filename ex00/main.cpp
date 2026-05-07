#include "Bureaucrat.hpp"

int main()
{
    std::cout << "           ___" << std::endl;
    std::cout << "         .';:;'." << std::endl;
    std::cout << "        /_' _' /\\   __" << std::endl;
    std::cout << "        ;a/ e= J/-'\"  '." << std::endl;
    std::cout << "        \\ ~_   (  -'  ( ;_ ,." << std::endl;
    std::cout << "         L~\"'_.    -.  \\ ./  )" << std::endl;
    std::cout << "         ,'-' '-._  _;  )'   (" << std::endl;
    std::cout << "       .' .'   _.'\")  \\  \\(  |" << std::endl;
    std::cout << "      /  (  .-'   __\\{`', \\  |" << std::endl;
    std::cout << "     / .'  /  _.-'   \"  ; /  |" << std::endl;
    std::cout << "    / /    '-._'-,     / / \\ (" << std::endl;
    std::cout << " __/ (_    ,;' .-'    / /  /_'-._" << std::endl;
    std::cout << "`\"-'` ~`  ccc.'   __.','     \\j\\L\\" << std::endl;
    std::cout << "                 .='/|\\7" << std::endl;
    std::cout << "     aag" << std::endl << std::endl;

    std::cout << "--- TEST 1: SUCCESSFUL ASCENSION (Aragorn) ---" << std::endl;
    try 
    {
        Bureaucrat aragorn("Aragorn", 10);
        std::cout << aragorn << std::endl;
        std::cout << "Aragorn becomes King (Incrementing...)" << std::endl;
        aragorn.incrementGrade();
        std::cout << "New rank: " << aragorn << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: SUCCESSFUL DEMOTION (Boromir) ---" << std::endl;
    try 
    {
        Bureaucrat boromir("Boromir", 42);
        std::cout << boromir << std::endl;
        std::cout << "Boromir makes a mistake (Decrementing...)" << std::endl;
        boromir.decrementGrade();
        std::cout << "New rank: " << boromir << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: GANDALF AT LIMIT (Too High) ---" << std::endl;
    try 
    {
        Bureaucrat gandalf("Gandalf the White", 1);
        std::cout << gandalf << std::endl;
        std::cout << "Trying to increment Gandalf beyond grade 1..." << std::endl;
        gandalf.incrementGrade();
    }
    catch (std::exception &e) 
    {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: PIPPIN AT LIMIT (Too Low) ---" << std::endl;
    try 
    {
        Bureaucrat pippin("Peregrin Took", 150);
        std::cout << pippin << std::endl;
        std::cout << "Pippin forgets to do any work (Decrementing...)" << std::endl;
        pippin.decrementGrade();
    }
    catch (std::exception &e) 
    {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    return 0;
}