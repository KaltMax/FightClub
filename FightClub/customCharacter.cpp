#include "customCharacter.hpp"

CustomCharacter::CustomCharacter() : Character(20) {

}

CustomCharacter::~CustomCharacter() {

}

void CustomCharacter::dealDamage(int damage) {
	if (boneShield > 0) {
		std::cout << "Bone Shield absorbs the attack!" << std::endl;
		boneShield--;
		return;
	}

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

void CustomCharacter::setBoneShield(int shield) {
	boneShield = boneShield + shield;
}

int CustomCharacter::getBoneShield() const {
	return boneShield;
}

void CustomCharacter::setDivineShield(int shield) {
	divineShield = divineShield + shield;
}

int CustomCharacter::getDivineShield() const {
	return divineShield;
}
