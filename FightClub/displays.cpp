#include "displays.hpp"

void Displays::displayHeader(){
    std::cout <<
        "    _______       __    __     ________      __  \n"
        "   / ____(_)___ _/ /_  / /_   / ____/ /_  __/ /_ \n"
        "  / /_  / / __ `/ __ \\/ __/  / /   / / / / / __ \\\n"
        " / __/ / / /_/ / / / / /_   / /___/ / /_/ / /_/ /\n"
        "/_/   /_/\\__, /_/ /_/\\__/   \\____/_/\\__,_/_.___/ \n"
        "        /____/                                   \n"
        "First rule of Fight Club: You do not talk about Fight Club!\n\n";
        enterToContinue2();
}

void Displays::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    // Assume POSIX
    system("clear");
#endif
}

// Utility Funktion, um im Loop fortzufahren (Press Enter)
void Displays::enterToContinue() {
    std::cout << "\nPress ENTER to continue!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); // Warten auf die Eingabetaste
}

void Displays::enterToContinue2() {
    std::cout << "\nPress ENTER to continue!" << std::endl;
    std::cin.get(); // Warten auf die Eingabetaste
}
