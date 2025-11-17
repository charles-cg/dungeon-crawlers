//
// Created by MATEO HERNANDEZ on 16/11/25.
//

#ifndef COMBATSYSTEM_H
#define COMBATSYSTEM_H



class CombatSystem {

private:

Hero& hero;
Entity& enemy; // The enemy is the monster that appeared in the current room

public:

CombatSystem(Hero& hero, Entity& enemy): hero(hero), enemy(enemy) {}
void battleStatus() const;
void turn();
bool isBattleOver() const;

};



#endif //COMBATSYSTEM_H
