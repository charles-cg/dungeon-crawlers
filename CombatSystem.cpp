//
// Created by MATEO HERNANDEZ on 16/11/25.
//

#include "CombatSystem.h"

void CombatSystem::battleStatus() const {
std::cout << "Battle Status" << std::endl;
std::cout << "Hero: " << hero.getName() << " HP: " << hero.getHp() << std::endl;
std::cout << "Enemy: " << enemy.getName() << " HP: " << enemy.getHp() << std::endl;
std::cout << std::endl;
}

void CombatSystem::turn() {
int heroDamage =
}

bool CombatSystem::isBattleOver() const {
return hero.getHp() <= 0 || enemy.getHp() <= 0;
}