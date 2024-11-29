#include "paladin.hpp"
#include "skills.hpp"

Paladin::Paladin(const std::string playerName) : Character(15) {
	setCharacterType("Paladin");
	setName(playerName);
	addSkill(std::make_unique<skillSceptreSwing>());
	addSkill(std::make_unique<skillDivineShield>());
	setDivineShield(1);
}

Paladin::~Paladin() {

}

void Paladin::setDivineShield(int shield) {
	divineShield = divineShield + shield;
}

int Paladin::getDivineShield() const {
	return divineShield;
}

void Paladin::dealDamage(int damage) {
	if (divineShield > 0) {
		std::cout << "Divine Shield absorbs 3 damage of the attack!" << std::endl;
		damage = damage - 3;
		if (damage < 0) {
			damage = 0;
		}
		lifePoints -= damage;
		divineShield--;
		return;
	}
	else if (damage > 0) {
		lifePoints -= damage;
	}
}

