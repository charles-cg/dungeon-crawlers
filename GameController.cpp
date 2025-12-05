#include "GameController.h"
#include "CombatSystem.h"

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

void GameController::handleCombat() {
    Hero* hero = dungeon.getHero();
    Monster* monster = dungeon.getCurrentMonster();
    
    std::cout << "\n<<<< COMBAT INITIATED >>>>" << std::endl;
    std::cout << "Prepare thyself, a wild " << monster->getName() << " has appeared!" << std::endl;
    
    CombatSystem combat(hero, monster);
    combat.battleFlow();
    
    if (hero->getHp() <= 0) {
        std::cout << "\nYour journey ends here..." << std::endl;
        return;
    }
    
    dungeon.setCurrentRoomMonsterDefeated();
    
    std::cout << "\nYou have defeated the " << monster->getName() << "!" << std::endl;
}

bool GameController::run() {
    std::cout << "<<<<<< DUNGEON CRAWLERS >>>>>>" << std::endl;
    std::cout << "(  )   /\\   _                 (     \n";
    std::cout << "  \\ |  (  \\ ( \\.(               )                      _____\n";
    std::cout << "\\  \\ \\  `  `   ) \\             (  ___                 / _   \\\n";
    std::cout << "(_`    \\+   . x  ( .\\            \\/   \\____-----------/ (o)   \\_\n";
    std::cout << "- .-               \\+  ;          (  O                           \\____\n";
    std::cout << "                         )        \\_____________  `              \\  /\n";
    std::cout << "(__                +- .( -'.- <. - _  VVVVVVV VV V\\                 \\/\n";
    std::cout << "(_____            ._._: <_ - <- _  (--  _AAAAAAA__A_/                  |\n";
    std::cout << "  .    /./.+-  . .- /  +--  - .     \\______________//_              \\_______\n";
    std::cout << "  (__ ' /x  / x _/ (                                  \\___'          \\     /\n";
    std::cout << ", x / ( '  . / .  /                                      |           \\   /\n";
    std::cout << "   /  /  _/ /    +                                      /              \\/\n";
    std::cout << "  '  (__/                                             /                  \\\n";
    std::cout << std::endl;

    std::cout << "Welcome adventurer, how do people call you?" << std::endl;
    std::string name = "";
    std::cout << "Type your adventurer name: ";
    std::cin >> name;

    dungeon.setHero(name);
    dungeon.setStartingRoom();  // Place the hero in the starting room


    std::cout << "lovely, " << name << std::endl;
    std::cout << "There is a comission to tackle a dungeon near the outskirts of the royal capital, if you slay the red dragon at the end of the dungeon, the king will reward you with immeasureable riches and fame, I am quite sure you will be up to the challenge." << std::endl;

    std::cout << "You travel to a mountain near the royal capital and encounter a huge entrance, this must be the dungeon" << std::endl;

    std::cout << "You enter the dungeon, ready to explore and slay the dragon!!!" << std::endl;

    int monstersDefeated = 0;
    const int TOTAL_MONSTERS = 10;
    Hero* hero = dungeon.getHero();

    if (dungeon.handleEncounter()) {
        handleCombat();
        
        // If hero survived, increment monsters defeated
        if (hero->getHp() > 0) {
            monstersDefeated++;
            std::cout << "Monsters defeated: " << monstersDefeated << "/" << TOTAL_MONSTERS << std::endl;
        }
    } else {
            std::cout << "\nYou explore the room carefully... it is completely empty." << std::endl;
    }

    while (hero->getHp() > 0 && monstersDefeated < TOTAL_MONSTERS) {
        // Handle movement
        std::cout << "\n--- Current Location ---" << std::endl;
        std::cout << "HP: " << hero->getHp() << "/" << hero->getMaxHp() 
                  << " | ATK: " << hero->getAtk() 
                  << " | DEF: " << hero->getDef() 
                  << " | Upgrade Points: " << hero->getUpgradePoints() << std::endl;
        
        handleHeroMovement();
        
        // Check for encounter after movement
        if (dungeon.handleEncounter()) {
            handleCombat();
            
            // If hero survived, increment monsters defeated
            if (hero->getHp() > 0) {
                monstersDefeated++;
                std::cout << "Monsters defeated: " << monstersDefeated << "/" << TOTAL_MONSTERS << std::endl;
            }
        } else {
            std::cout << "\nYou explore the room carefully... it is completely empty." << std::endl;
        }
    }
    
    // Final check after loop exits
    if (hero->getHp() <= 0) {
        std::cout << "\n***********************************" << std::endl;
        std::cout << "         GAME OVER" << std::endl;
        std::cout << "*************************************" << std::endl;
        std::cout << "You have been defeated..." << std::endl;
        std::cout << "Monsters defeated: " << monstersDefeated << "/" << TOTAL_MONSTERS << std::endl;
        return false;
    } else {
        std::cout << "\n*********************************" << std::endl;
        std::cout << "         VICTORY!" << std::endl;
        std::cout << "***********************************" << std::endl;
        std::cout << "You have slain the Red Dragon and cleared the dungeon!" << std::endl;
        std::cout << "The king rewards you with immeasurable riches and fame!" << std::endl;
        std::cout << "Your name will be remembered in songs for generations!" << std::endl;
        return true;
    }
}