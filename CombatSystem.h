//
// Created by MATEO HERNANDEZ on 16/11/25.
//

#ifndef COMBATSYSTEM_H
#define COMBATSYSTEM_H

#include "Hero.h"
#include "Entity.h"
#include "Monster.h"

class CombatSystem {

private:

Hero& hero;
Monster& enemy; // The enemy is the monster that appeared in the current room

public:

CombatSystem(Hero& hero, Monster& enemy): hero(hero), enemy(enemy) {}
void battleStatus() const;
void turn();
bool isBattleOver() const;

};



#endif //COMBATSYSTEM_H
