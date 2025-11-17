#include "GameController.h"
#include <iostream>

int main() {
    GameController controller;

    while(true) {
        controller.handleHeroMovement();
    }

    return 0;
}