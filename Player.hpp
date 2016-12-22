//
// Created by Liam on 11/3/2016.
//

#ifndef CS368FINALPROJECT_RPG_PLAYER_HPP
#define CS368FINALPROJECT_RPG_PLAYER_HPP

#include "Character.hpp"
#include "Item.hpp"
#include <SFML/Graphics.hpp>


class Player : public Character{
private:
    int exp;
    double money;
    int positionX;
    int positionY;
    int speed;
    std::vector<Item> inventory;
    size_t tilesMoved = 0;
    sf::Sprite sprite;


public:
    Player(sf::Texture &texture, int posX, int posY, int speed);
    void draw(sf::RenderWindow* rw);
    void useitem(Item item);
    void addExp(size_t xp);
    void changeMoney(int gold);
    void defend();
    bool flee();
    void setPositionX(int x);
    void setPositionY(int y);
    void setTilesMoved(size_t moved);
    size_t getTilesMoved();
    void setPosition();
    int getSpeed();
    void setHP(int health);
    int getHP();
    int getDef();
    void setDef(int defense);
};

#endif //CS368FINALPROJECT_RPG_PLAYER_HPP
