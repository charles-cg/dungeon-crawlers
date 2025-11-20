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
    while (hero.getHp() > 0 && enemy.getHp() > 0) {
        //Hero´s turn
        battleStatus();

        int heroDamage = hero.getAtk() - enemy.getDef();

        if (heroDamage < 0){
            std::cout << hero.getName() << " missed!" << std::endl;
            heroDamage = 0;
        } else {
            enemy.setHp(enemy.getHp() - heroDamage);
            std::cout << hero.getName() << " attacks! " << enemy.getName() << std::endl;
            std::cout << " Damage dealt: " << heroDamage << std::endl;
            std::cout << std::endl;
            std::cout << "Curent battle status" << std::endl;

            battleStatus();
        }
        if(enemy.getHp() > 0) {
            int enemyDamage = enemy.getAtk() - hero.getDef();

            if (enemyDamage < 0) {
                std::cout << enemy.getName() << " missed!" << std::endl;
                enemyDamage = 0;
            } else {
                hero.setHp(hero.getHp() - enemyDamage);
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
            } else if (hero.getHp() == 0) {
                std::cout << enemy.getName() << " won the battle!" << std::endl;
                std::cout << "Game Over" << std::endl;
            }
            battleStatus();
        }
    }
}

bool CombatSystem::isBattleOver() const {
        return hero.getHp() <= 0 || enemy.getHp() <= 0;
}

//To do, crear función max y agregar el rand() para el battle system