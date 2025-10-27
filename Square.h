#ifndef SQUARE_H
#define SQUARE_H
#include <string>

template <typename T>
class Square {
private:
    unsigned int id;
    std::string name;
    unsigned int encounterChance; // chance ranges from 0 - 1
    bool wasVisited; // flag indicating if a square has been visited
};

#endif