//
// Created by MATEO HERNANDEZ on 16/11/25.
//

#include "CombatSystem.h"
#include <iostream>
#include "Monster.h"

void CombatSystem::battleStatus() const {

std::cout << "Battle Status" << std::endl;
std::cout << "Hero: " << hero.getName() << " Hit Points: " << hero.getHp() << " Defence: " << hero.getDef() << std::endl;
std::cout << "Enemy: " << enemy.getName() << " Hit Points: " << enemy.getHp() << " Defence: " << enemy.getDef() << std::endl;
std::cout << std::endl;

}

void CombatSystem::turn() {
//Hero´s turn
battleStatus();
int heroDamage = hero.getAtk() - enemy.getDef();

if (enemy.getDef() > hero.getAtk()) {
std::cout << " You missed! " << enemy.getName() << "defence was stronger than your attack" << std::endl;
} else if (heroDamage <= enemy.getDef()) {

enemy.setHp(enemy.getHp() - heroDamage);

std::cout << hero.getName() << " attacks! " << enemy.getName() << std::endl;
std::cout << " Damage dealt: " << heroDamage << std::endl;
std::cout << std::endl;
std::cout << "Curent battle status" << std::endl;
battleStatus();
}


//Enemy`s/Monster's turn
if(enemy.Hp() > 0) {

int enemyDamage = enemy.getAtk() - hero.getDef();
// Here goes the accuracy part

if (hero.getDef() > enemy.getAtk()) {
std::cout << enemy.getName() << " missed!" << std::endl;

} else if (enemyDamage <= hero.getDef()) {
hero.setHp(hero.getHp() - enemyDamage);
battleStatus();

std::cout << enemy.getName() << " attacks! " << hero.getName() << std::endl;
std::cout << " Damage dealt: " << enemyDamage << std::endl;
std::cout << std::endl;
std::cout << "Curent battle status" << std::endl;
battleStatus();
}

}

if(isBattleOver()) {
std::cout << " The battle is over!" << std::endl;
if (enemy.getHp() == 0) {
std::cout << hero.getName() << " won the battle!" << std::endl;
} else (hero.getHp() == 0) {
std::cout << enemy.getName() << " won the battle!" << std::endl;
std::cout << "Game Over" << std::endl;
}
battleStatus();

}

}

bool CombatSystem::isBattleOver() const {
return hero.getHp() <= 0 || enemy.getHp() <= 0;
}

//To do, crear función max y agregar el rand() para el battle system