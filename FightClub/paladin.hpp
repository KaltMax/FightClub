#pragma once
#include "Character.hpp"  
#include <iostream>

class Paladin : public Character {
public:
    Paladin(const std::string playerName);
    virtual ~Paladin();
    void setDivineShield(int shield);
    int getDivineShield() const;
    void dealDamage(int damage) override;

protected:
    int divineShield = 0;

private:

};