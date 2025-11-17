#include "Hero.h"

Hero::~Hero() {

}

void Hero::setCurrentRoomId(const std::string& id) {
    currentRoomId = id;
}

std::string Hero::getCurrentRoomId() const{
    return currentRoomId;
}