#include "necromancer.hpp"
#include "skills.hpp"

Necromancer::Necromancer(const std::string playerName) : Character(15) {
	setCharacterType("Necromancer");
	setName(playerName);
	addSkill(std::make_unique<skillSkeletonWarrior>());
	addSkill(std::make_unique<skillBoneShield>());
	setBoneShield(2);
}

Necromancer::~Necromancer() {

}

void Necromancer::setBoneShield(int shield) {
	boneShield = boneShield + shield;
}

void Necromancer::dealDamage(int damage) {
	if (boneShield > 0) {
		std::cout << "Bone Shield absorbs the attack!" << std::endl;
		boneShield--;
		return;
	}
	else if (damage > 0) {
		lifePoints -= damage;
	}
}

int Necromancer::getBoneShield() const {
	return boneShield;
}

