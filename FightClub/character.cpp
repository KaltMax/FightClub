#include "character.hpp"

Character::Character(int startingLife) {
	lifePoints = startingLife;
}

Character::~Character() {

}

void Character::addSkill(std::unique_ptr<Skill> skill) {
	if (skills.size() < 2) { 
		skills.push_back(std::move(skill));
	}
}

void Character::useSkill(int index, Character& target) {
	if (index >= 0 && index < skills.size()) {
		skills[index]->execute(*this, target);
	}
}

int Character::getLifePoints() const{
	return lifePoints;
}

void Character::setCharacterType(std::string type) {
	this->characterType = type;
}

std::string Character::getCharacterType() const {
	return this->characterType;
}

void Character::setName(std::string name) {
	this->name = name;
}

std::string Character::getName() const {
	return this->name;
}

void Character::dealDamage(int damage) {
	if (damage > 0) {
		lifePoints -= damage;
	}
}

void Character::healSelf(int heal) {
	if (heal > 0) {
		lifePoints += heal;
	}
}

bool Character::isAlive() {
	if (lifePoints > 0) {
		return true;
	}
	else {
		return false;
	}
}
