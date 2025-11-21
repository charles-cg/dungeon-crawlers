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
            std::cout << "Current battle status" << std::endl;

            battleStatus();
        }
        if(enemy.getHp() > 0) {
            int enemyDamage = enemy.getAtk() - hero.getDef();
            int chance = rand() % 100; // Optated to use rand() due to simplicity rather than <random> library
            float accuracy = enemy.getAccuracy();
            int accuracyPercentage = accuracy * 100;

            if (enemyDamage < 0) {
                std::cout << enemy.getName() << " missed!" << std::endl;
                enemyDamage = 0;
            } else {
                if (chance < accuracyPercentage) {
                    hero.setHp(hero.getHp() - enemyDamage);
                    std::cout << enemy.getName() << " attacks! " << hero.getName() << std::endl;
                    std::cout << " Damage dealt: " << enemyDamage << std::endl;
                    std::cout << std::endl;
                    std::cout << "Curent battle status" << std::endl;

                    battleStatus();

                } else if (chance > accuracyPercentage) {
                    std::cout << enemy.getName() << " missed!" << std::endl;
                    battleStatus();
                }
            }
        }
        if(isBattleOver()) {
            std::cout << " The battle is over!" << std::endl;
            if (enemy.getHp() == 0) {
                int pointsRewarded = enemy.getReward(); // Preguntar si es necesario hacer un cast
                std::cout << hero.getName() << " won the battle!" << std::endl;
                std::cout << "Points granted by defeating " << enemy.getName() << " are: " << pointsRewarded << " points!" << std::endl;
                hero.addUpgradePoints(pointsRewarded);
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

void CombatSystem::UpgradeStats() {
    int points = hero.getUpgradePoints();

    while (points > 0) {
        std::cout << "UPGRADE SYSTEM" << std::endl;
        std::cout << "Points left: " << points << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cout << "1- Upgrade hit points" << std::endl;
        std::cout << "2- Upgrade defense" << std::endl;
        std::cout << "3- Upgrade attack" << std::endl;
        std::cout << "Exit" << std::endl;

        int option;
        std::cin >> option;

        switch (option) {
            case 1:
                hero.spendUpgradePoints();
                break;
            case 2:
                hero.spendUpgradePoints();
                break;
            case 3:
                hero.spendUpgradePoints();
                break;
            case 4:
                std::cout << "Goodbye!" << std::endl;
                break;
        }
    }

}

//To do, agregar el reward system