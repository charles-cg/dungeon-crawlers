#include "GameController.h"
#include <iostream>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(time(nullptr))); // Seed RNG
    GameController controller;

    bool flag = controller.run();

    return 0;
}