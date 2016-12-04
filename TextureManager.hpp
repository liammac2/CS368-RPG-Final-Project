//
// Created by Liam on 11/4/2016.
//

#ifndef CS368FINALPROJECT_RPG_IMAGEMANAGER_HPP
#define CS368FINALPROJECT_RPG_IMAGEMANAGER_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class TextureManager {
private:
    std::vector<sf::Texture> textures;

public:
    TextureManager();
    ~TextureManager();
    void addTexture(sf::Texture& texture);
    sf::Texture& getTexture(int index);
};
#endif //CS368FINALPROJECT_RPG_IMAGEMANAGER_HPP
