#ifndef MONSTER_H
#define MONSTER_H
#include <string>

#define MONSTER_NUMBER_ATTRIBUTES 7

class Monster {
private:
    std::string id;
    std::string name;

    int hp;
    int atk;
    int def;

    float accuracy;
    float reward;
public:
    Monster();
    ~Monster();

    void setId(const std::string& id);
    void setName(const std::string& name);
    void setHp(const int& hp);
    void setAtk(const int& atk);
    void setDef(const int& def);
    void setAccuracy(const float& accuracy);
    void setReward(const float& reward);

    std::string getId();
    std::string getName();
    int getHp();
    int getAtk();
    int getDef();
    float getAccuracy();
    float getReward();
};

#endif