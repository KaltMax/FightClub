#include "Character.hpp"
#include "skillBase.hpp"
#include "necromancer.hpp"
#include "paladin.hpp"
#include "customCharacter.hpp"

class skillSkeletonWarrior : public Skill {
public:
    skillSkeletonWarrior() : Skill("Skeleton Warrior") {};
    void execute(Character& executor, Character& target) override;
    void displayDescription() const override;
};

class skillDrawEssence : public Skill {
public:
    skillDrawEssence() : Skill("Draw Essence") {};
    void execute(Character& executor, Character& target) override;
    void displayDescription() const override;
};

class skillCurse : public Skill {
public:
    skillCurse() : Skill("Curse") {};
    void execute(Character& executor, Character& target) override;
    void displayDescription() const override;
};

class skillBoneShield : public Skill {
public:
    skillBoneShield() : Skill("Bone Shield") {};
    void execute(Character& executor, Character& target) override;
    void displayDescription() const override;
};

class skillHolyBlast : public Skill {
public:
    skillHolyBlast() : Skill("Holy Blast") {};
    void execute(Character& executor, Character& target) override;
    void displayDescription() const override;
};

class skillDivineShield : public Skill {
    public:
    skillDivineShield() : Skill("Divine Shield") {};
    void execute(Character& executor, Character& target) override;
    void displayDescription() const override;
};

class skillSceptreSwing : public Skill {
public:
    skillSceptreSwing() : Skill("Sceptre Swing") {};
    void execute(Character& executor, Character& target) override;
    void displayDescription() const override;
};

class skillHolyLight : public Skill {
public:
    skillHolyLight() : Skill("Holy Light") {};
    void execute(Character& executor, Character& target) override;
    void displayDescription() const override;
};

