//
// Created by Liam on 11/3/2016.
//

#include "Player.hpp"

Player::Player(sf::Texture &texture, int posY, int posX, int spd) {
    sprite.setTexture(texture);
    positionX = posX;
    positionY = posY;
    sprite.setPosition(positionX, positionY);
    sprite.setScale(.2, .2);
    speed = spd;
    maxHP = 120;
    currHP = maxHP;
    maxMP = 30;
    currMP = maxMP;
    str = 30;
    def = 10;
    magic = 20;
    Player::spd = 20;
    luck = 15;
}

void Player::draw(sf::RenderWindow *rw) {
    sprite.setPosition(positionX, positionY);
    rw->draw(sprite);
}

void Player::setTilesMoved(size_t moved) {
    tilesMoved = moved;
}

size_t Player::getTilesMoved() {
    return tilesMoved;
}

void Player::setPositionX(int x) {
    positionX += x;
}

void Player::setPositionY(int y) {
    positionY += y;
}

void Player::setPosition() {
    sprite.setPosition(positionX, positionY);
}

int Player::getSpeed() {
    return speed;
}

void Player::defend() {
    def *= 2;
}

bool Player::flee() {
    return true;
}

void Player::setHP(int health) {
    currHP = health;
}

int Player::getHP() {
    return currHP;
}

int Player::getDef() {
    return def;
}

void Player::setDef(int defense) {
    def = defense;
}

