#include "Monster.h"

Monster::Monster() {
    accuracy = 0;
    reward = 0;
}

Monster::~Monster() {
    
}

// setter methods
void Monster::setAccuracy(const float& accuracy) {
    this->accuracy = accuracy;
}


void Monster::setReward(const float& reward) {
    this->reward = reward;
}

// Getter methods
float Monster::getAccuracy() {
    return accuracy;
}
float Monster::getReward() {
    return reward;
}