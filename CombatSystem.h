//
// Created by MATEO HERNANDEZ on 16/11/25.
//

#ifndef COMBATSYSTEM_H
#define COMBATSYSTEM_H

#include "Hero.h"
#include "Monster.h"

class CombatSystem {

private:
    Hero* hero; // cambiar a puntero
    Monster* enemy; // The enemy is the monster that appeared in the current room
    bool isBattleOver() const;
    void UpgradeStats();

public:
    CombatSystem(Hero& hero, Monster& enemy): hero(hero), enemy(enemy) {}
    void battleStatus() const;
    static void turn();

};



#endif //COMBATSYSTEM_H
