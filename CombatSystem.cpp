//
// Created by MATEO HERNANDEZ on 16/11/25.
//

#include "CombatSystem.h"
#include <iostream>
#include <cstdlib>

void CombatSystem::battleStatus() const {

        std::cout << "Battle Status" << std::endl;
        std::cout << "Hero: " << hero->getName() << " Hit Points: " << hero->getHp() << " Defence: " << hero->getDef() << std::endl;
        std::cout << "Enemy: " << enemy->getName() << " Hit Points: " << enemy->getHp() << " Defence: " << enemy->getDef() << std::endl;
        std::cout << std::endl;
}

void CombatSystem::turn() {
    while (hero->getHp() > 0 && enemy->getHp() > 0) {
        //Hero´s turn
        battleStatus();

        float percentageDamageReducedEnemy = static_cast<float>(enemy->getDef()) / 100;
        float heroDamage = static_cast<float>(hero->getAtk()) - percentageDamageReducedEnemy;

        if (heroDamage < 0) {
            heroDamage = 0;
            std::cout << hero->getName() << " missed!" << std::endl;

            battleStatus();
        }
        if (heroDamage == 0) {
            std::cout << hero->getName() << " could not penetrate the defence of " << enemy->getName() << std::endl;

            battleStatus();

        } else {
            int heroDamageInt = static_cast<int>(heroDamage);
            enemy->setHp(enemy->getHp() - heroDamageInt);
            std::cout << hero->getName() << " attacks! " << enemy->getName() << std::endl;
            std::cout << " Damage dealt: " << heroDamage << std::endl;
            std::cout << std::endl;
            std::cout << "Current battle status" << std::endl;

            battleStatus();
        }
        if(enemy->getHp() > 0) {

            float percentageDamageReducedHero = static_cast<float>(hero->getDef()) / 100;
            float enemyDamage = static_cast<float>(enemy->getAtk()) - percentageDamageReducedHero;

            int chance = rand() % 100; // Chose to use rand() due to simplicity rather than <random> library
            float accuracy = enemy->getAccuracy();
            int accuracyPercentage = static_cast<int>(accuracy * 100);

            if (enemyDamage < 0) {
                enemyDamage = 0;
                std::cout << enemy->getName() << " missed!" << std::endl;

                battleStatus();
            } if (enemyDamage == 0) {
                std::cout << enemy->getName() << " could not penetrate your defence!" << std::endl;

                battleStatus();
            } else {
                if (chance < accuracyPercentage) {
                    int enemyDamageInt = static_cast<int>(enemyDamage);
                    hero->setHp(hero->getHp() - enemyDamageInt);
                    std::cout << enemy->getName() << " attacks! " << hero->getName() << std::endl;
                    std::cout << " Damage dealt: " << enemyDamage << std::endl;
                    std::cout << std::endl;
                    std::cout << "Curent battle status" << std::endl;

                    battleStatus();

                } else {
                    std::cout << enemy->getName() << " missed!" << std::endl;
                    battleStatus();
                }
            }
        }
        if(isBattleOver()) {
            std::cout << " The battle is over!" << std::endl;
            if (enemy->getHp() == 0) {
                int pointsRewarded = static_cast<int>(enemy->getReward()); // Preguntar si es necesario hacer un cast
                std::cout << hero->getName() << " won the battle!" << std::endl;
                std::cout << "Points granted by defeating " << enemy->getName() << " are: " << pointsRewarded << " points!" << std::endl;
                hero->addUpgradePoints(pointsRewarded);
                upgradeStats();
            } else if (hero->getHp() == 0) {
                std::cout << enemy->getName() << " won the battle!" << std::endl;
                std::cout << "Game Over" << std::endl;
            }
            battleStatus();
        }
    }
}

bool CombatSystem::isBattleOver() const {
    return hero->getHp() <= 0 || enemy->getHp() <= 0;
}


void CombatSystem::upgradeStats() {

    while (hero->getUpgradePoints() > 0) {

        int points = hero->getUpgradePoints();

        std::cout << "UPGRADE SYSTEM" << std::endl;
        std::cout << "Points left: " << points << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cout << "1- Upgrade hit points" << std::endl;
        std::cout << "2- Upgrade defense" << std::endl;
        std::cout << "3- Upgrade attack" << std::endl;
        std::cout << "4- Exit" << std::endl;

        int option;
        std::cin >> option;

        switch (option) {
            case 1:
                hero->spendUpgradePointsHp(1);
                std::cout << "Congratulations, you have upgraded your hit points the new stats are: " << std::endl;
                battleStatus();
                break;
            case 2:
                hero->spendUpgradePointsDef(1);
                std::cout << "Congratulations, you have upgraded your defence the new stats are: " << std::endl;
                battleStatus();
                break;
            case 3:
                hero->spendUpgradePointsAtk(1);
                std::cout << "Congratulations, you have upgraded your attack the new stats are: " << std::endl;
                battleStatus();
                break;
            case 4:
                std::cout << "Goodbye!" << std::endl;
                return;
            default:
                std::cout << "Invalid option" << std::endl;
        }

    }
    std::cout << hero->getName() << " has no more points left to spend" << std::endl;
}

