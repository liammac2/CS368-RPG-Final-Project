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
