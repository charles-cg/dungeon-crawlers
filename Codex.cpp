#pragma once
#include <iostream>
#include "Codex.h"
#include <fstream>
#include <sstream>


bool Codex::loadMonsterTXT(std::string filename) {
	std::ifstream file(filename);
	std::string line;
	unsigned int size = 0;

	if (!file.is_open()) {
		std::cout << "File could not be opened" << filename << std::endl;
		return false;
	}
	if (!getline (file, line)) {
		std::cout << "File does not have a header" << std::endl;
		return false;
	}
	std::cout << "File has been opened"<< std::endl;
	while (getline (file, line)) {
		Monster newMonster = Monster();
		std::stringstream ss(line);
		std::string cell;
		int field = 0, errors = 0;

		while (getline(ss, cell, ',')) {
			if (!cell.length())
				errors++;
			switch (field){
				case 0:
					newMonster.setId(stoi(cell));
					break;
				case 1:
					newMonster.setName(cell);
					break;
				case 2:
					newMonster.setHp(stoi(cell));
					break;					
				case 3:
					newMonster.setAtk(stoi(cell));
					break;
                case 4:
                    newMonster.setDef(stoi(cell));
                    break;
                case 5:
                    newMonster.setSpawnChance(stoi(cell));
                    break;
                case 6:
                    newMonster.setReward(stoi(cell));
                    break;
				default:
					errors++;
					break;
				}
			field++;
			}
		if (errors || field != MONSTER_NUMBER_STATS){
			std::cout << "Error on line: " << line << std::endl;
			file.close();
			return false;
		}
		if(size < totalMonsters) {
			codexTree.insert(newMonster);
			size++;
		}
		else {
			std::cout << "Error inserting element on tree" << std::endl;
			file.close();
			return false;
		}
	}
	file.close();
	return true;
}