#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "skillBase.hpp"

class Character {
	public:
		Character(int startingLife);
		virtual ~Character();

		std::vector<std::unique_ptr<Skill>> skills;

		void addSkill(std::unique_ptr<Skill> skill);
		void useSkill(int index, Character& target);
		virtual void dealDamage(int damage);
		virtual void healSelf(int heal);
		int getLifePoints() const;
		void setCharacterType(std::string type);
		std::string getCharacterType() const;
		void setName(std::string name);
		std::string getName() const;
		bool isAlive();

	protected:
		int lifePoints;
		std::string name;
		std::string characterType;

	private:

};