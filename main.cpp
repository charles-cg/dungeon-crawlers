#include "GameController.h"
#include <iostream>

int main() {
    std::srand(static_cast<unsigned int>(time(nullptr))); // Seeding the random number generator in main to prevent having the same value in the calling of the function turn() in CombatSystem.cpp
    GameController controller;

    while(true) {
        controller.handleHeroMovement();
    }

    return 0;
}