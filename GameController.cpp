#include "GameController.h"

void GameController::handleHeroMovement() {
    dungeon.showNeghboringRooms();
    std::string roomIdInput = "";
    std::cout << "Select the room you want to travel to by inputting its magic ID: "; 
    std::cin >> roomIdInput;
    while (!dungeon.moveHero(roomIdInput)) {
        std::cout << "Select the room you want to travel to by inputting its magic ID: "; 
        std::cin >> roomIdInput;
    }
}