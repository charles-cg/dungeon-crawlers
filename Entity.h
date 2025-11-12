#ifndef ENTITY_H
#define ENTITY_H
#include <string>

class Entity {
protected:
    std::string id;
    std::string name;

    int hp;
    int atk;
    int def;
public:
    Entity();
    ~Entity();

    void setId(const std::string& id);
    void setName(const std::string& name);
    void setHp(const int& hp);
    void setAtk(const int& atk);
    void setDef(const int& def);

    std::string getId();
    std::string getName();
    int getHp();
    int getAtk();
    int getDef();
};

#endif