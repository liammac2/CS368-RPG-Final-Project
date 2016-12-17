//
// Created by Liam on 11/4/2016.
//

#ifndef CS368FINALPROJECT_RPG_TILE_HPP
#define CS368FINALPROJECT_RPG_TILE_HPP

#include <SFML/Graphics.hpp>

class Tile {
private:
    sf::Sprite baseSprite;

public:
    Tile(sf::Texture& texture);
    ~Tile();
    void draw(int x, int y, sf::RenderWindow *rw);
    void setSpriteScale(float x, float y);
};
#endif //CS368FINALPROJECT_RPG_TILE_HPP
