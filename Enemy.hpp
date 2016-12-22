//
// Created by Liam on 11/3/2016.
//

#ifndef CS368FINALPROJECT_RPG_ENEMY_HPP
#define CS368FINALPROJECT_RPG_ENEMY_HPP

#include "Character.hpp"
#include "Skill.hpp"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>


class Enemy : public Character{
private:
    sf::Sprite sprite;


public:
    Enemy(sf::Texture &texture);
    void draw(sf::RenderWindow* rw);
    void setHP(int health);
    int getHP();
    int getDef();
    void reset();

};

#endif //CS368FINALPROJECT_RPG_ENEMY_HPP
