#include "GameController.h"
#include <iostream>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(time(nullptr))); // Seeding the random number generator in the main to prevent having the same value in the calling of the function turn() in CombatSystem.cpp
    GameController controller;

    bool flag = controller.run();

    return 0;
}