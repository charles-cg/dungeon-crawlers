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
    Hero* hero = dungeon.getHero();

    if (dungeon.handleEncounter()) {
        handleCombat();
        
        // If hero survived, increment monsters defeated
        if (hero->getHp() > 0) {
            monstersDefeated++;
            std::cout << "Monsters defeated: " << monstersDefeated << std::endl;
        }
    } else {
            std::cout << "\nYou explore the room carefully... it is completely empty." << std::endl;
    }
    int option = 0;
    while (hero->getHp() > 0 && !dungeon.isRedDragonDefeated()) {
        // Handle movement
        std::cout << "\n--- Current Location ---" << std::endl;
        std::cout << "HP: " << hero->getHp() << "/" << hero->getMaxHp() 
                  << " | ATK: " << hero->getAtk() 
                  << " | DEF: " << hero->getDef() 
                  << " | Upgrade Points: " << hero->getUpgradePoints() << std::endl;

        std::cout << "What will you do now?" << std::endl;
        std::cout << "1) Move to another room" << std::endl;
        std::cout << "2) Try you knowledge by using the secret password" << std::endl;
        std::cout << "3) Wait here (I wouldn't know why, but ok man)" << std::endl;
        std::cout << "4) Surrender and leave the doungeon (I also wouldn't recomend it, but sure mate)" << std::endl;

        std::cin >> option;

        switch (option) {
            case 1:
                handleHeroMovement();

                // Check for encounter after movement
                if (dungeon.handleEncounter()) {
                    handleCombat();

                    // If hero survived, increment monsters defeated
                    if (hero->getHp() > 0) {
                        monstersDefeated++;
                        std::cout << "Monsters defeated: " << monstersDefeated << std::endl;
                    }
                } else {
                    std::cout << "\nYou explore the room carefully... it is completely empty." << std::endl;
                }
                break;
            case 2:
                showSecretPath();
                break;
            case 3: std::cout << "I still don't know why you chose to rest, but I admit it's necessary sometimes" << std::endl;
                break;
            case 4:
                std::cout << "So, you decide to surrender, I thought you could tackle the task" << std::endl;
                return false;
            default:
                std::cout << "Sorry man, that's not a valid option" << std::endl;
                break;
        }
    }

    // Final check after loop exits
    if (hero->getHp() <= 0) {
        std::cout << "\n***********************************" << std::endl;
        std::cout << "         GAME OVER" << std::endl;
        std::cout << "*************************************" << std::endl;
        std::cout << "You have been defeated..." << std::endl;
        std::cout << "Monsters defeated: " << monstersDefeated << std::endl;
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

void GameController::showSecretPath() {
    std::string password;
    std::cout << "Enter the secret password to reveal the secret path" << std::endl;
    std::cin >> password;

    if (password != secretPassword) {
        std::cout << "That's not the secret password, good luck finding the path!" << std::endl;
        return;
    } else {
        std::cout << "Correct! Now, the magic shall show you the most optimal path to yout destiny" << std::endl;
    }

    Hero* hero = dungeon.getHero();
    if (!hero) {
        std::cout << "There's no hero in the dungeon" << std::endl;
        return;
    }
    std::string currentRoomId = hero->getCurrentRoomId();
    Room<Monster> currentRoom(hero->getCurrentRoomId());

    dungeon.getBoard().dijkstra(currentRoom);
}

