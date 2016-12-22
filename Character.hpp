//
// Created by Liam on 11/3/2016.
//

#ifndef CS368FINALPROJECT_RPG_CHARACTER_HPP
#define CS368FINALPROJECT_RPG_CHARACTER_HPP

#include "Skill.hpp"
#include <vector>
#include <SFML/Graphics.hpp>


class Character {
protected:
    int maxHP;
    int currHP;
    int maxMP;
    int currMP;
    int str;
    int def;
    int magic;
    int spd;
    int luck;
    std::vector<Skill> skills;
    sf::Sprite sprite;



public:
    void useSkill(Skill skill);
    bool attack(Character* character);
};

#endif //CS368FINALPROJECT_RPG_CHARACTER_HPP
