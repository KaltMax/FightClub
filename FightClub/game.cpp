#pragma once
#include "game.hpp"
#include "displays.hpp"
#include "character.hpp"
#include "paladin.hpp"
#include "necromancer.hpp"
#include "customCharacter.hpp"
#include "skills.hpp"

int Game::paladinVictories = 0;
int Game::necromancerVictories = 0;
int Game::customCharacterVictories = 0;

std::string Game::enterPlayerName() {
	std::string playerName;

	std::cout << "Enter your name: ";
	std::cin >> playerName;

	Displays::clearScreen();
	return playerName;
}

Character* Game::createCustomCharacter(const std::string& playerName) {
	Character* newCustomCharacter = new CustomCharacter();
	selectCustomCharacterSkills(newCustomCharacter);
	newCustomCharacter->setCharacterType("Custom Character");
	newCustomCharacter->setName(playerName);
	return newCustomCharacter;
}

void Game::displayCharacterInfo(Character* character) {
	Displays::clearScreen();
	std::cout << character->getName() << ", you have chosen " << character->getCharacterType() << ".\n" << std::endl;
	std::cout << "Your " << character->getCharacterType() << " has been created with the following skills: \n" << std::endl;
	std::cout << "1.) " << character->skills[0]->getSkillName() << std::endl;
	character->skills[0]->displayDescription();
	std::cout << "2.) " << character->skills[1]->getSkillName() << std::endl;
	character->skills[1]->displayDescription();
	Displays::enterToContinue();
	Displays::clearScreen();
}

Character* Game::chooseCharacter() {
	std::string playerName = enterPlayerName();
	Displays::clearScreen();

	while (true) {
		std::cout << playerName << " choose your class: " << std::endl;
		std::cout << "1. Paladin" << std::endl;
		std::cout << "2. Necromancer" << std::endl;
		std::cout << "3. Create a custom character\n" << std::endl;
		std::cout << "Enter your choice: ";

		int choice;
		std::cin >> choice;

		Character* newCharacter = nullptr;

		switch (choice) {
		case 1:
			Displays::clearScreen();
			newCharacter = new Paladin(playerName);
			break;
		case 2:
			Displays::clearScreen();
			newCharacter = new Necromancer(playerName);
			break;
		case 3:
			Displays::clearScreen();
			newCharacter = Game::createCustomCharacter(playerName);
			break;
		default:
			std::cout << "\nInvalid choice. Please try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (newCharacter) {
			Game::displayCharacterInfo(newCharacter);
			return newCharacter;
		}
	}
}

std::vector<std::unique_ptr<Skill>> Game::createSkillsList() {
	std::vector<std::unique_ptr<Skill>> skills;
	skills.push_back(std::make_unique<skillSkeletonWarrior>());
	skills.push_back(std::make_unique<skillDrawEssence>());
	skills.push_back(std::make_unique<skillCurse>());
	skills.push_back(std::make_unique<skillBoneShield>());
	skills.push_back(std::make_unique<skillHolyBlast>());
	skills.push_back(std::make_unique<skillDivineShield>());
	skills.push_back(std::make_unique<skillSceptreSwing>());
	skills.push_back(std::make_unique<skillHolyLight>());
	return skills;
}

void Game::selectCustomCharacterSkills(Character* customCharacter) {
	std::vector<std::unique_ptr<Skill>> availableSkills = createSkillsList(); // Fill the vector with all the available Skills
	int skillCount = 0;

	std::cout << "Select 2 skills for your custom character:\n" << std::endl;

	// Display the available skills
	for (int i = 0; i < availableSkills.size(); ++i) {
		std::cout << i + 1 << ".) " << availableSkills[i]->getSkillName() << std::endl;
		availableSkills[i]->displayDescription();
		std::cout << "\n"; 
	}

	while (skillCount < 2) {
		std::cout << "Enter the number of the " << skillCount + 1 << ". skill you want to add (1 - " << availableSkills.size() << ") : ";
		int choice = 0;
		std::cin >> choice;

		if (choice > 0 && choice <= availableSkills.size() && availableSkills[choice - 1] != nullptr) {
			customCharacter->addSkill(std::move(availableSkills[choice - 1]));
			std::cout << "\n" << customCharacter->skills[skillCount]->getSkillName() << " has been added to your custom character.\n" << std::endl;
			++skillCount;
		}
		else {
			std::cout << "\nInvalid choice. Please select a skill from the list!\n" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	}
	Displays::enterToContinue();

}

void Game::chooseSkill(Character* activePlayer, Character* targetPlayer) {
	int action;
	bool validChoice = false;

	std::cout << "\n" << activePlayer->getName() << "'s turn. Choose your skill!" << std::endl;
	std::cout << "1.) " << activePlayer->skills[0]->getSkillName() << std::endl;
	std::cout << "2.) " << activePlayer->skills[1]->getSkillName() << std::endl;
	
	while (!validChoice) {
		std::cout << "Enter your choice: ";
		std::cin >> action;
		std::cout << "\n";

		switch (action) {
		case 1:
			activePlayer->useSkill(action - 1, *targetPlayer);
			validChoice = true;
			break;
		case 2:
			activePlayer->useSkill(action - 1, *targetPlayer);
			validChoice = true;
			break;
		default:
			std::cout << "\nInvalid action. Try again!" << std::endl;
		}
	}
	Displays::enterToContinue();
	Displays::clearScreen();
}

void Game::displayStats(Character* player1, Character* player2) {
	std::cout << "\n" << player1->getName() << " | HP: " << player1->getLifePoints() << std::endl;
	std::cout << "\n" << player2->getName() << " | HP: " << player2->getLifePoints() << std::endl;
}

void Game::incrementVictories(Character* player) {
	if (player->getCharacterType() == "Paladin") {
		++paladinVictories;
	}
	else if (player->getCharacterType() == "Necromancer") {
		++necromancerVictories;
	}
	else {
		++customCharacterVictories;
	}
}

void Game::displayVictoryCounts() {
	std::cout << "\nVictory Counts:" << std::endl;
	std::cout << "Paladin: " << paladinVictories << std::endl;
	std::cout << "Necromancer: " << necromancerVictories << std::endl;
	std::cout << "Custom Characters: " << customCharacterVictories << "\n" << std::endl;
}

bool Game::checkIfAlive(Character* player1, Character* player2) {
	if (!player1->isAlive()) {
		std::cout << "\n" << player2->getName() << " has won and has " << player2->getLifePoints() << " HP left." << std::endl;
		incrementVictories(player2);
		return false;
	}
	if (!player2->isAlive()) {
		std::cout << "\n" << player1->getName() << " has won and has " << player1->getLifePoints() << " HP left." << std::endl;
		incrementVictories(player1);
		return false;
	}
	return true;
}

bool Game::playAgain() {
	while (true) {
		std::string againInput = "";
		std::cout << "\nIf you want to play Again press ENTER. If you are weak and want to quit press 'q'" << std::endl;
		std::getline(std::cin, againInput);
		if (againInput.empty()) {
			return true;
		}
		else if (againInput == "q") {
			Displays::clearScreen();
			std::cout << "Thanks for playing!" << std::endl;
			std::cout << "Press ENTER to close the game!\n";
			std::cin.get();
			return false;
		}
	}
}
