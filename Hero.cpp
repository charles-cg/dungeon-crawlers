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
    upgradeAtk(10);
    upgradePoints -= points;
}

void Hero::spendUpgradePointsDef(int points) {
    if (points <= 0 || upgradePoints < points) {
        std::cout << "Sorry, you do not have enough points" << std::endl;
        return;
    }
    upgradeDef(10);
    upgradePoints -= points;
}

void Hero::spendUpgradePointsHp(int points) {
    if (points <= 0 || upgradePoints < points) {
        std::cout << "Sorry, you do not have enough points" << std::endl;
        return;
    }
    upgradeHp(10);
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
    hp += amount;
    if (hp > maxHp) {
        hp = maxHp;
    }
}

void Hero::setStamina(int value) {
    stamina = value;
    if (stamina > maxStamina) {
        stamina = maxStamina;
    }
    if (stamina < 0) {
        stamina = 0;
    }

}

int Hero::getStamina() {
    return stamina;
}

int Hero::getMaxStamina() {
    return maxStamina;
}

void Hero::setMaxStamina(int maxStamina) {
    this->maxStamina = maxStamina;
}

void Hero::staminaConsumption(int staminaCost) {
    stamina -= staminaCost;
    if (stamina < 0) {
        stamina = 0;
    }
}

bool Hero::hasEnoughStamina(int staminaCost) const {
    return stamina >= staminaCost;
}

