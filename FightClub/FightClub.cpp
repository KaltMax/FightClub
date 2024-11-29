#include <iostream>
#include "game.hpp"
#include "displays.hpp"
#include "character.hpp"
#include "necromancer.hpp"
#include "paladin.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    bool playAgain = true;

    Displays::displayHeader();

    while (playAgain) {
        Displays::clearScreen();
        // characterselection
        std::cout << "Player 1: Set up your character!" << std::endl;
        Character* player1 = Game::chooseCharacter();
        std::cout << "Player 2: Set up your character! " << std::endl;
        Character* player2 = Game::chooseCharacter();

        // game loop
        while (true) {
            // Player1 turn
            Game::displayStats(player1, player2);

            Game::chooseSkill(player1, player2);

            if (!Game::checkIfAlive(player1, player2)) {
                Game::displayVictoryCounts();
                break;
            }
            // Player2 turn
            Game::displayStats(player1, player2);

            Game::chooseSkill(player2, player1);

            if (!Game::checkIfAlive(player1, player2)) {
                Game::displayVictoryCounts();
                break;
            }
        }
        playAgain = Game::playAgain();
    }

    return 0;
}


