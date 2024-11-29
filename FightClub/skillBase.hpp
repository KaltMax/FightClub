#pragma once
#include "character.hpp"

class Character;

class Skill {
public:
    Skill(const std::string& skillName) : skillName(skillName) {};
    virtual ~Skill() {}
    virtual void execute(Character& executor, Character& target) = 0;
    virtual void displayDescription() const {};
    std::string getSkillName() const { return skillName; };

protected:
    std::string skillName;
};