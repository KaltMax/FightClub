#pragma once
#include "Character.hpp"  
#include <iostream>

class Necromancer : public Character {  
public:
    Necromancer(const std::string playername);  
    virtual ~Necromancer();  
    int getBoneShield() const;
    void setBoneShield(int shield);
    void dealDamage(int damage) override;

protected:
    int boneShield = 0;

private:
    
};