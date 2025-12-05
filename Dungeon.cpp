#include "Dungeon.h"
#include <cstdlib>

Dungeon::~Dungeon() {
	delete hero;
	hero = nullptr;
}

int Dungeon::countLines(std::string filename) {
    std::ifstream file(filename);
    int lineCount = 0;
    std::string line;

    // check if the file has been opened
    if (!file.is_open()) {
        std::cerr << "There was an error opening the file: " << filename << std::endl;
        return -1;
    }

    // skip header
    if(!getline(file, line)) {
        std::cerr << "File does not have a header" << std::endl;
        file.close();
        return -1;
    }

    // Count lines
    while(getline(file, line)) {
        lineCount++;    
    }

    file.close();
    return(lineCount);
}

bool Dungeon::loadRoomsTXT(std::string filename) {
	std::ifstream file(filename);
	std::string line;
	unsigned int size = 0;

	if (!file.is_open()) {
		std::cout << "Unable to open file: " << filename << std::endl;
		return false;
	}
	if (!getline (file, line)) {
		std::cout << "Text file has no header" << std::endl;
		return false;
	}
	std::cout << "File Open" << std::endl;
	while (getline (file, line)) {
		Room<Monster> newRoom = Room<Monster>();
		std::stringstream ss(line);
		std::string cell;
		int field = 0, errors = 0;

		while (getline(ss, cell, ',')) {
			if (!cell.length())
				errors++;
			switch (field){
				case 0:
					newRoom.setId(cell);
					break;
				case 1:
					newRoom.setName(cell);
					break;
				case 2:
					newRoom.setEncounterChance(stof(cell));
					break;					
				case 3: {
                    int tempInt = stoi(cell); // Implicit conversion from int to boolean 
                    bool tempBool = tempInt; // any non-zero value will output true, 0 outputs false
					newRoom.setWasVisited(tempBool);
					break;
                }
                case 4: {
                    std::string monsterId = cell;
					newRoom.setCreature(monsterCodex.searchMonster(monsterId));
					break;
                }	                   
				default:
					errors++;
					break;
				}
			field++;
			}
		if (errors || field != ROOM_NUMBER_ATTRIBUTES){
			std::cout << "Error on line: " << line << std::endl;
			file.close();
			return false;
		}
		if(size < totalRooms) {
			board.addVertex(newRoom);
			size++;
		}
		else {
			std::cout << "Error, the capacity of the board is too small" << std::endl;
			file.close();
			return false;
		}
	}
	file.close();
	return true;
}

bool Dungeon::loadRoomData() {
    totalRooms = countLines(ROOMS_TXT);

    if (totalRooms == -1) {
        std::cerr << "Unable to load data set from" << ROOMS_TXT << std::endl;
        return false;
    }

    std::cout << "The file \"" << ROOMS_TXT << "\" has: " << totalRooms << " rooms\n";

    if (!loadRoomsTXT(ROOMS_TXT)) {
        std::cerr << "Error loading data set from " << ROOMS_TXT << std::endl;
        return false;
    }
    return true;
}

bool Dungeon::addRoomPath(std::string& roomFromId, std::string& roomToId, int weight, bool directed) {
	Room<Monster> roomFrom, roomTo;

	roomFrom.setId(roomFromId);
	roomTo.setId(roomToId);

	return board.addEdge(roomFrom, roomTo, weight, directed);
}

bool Dungeon::loadPathsTXT(std::string filename) {
	std::ifstream file(filename);
	std::string line;
	unsigned int size = 0;

	if (!file.is_open()) {
		std::cout << "Unable to open file: " << filename << std::endl;
		return false;
	}
	if (!getline (file, line)) {
		std::cout << "Text file has no header" << std::endl;
		return false;
	}
	std::cout << "File Open" << std::endl;
	while (getline (file, line)) {
		std::string roomFromId, roomToId = "";
		int weight = 1;
		bool directed = false;
		std::stringstream ss(line);
		std::string cell;
		int field = 0, errors = 0;

		while (getline(ss, cell, ',')) {
			if (!cell.length())
				errors++;
			switch (field){
				case 0:
					roomFromId = cell;
					break;
				case 1:
					roomToId = cell;
					break;
				case 2:
					weight = stoi(cell);
					break; 
				case 3: {
					int tempInt = stoi(cell); // Implicit conversion from int to boolean 
                    bool tempBool = tempInt; // any non-zero value will output true, 0 outputs false
					directed = tempBool;
					break;
				}           
				default:
					errors++;
					break;
				}
			field++;
			}
		if (errors || field != ADD_PATH_NUMBER_ARGUMENTS){
			std::cout << "Error on line: " << line << std::endl;
			file.close();
			return false;
		}
		if(size < totalPaths) {
			addRoomPath(roomFromId, roomToId, weight, directed);
			size++;
		}
		else {
			std::cout << "Error adding edges to board" << std::endl;
			file.close();
			return false;
		}
	}
	file.close();
	return true;
}

bool Dungeon::loadPathData() {
    totalPaths = countLines(PATHS_TXT);

    if (totalPaths == -1) {
        std::cerr << "Unable to load data set from" << PATHS_TXT << std::endl;
        return false;
    }

    std::cout << "The file \"" << PATHS_TXT << "\" has: " << totalPaths << " paths\n";

    if (!loadPathsTXT(PATHS_TXT)) {
        std::cerr << "Error loading data set from " << PATHS_TXT << std::endl;
        return false;
    }
    return true;
}

void Dungeon::printBoard() const {
	board.print();
}

void Dungeon::setStartingRoom() {
	Room<Monster> tempRoom("R1");
	board.findVertexNode(tempRoom)->getData().getData().setHero(hero);
	hero->setCurrentRoomId("R1");
}

void Dungeon::showNeghboringRooms() const {
	std::cout << "Signs, each located at the entrance of a path appear before you, each having the following text: " << std::endl;
	Room<Monster> tempRoom(hero->getCurrentRoomId());
	board.findVertexNode(tempRoom)->getData().getAdj().print();
}

bool Dungeon::moveHero(const std::string& roomId) {

	Room<Monster> tempRoom(roomId);
	Room<Monster> currentRoom(hero->getCurrentRoomId());

	Edge<Room<Monster>> searchEdge(tempRoom, 0);

	if (!board.findVertexNode(currentRoom)->getData().getAdj().search(searchEdge)) {
		std::cout << "Where did you even read that Magic ID, try again!" << std::endl;
		return false;
	}

	int staminaCost = getCost(currentRoom.getId(), roomId);
	if (staminaCost < 0) {
		std::cout << "There is no magic path to the room " << roomId << std::endl;
		return false;
	}
	if (!hero->hasEnoughStamina(staminaCost)) {
		std::cout << hero->getName() << " has no enought stamina to move there" << std::endl;
		std::cout << "Stamina needed: " << staminaCost << std::endl;
		std::cout << "Current stamina: " << hero->getStamina() << std::endl;
		return false;
	}

	hero->staminaConsumption(staminaCost);
	std::cout << hero->getName() << " moved to: " << roomId << std::endl;

	std::cout << "The remaining stamina is: " << hero->getStamina() << std::endl;

	board.findVertexNode(currentRoom)->getData().getData().setWasVisited(true);
	board.findVertexNode(currentRoom)->getData().getData().setHero(nullptr);
	board.findVertexNode(tempRoom)->getData().getData().setHero(hero);
	hero->setCurrentRoomId(roomId);
	return true;
}

Monster* Dungeon::getCurrentMonster() {
	Room<Monster> currentRoom(hero->getCurrentRoomId());

	return board.findVertexNode(currentRoom)->getData().getData().getCreaturePtr();
}

bool Dungeon::shouldTriggerEncounter() {
	Room<Monster> currentRoom(hero->getCurrentRoomId());
	float encounterChance = board.findVertexNode(currentRoom)->getData().getData().getEncounterChance();
	
	float randomValue = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	
	return randomValue < encounterChance;
}

bool Dungeon::handleEncounter() {
	Room<Monster> currentRoom(hero->getCurrentRoomId());

	bool encounterFlag = shouldTriggerEncounter();

	bool defeatedFlag = board.findVertexNode(currentRoom)->getData().getData().getWasMonsterDefeated();

	if (defeatedFlag == false && encounterFlag == true) {
		return true;
	}

	return false;
}

Hero* Dungeon::getHero() {
	return hero;
}

void Dungeon::setCurrentRoomMonsterDefeated() {
	Room<Monster> currentRoom(hero->getCurrentRoomId());
	board.findVertexNode(currentRoom)->getData().getData().setWasMonsterDefeated(true);
}

void Dungeon::setHero(const std::string& name) {
	hero = new Hero("H1", name, 100, 3, 10);
	hero->setMaxStamina(100);
	hero->setStamina(100);
}

int Dungeon::getCost(const std::string& fromId, const std::string& toId) {
	Room<Monster> fromRoom(fromId);

	ListNode<Vertex<Room<Monster>>>* fromNode = board.findVertexNode(fromRoom);
	if (!fromNode) {
		return -1; // The vertex does not exist
	}
	LinkedList<Edge<Room<Monster>>> adjList = fromNode->getData().getAdj();
	ListNode<Edge<Room<Monster>>>* edgeNode = adjList.getHead();

	while (edgeNode) {
		Edge<Room<Monster>>& edge = edgeNode->getData();
		Room<Monster> destRoom = edge.getDestination();

		if (destRoom.getId() == toId) {
			return edge.getWeight();
		}
		edgeNode = edgeNode->getNext();
	}
	return -1;
}

bool Dungeon::isRedDragonDefeated() {
	Room<Monster> dragonRoom("R10");
	return board.findVertexNode(dragonRoom)->getData().getData().getWasMonsterDefeated();
}

Graph<Room<Monster>>& Dungeon::getBoard() {
	return board;
}

const Graph<Room<Monster>>& Dungeon::getBoard() const {
	return board;
}