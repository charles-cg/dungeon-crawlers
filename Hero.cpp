#include "Hero.h"

#include <iostream>
#include <ostream>

Hero::~Hero() {

}

void Hero::setCurrentRoomId(const std::string& id) {
    currentRoomId = id;
}

std::string Hero::getCurrentRoomId() const{
    return currentRoomId;
}

int Hero::getUpgradePoints() const {
    return upgradePoints;
}

void Hero::addUpgradePoints(int points) {
    upgradePoints += points;
}

void Hero::spendUpgradePointsAtk(int points) {
    if (points <= 0 || upgradePoints < points) {
        std::cout << "Sorry, you do not have enough points" << std::endl;
        return;
    }
    upgradeAtk(points);
    upgradePoints -= points;
}

void Hero::spendUpgradePointsDef(int points) {
    if (points <= 0 || upgradePoints < points) {
        std::cout << "Sorry, you do not have enough points" << std::endl;
        return;
    }
    upgradeDef(points);
    upgradePoints -= points;
}

void Hero::spendUpgradePointsHp(int points) {
    if (points <= 0 || upgradePoints < points) {
        std::cout << "Sorry, you do not have enough points" << std::endl;
        return;
    }
    upgradeHp(points);
    upgradePoints -= points;
}

void Hero::upgradeAtk(int amount) {
    atk += amount;
}

void Hero::upgradeDef(int amount) {
    def += amount;
}

void Hero::upgradeHp(int amount) {
    maxHp += amount;
}