//
// Created by Liam on 11/4/2016.
//

#ifndef CS368FINALPROJECT_RPG_ENGINE_HPP
#define CS368FINALPROJECT_RPG_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

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
    Player *player;
    Enemy *enemy;
    int selectedMenu = 0;
    int tilesize = 40;
    bool battleProcessing = false;
    void processBattle();
    std::vector<sf::Text> menu;
    bool gameOver = false;


public:
    Engine();
    ~Engine();
    void go();
};

#endif //CS368FINALPROJECT_RPG_ENGINE_HPP
