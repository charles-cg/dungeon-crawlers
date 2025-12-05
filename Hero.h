#ifndef HERO_H
#define HERO_H
#include "Entity.h"

class Hero : public Entity {
private:
    std::string currentRoomId;
    int upgradePoints; // Used in the upgrade system
    int stamina;
    int maxStamina;
public:
    Hero(std::string id, std::string name, int hp, int atk, int def) : currentRoomId(""),  Entity(id, name, hp, atk, def), upgradePoints(0) {}
    ~Hero();

    void setCurrentRoomId(const std::string& id);

    std::string getCurrentRoomId() const;

    int getUpgradePoints() const;

    void addUpgradePoints(int points);

    void spendUpgradePointsAtk(int points);
    void spendUpgradePointsDef(int points);
    void spendUpgradePointsHp(int points);

    void upgradeAtk(int amount);
    void upgradeDef(int amount);
    void upgradeHp(int amount);

    void setStamina(int value);
    int getStamina();
    void setMaxStamina(int maxStamina);
    int getMaxStamina();
    void staminaConsumption(int staminaCost);
    bool hasEnoughStamina( int staminaCost) const;
};

#endif