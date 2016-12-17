//
// Created by Liam on 11/4/2016.
//

#ifndef CS368FINALPROJECT_RPG_ENGINE_HPP
#define CS368FINALPROJECT_RPG_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include "Tile.hpp"
#include "Player.hpp"

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
    std::vector<std::vector<Tile*>> tiles;
    Player* player;
    int tilesize = 40;
    bool battleProcessing = false;
    void processBattle(Player &player);


public:
    Engine();
    ~Engine();
    void go();
};

#endif //CS368FINALPROJECT_RPG_ENGINE_HPP
