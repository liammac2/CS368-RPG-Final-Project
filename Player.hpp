//
// Created by Liam on 11/3/2016.
//

#ifndef CS368FINALPROJECT_RPG_PLAYER_HPP
#define CS368FINALPROJECT_RPG_PLAYER_HPP

#include "Character.hpp"
#include "Item.hpp"



class Player : public Character{
private:
    int exp;
    double money;
    int positionX;
    int positionY;
    std::vector<Item> inventory;

public:
    void useitem(Item item);
};

#endif //CS368FINALPROJECT_RPG_PLAYER_HPP
