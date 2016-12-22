//
// Created by Liam on 11/3/2016.
//

#include <sstream>
#include "Character.hpp"

bool Character::attack(Character *character) {
    int damage = str - character->def;
    character->currHP -= (damage);
    return character->currHP <= 0;
}
