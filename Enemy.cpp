//
// Created by Liam on 11/3/2016.
//

#include "Enemy.hpp"

Enemy::Enemy(sf::Texture &texture) {
    sprite.setTexture(texture);
    sprite.setScale(.8, .8);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    maxHP = 100;
    currHP = maxHP;
    maxMP = 30;
    currMP = maxMP;
    str = 25;
    def = 10;
    magic = 20;
    spd = 20;
    luck = 15;
}

void Enemy::draw(sf::RenderWindow *rw) {
    sprite.setPosition(rw->getSize().x / 2, rw->getSize().y / 2);
    rw->draw(sprite);

}

void Enemy::setHP(int health) {
    currHP = health;
}

int Enemy::getHP() {
    return currHP;
}

int Enemy::getDef() {
    return def;
}

void Enemy::reset() {
    currHP = maxHP;
    currMP = maxMP;
}

