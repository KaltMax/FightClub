#pragma once
#include "Character.hpp"  
#include <iostream>

class CustomCharacter : public Character {
public:
    CustomCharacter();
    virtual ~CustomCharacter();
    void dealDamage(int damage) override;
    void setBoneShield(int shield);
    int getBoneShield() const;
    void setDivineShield(int shield);
    int getDivineShield() const;

protected:
	int boneShield = 0;
	int divineShield = 0;

private:

};