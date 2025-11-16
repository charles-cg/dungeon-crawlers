#include "Dungeon.h"

Dungeon::~Dungeon() {

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