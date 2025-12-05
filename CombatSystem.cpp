//
// Created by MATEO HERNANDEZ on 16/11/25.
//

#include "CombatSystem.h"
#include <iostream>
#include <cstdlib>

void CombatSystem::battleStatus() const {

        std::cout << "Battle Status" << std::endl; //The menu is displayed to show the current stats of both hero and monster
        // Hero stats
        std::cout << "Hero: " << hero->getName() << " Hit Points: " << hero->getHp() << " Defence: " << hero->getDef() << std::endl;
        // Current monster stats
        std::cout << "Enemy: " << enemy->getName() << " Hit Points: " << enemy->getHp() << " Defence: " << enemy->getDef() << std::endl;
        std::cout << std::endl;
}

void CombatSystem::battleFlow() {

    while (!isBattleOver()) {
        battleStatus();

        heroTurn();
        if (isBattleOver()) {
            break; // Checar al rato como corregir esto
        }

        enemyTurn();
        if (isBattleOver()) {
            break; //Checar al rato como corregir esto
        }
    }

    if(isBattleOver()) { // This condition only enters once the hero or the enemy is defeated

        std::cout << " The battle is over!" << std::endl;

        if (enemy->getHp() == 0) { // The first case covers the situation where the enemy is defeated
            int pointsRewarded = static_cast<int>(enemy->getReward()); //The number of points depends on the type of monster the hero defeats
            std::cout << hero->getName() << " won the battle!" << std::endl;
            std::cout << "Points granted by defeating " << enemy->getName() << " are: " << pointsRewarded << " points!" << std::endl;
            hero->addUpgradePoints(pointsRewarded); //Method defined to add the upgrade points
            upgradeStats(); // calls the method to update points

        } else if (hero->getHp() == 0) { // Case where the enemy defeats the hero
            std::cout << enemy->getName() << " won the battle!" << std::endl;
            std::cout << "Game Over" << std::endl;
        }
        //Final battle status
        battleStatus();
    }
}

bool CombatSystem::isBattleOver() const {
    return hero->getHp() <= 0 || enemy->getHp() <= 0; //This function returns "true" whether the hero or the enemy has 0 or less of hit points
}

void CombatSystem::upgradeStats() { // The function implements a menu in order to upgrade the stats of the hero

    int option = 0;
    while (option != 4 && hero->getUpgradePoints() <= 0) { // The while maintains the loop until the player enters "4"to exit the menu

        int points = hero->getUpgradePoints(); //We assign the upgrade points of the hero to the variable points to use it in the system

        std::cout << "UPGRADE SYSTEM" << std::endl;
        std::cout << "Points left: " << points << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cout << "1- Upgrade hit points" << std::endl;
        std::cout << "2- Upgrade defense" << std::endl;
        std::cout << "3- Upgrade attack" << std::endl;
        std::cout << "4- Exit" << std::endl;

        std::cin >> option; // Here the player can change the option and exit the loop

        switch (option) {
            case 1:
                if (points > 0) {
                    hero->spendUpgradePointsHp(3);
                    std::cout << "Congratulations, you have upgraded your hit points the new stats are: " << std::endl;
                    battleStatus();
                } else {
                    std::cout << "You have no points left" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 2:
                if (points > 0) {
                    hero->spendUpgradePointsDef(2);
                    std::cout << "Congratulations, you have upgraded your defence the new stats are: " << std::endl;
                    battleStatus();
                } else {
                    std::cout << "You have no points left" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 3:
                if (points > 0) {
                    hero->spendUpgradePointsAtk(2);
                    std::cout << "Congratulations, you have upgraded your attack the new stats are: " << std::endl;
                    battleStatus();
                } else {
                    std::cout << "You have no points left" << std::endl;
                }
                std::cout << std::endl;
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

void CombatSystem::heroTurn() {
    //From the txt, the percentage of reduction from the defence of the monster is calculated.
    float percentageDamageReducedEnemy = static_cast<float>(enemy->getDef()) / 100; // The static cast is made because the defence is an integer in the txt.
    float heroDamage = static_cast<float>(hero->getAtk()) - percentageDamageReducedEnemy; // The damage the hero is going to make is calculated

    if (heroDamage < 0) { //First case, the enemy damage is less than cero.
        std::cout << hero->getName() << " missed!" << std::endl; //We consider this case as the hero missed the attack
        battleStatus(); // The stats are shown
        return;
    }
    if (heroDamage == 0) {
        // Second case, the damage is equal to cero, this is considered that the damage from the hero could not penetrate the defence of the monster
        std::cout << hero->getName() << " could not penetrate the defence of " << enemy->getName() << std::endl;
        battleStatus(); // We again show the stats
        return;
    }
    // If any of the previous cases are fulfilled, the battle "finally" starts
    int heroDamageInt = static_cast<int>(heroDamage); //Here we retransform the hero damage into an int
    enemy->setHp(enemy->getHp() - heroDamageInt); // The monster "receives" the damage

    if (enemy->getHp < 0) {
        enemy->setHp(0); // If the Hp results in a negative number, we set is as 0 for ti not to be weird
    }

    //Messages to understand the flow of the battle
    std::cout << hero->getName() << " attacks! " << enemy->getName() << std::endl;
    std::cout << " Damage dealt: " << heroDamage << std::endl; // Shows the damage made to the monster
    std::cout << std::endl;
    std::cout << "Current battle status" << std::endl;

    battleStatus(); //Shows the newly altered stats
}


void CombatSystem::enemyTurn() {

    float percentageDamageReducedHero = static_cast<float>(hero->getDef()) / 100; //The same calculations are applied to the enemy
    float enemyDamage = static_cast<float>(enemy->getAtk()) - percentageDamageReducedHero;

    //In this case, even thought the rand() has a predictable generation of numbers, for the purpose of this project, it's not relevant
    int chance = rand() % 100; // Chose to use rand() due to simplicity rather than <random> library, the seed si in the main
    float accuracy = enemy->getAccuracy();

    int accuracyPercentage = static_cast<int>(accuracy * 100);
    //The same cases from the hero apply for the monster
    if (enemyDamage < 0) { //The monster missed
        std::cout << enemy->getName() << " missed!" << std::endl;

        battleStatus(); // We show the stats
        return;
    }
    if (enemyDamage == 0) {
        // The monster's damage could not penetrate the defence of the hero
        std::cout << enemy->getName() << " could not penetrate your defence!" << std::endl;

        battleStatus(); // We show the stats
        return;
    }

    // In the case of the monsters, they can also miss because of the accuracy percentage that si calculated with the rand()
    if (chance < accuracyPercentage) { // if the variable chance defined previously is less than the accuracy of the monster
        int enemyDamageInt = static_cast<int>(enemyDamage);
        hero->setHp(hero->getHp() - enemyDamageInt); // We define the new hp of the hero

        if (hero->getHp() < 0) {
            hero->setHp(0); // If the Hp results in a negative number, we set is as 0 for ti not to be weird
        }

        std::cout << enemy->getName() << " attacks! " << hero->getName() << std::endl;
        std::cout << " Damage dealt: " << enemyDamage << std::endl;
        std::cout << std::endl;
        std::cout << "Curent battle status" << std::endl;

        battleStatus(); // We show the new stats

    } else {
        std::cout << enemy->getName() << " missed!" << std::endl;
        battleStatus();
    }
}