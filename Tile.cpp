//
// Created by Liam on 11/4/2016.
//

#include <iostream>
#include "Tile.hpp"

Tile::Tile(sf::Texture &texture) {
    baseSprite.setTexture(texture);
}

Tile::~Tile() {

}

void Tile::draw(int x, int y, sf::RenderWindow *rw) {
    baseSprite.setPosition(x, y);
    rw->draw(baseSprite);
}

void Tile::setSpriteScale(float x, float y) {
    baseSprite.setScale(x, y);
}
