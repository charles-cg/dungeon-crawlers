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
//Hero´s turn
int heroDamage = hero.getAtk() - enemy.getDef();
enemy.setHp(enemy.getHp() - heroDamage);
battleStatus();

std::cout << hero.getName() << " attacks! " << enemy.getName() << std::endl;
std::cout " Damage dealt: " << heroDamage << std::endl;
std::cout << std::endl;
std::cout << "Curent battle status" << std::endl;
battleStatus();

//Enemy`s/Monster's turn
if(enemy.Hp() > 0) {

int enemyDamage = enemy.getAtk() - hero.getDef();
hero.setHp(hero.getHp() - enemyDamage);
battleStatus();

std::cout << enemy.getName() << " attacks! " << hero.getName() << std::endl;
std::cout << " Damage dealt: " << enemyDamage << std::endl;
std::cout << std::endl;
std::cout << "Curent battle status" << std::endl;
battleStatus();
}

if(isBattleOver()) {
std::cout << " The battle is over!" << std::endl;
battleStatus();

}

}

bool CombatSystem::isBattleOver() const {
return hero.getHp() <= 0 || enemy.getHp() <= 0;
}