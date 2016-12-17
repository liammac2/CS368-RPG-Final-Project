//
// Created by Liam on 11/4/2016.
//

#include <iostream>
#include "TextureManager.hpp"

TextureManager::TextureManager() {

}

TextureManager::~TextureManager() {

}

void TextureManager::addTexture(sf::Texture texture) {
    textures.push_back(texture);
}

sf::Texture &TextureManager::getTexture(int index) {
    return textures[index];
}
