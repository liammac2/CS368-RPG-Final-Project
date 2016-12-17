//
// Created by Liam on 11/4/2016.
//

#include "Engine.hpp"
#include <iostream>

Engine::Engine() {

}

Engine::~Engine() {

}

bool Engine::initialize() {
    window = new sf::RenderWindow(sf::VideoMode(800, 800, 32), "Game");
    textureManager = new TextureManager();
    tiles.resize(20);
    for (size_t i = 0; i < 20; i++) {
        tiles[i].resize(20);
    }
    loadTextures();

    if (!window) {
        return false;
    }

    return true;
}

void Engine::loop() {
    while(window->isOpen()) {
        processInput();
        update();
        renderFrame();
    }
}

void Engine::renderFrame() {
    window->clear();
    for (size_t i = 0; i < 20; i++) {
        for (size_t j = 0; j < 20; j++) {
            tiles[i][j]->draw(j * tilesize, i * tilesize, window);
        }
    }
    player->draw(window);
    window->display();
}

void Engine::processInput() {
    sf::Event event;

    while(window->pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                player->setPositionY(player->getSpeed() * -1);
                player->setPosition();
                player->setTilesMoved(player->getTilesMoved() + 1);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                player->setPositionY(player->getSpeed());
                player->setPosition();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                player->setPositionX(player->getSpeed() * -1);
                player->setPosition();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                player->setPositionX(player->getSpeed());
                player->setPosition();
            }
        }
    }
}

void Engine::update() {

}

void Engine::go() {
    if(!initialize()) {
        throw "Engine totally failed. Learn to code, n00b.";
    }

    loop();
}

void Engine::loadTextures() {
    sf::Image image;
    sf::Texture sprite;
    if (!sprite.loadFromFile("K:\\Liam\\ClionProjects\\CS368FinalProject-RPG\\grass.jpg")) {
        throw "Texture could not be opened";
    }
    textureManager->addTexture(sprite);

    if (!image.loadFromFile("K:\\Liam\\ClionProjects\\CS368FinalProject-RPG\\OurIntrepidHero.png")) {
        throw "Texture could not be opened";
    }
    sf::Texture sprite2;
    image.createMaskFromColor(sf::Color::White, 0);
    if (!sprite2.loadFromImage(image)) {
        throw "Image couldn't be loaded";
    }
    textureManager->addTexture(sprite2);

    for (size_t i = 0; i < 20; i++) {
        for (size_t j = 0; j < 20; j++) {
            tiles[i][j] = new Tile(textureManager->getTexture(0));
            tiles[i][j]->setSpriteScale(.1, .1);
        }
    }

    player = new Player(textureManager->getTexture(1), 400, 400, 20);
}
