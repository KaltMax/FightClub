#pragma once
#include "character.hpp"
#include <iostream>
#include <string>


class Game {
	public:
		static Character* chooseCharacter();
		static void chooseSkill(Character* activePlayer, Character* targetPlayer);
		static void displayStats(Character* player1, Character* player2);
		static bool checkIfAlive(Character* player1, Character* player2);
		static void displayVictoryCounts();
		static bool playAgain();

	private:
		static std::string enterPlayerName();
		static void displayCharacterInfo(Character* character);
		static Character* createCustomCharacter(const std::string& playerName);
		static void selectCustomCharacterSkills(Character* customCharacter);
		static std::vector<std::unique_ptr<Skill>> availableSkills;
		static std::vector<std::unique_ptr<Skill>> createSkillsList();

		static int paladinVictories;
		static int necromancerVictories;
		static int customCharacterVictories;
		static void incrementVictories(Character* character);
};