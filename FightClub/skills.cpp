#include "skills.hpp"

void skillSkeletonWarrior::execute(Character& executor, Character& target) {
	displayDescription();
	target.dealDamage(5);
}

void skillSkeletonWarrior::displayDescription() const {
	std::cout << "You summon a Skeleton Warrior to attack your enemy. (deal 5 damage)\n" << std::endl;
}


void skillDrawEssence::execute(Character& executor, Character& target) {
	displayDescription();
	executor.healSelf(3);
	target.dealDamage(2);
}

void skillDrawEssence::displayDescription() const {
	std::cout << "You draw on the life force of your enemy to heal yourself. (Heals 3 HP and deals 2 damage to your enemy)\n" << std::endl;
}


void skillCurse::execute(Character& executor, Character& target) {
	displayDescription();
	executor.dealDamage(5);
	target.dealDamage(10);
}

void skillCurse::displayDescription() const {
	std::cout << "You curse the enemy, sacrificing your own vitality for greater damage. (loose 5 HP and deal 10 damage)\n" << std::endl;
}



void skillBoneShield::execute(Character& executor, Character& target) {
	// Attempt to cast the executor to types that can have boneShield
	if (auto necro = dynamic_cast<Necromancer*>(&executor)) {
		necro->setBoneShield(1);
		displayDescription();
	}
	else if (auto custom = dynamic_cast<CustomCharacter*>(&executor)) {
		custom->setBoneShield(1);
		displayDescription();
	}
}

void skillBoneShield::displayDescription() const {
	std::cout << "You summon a Bone Shield to protect yourself from the next attack.\n" << std::endl;
}


void skillHolyBlast::execute(Character& executor, Character& target) {
	displayDescription();
	target.dealDamage(3);
	executor.healSelf(2);
}

void skillHolyBlast::displayDescription() const {
	std::cout << "Light coalesces into a holy blast directed at the enemy. (heal 2 HP and deal 3 damage)\n" << std::endl;
}


void skillDivineShield::execute(Character& executor, Character& target) {
	// Attempt to cast the executor to types that can have divineShield
	if (auto paladin = dynamic_cast<Paladin*>(&executor)) {
		paladin->setDivineShield(2);
		displayDescription();
	}
	else if (auto custom = dynamic_cast<CustomCharacter*>(&executor)) {
		custom->setDivineShield(2);
		displayDescription();
	}
}

void skillDivineShield::displayDescription() const {
	std::cout << "You summon a Divine Shield to reduce the damage of the next 2 attacks by 3.\n" << std::endl;
}


void skillSceptreSwing::execute(Character& executor, Character& target) {
	displayDescription();
	target.dealDamage(5);
}

void skillSceptreSwing::displayDescription() const {
	std::cout << "Empowered by divine Wrath, you swing your mighty sceptre through the air. (deal 5 damage)\n" << std::endl;
}


void skillHolyLight::execute(Character& executor, Character& target) {
	displayDescription();
	executor.healSelf(5);
}

void skillHolyLight::displayDescription() const {
	std::cout << "Warm light envelops you, sealing your wounds. (heal 5 HP)\n" << std::endl;
}

