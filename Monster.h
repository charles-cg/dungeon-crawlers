#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include "Entity.h"

#define MONSTER_NUMBER_ATTRIBUTES 7

class Monster : public Entity{
private:
    float accuracy;
    float reward;
public:
    Monster();
    ~Monster();

    void setAccuracy(const float& accuracy);
    void setReward(const float& reward);

    float getAccuracy();
    float getReward();

};

#endif