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

void Hero::spendUpgradePoints() {
    if (upgradePoints > 0) {
        upgradePoints--;
        std::cout << "You spent a point of upgrade!" << std::endl;
    }
}