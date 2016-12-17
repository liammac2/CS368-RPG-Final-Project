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
    sf::Sprite sprite;
    size_t tilesMoved;

public:
    Player(sf::Texture &texture, int posX, int posY, int speed);
    void draw(sf::RenderWindow* rw);
    void useitem(Item item);
    void addExp(size_t xp);
    void changeMoney(int gold);
    void setPositionX(int x);
    void setPositionY(int y);
    void setTilesMoved(size_t moved);
    size_t getTilesMoved();
    void setPosition();
    int getSpeed();
};

#endif //CS368FINALPROJECT_RPG_PLAYER_HPP
