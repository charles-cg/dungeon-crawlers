#ifndef MONSTER_H
#define MONSTER_H
#include <string>

class Monster {
private:
    unsigned int id;
    std::string name;

    int hp;
    int atk;
    int def;

    int spawnChance;
    int reward;
public:
    Monster();
    ~Monster();

    void setId(const unsigned int& id);
    void setName(const std::string& name);
    void setHp(const int& hp);
    void setAtk(const int& atk);
    void setDef(const int& def);
    void setSpawnChance(const int& spawnChance);
    void setReward(const int& reward);

    unsigned int getId();
    std::string getName();
    int getHp();
    int getAtk();
    int getDef();
    int getSpawnChance();
    int getReward();
};

#endif