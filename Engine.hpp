//
// Created by Liam on 11/4/2016.
//

#ifndef CS368FINALPROJECT_RPG_ENGINE_HPP
#define CS368FINALPROJECT_RPG_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include "Tile.hpp"

class Engine {
private:
    TextureManager* textureManager;
    sf::RenderWindow *window;
    bool initialize();
    void loop();
    void renderFrame();
    void processInput();
    void update();
    void loadTextures();
    Tile* tile;

public:
    Engine();
    ~Engine();
    void go();
};

#endif //CS368FINALPROJECT_RPG_ENGINE_HPP
