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
    Square<T>* prev;
    Square<T>* next;
public:
    Square();
    ~Square();

    void setId(const unsigned int& id);
    void setName (const std::string& name);
    void setEncounterChance(const unsigned int& encounterChance);
    void setWasVisited(bool& wasVisited);
    void setPrev(Square<T>* prev);
    void setNext(Square<T>* next);

    unsigned int getId();
    std::string getName();
    unsigned int getEncounterChance();
    bool getWasVisited();
    Square<T>* getPrev();
    Square<T>* getNext();
};

#include "Square.tpp"

#endif