#ifndef ENTITY_H
#define ENTITY_H
#include <string>

class Entity {
private:
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

        //operator overloading in order to order monsters based on ID on the binary tree of the codex
    bool operator<(const Entity& otherEntity) const {
        return this->id < otherEntity.id;
    }

    bool operator>(const Entity& otherEntity) const {
        return this->id > otherEntity.id;
    }

    friend std::ostream& operator<<(std::ostream& os, const Entity& entity) {
        os << entity.name;
        return os;
    }
};

#endif