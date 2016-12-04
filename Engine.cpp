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
    window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Game");
    textureManager = new TextureManager();
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
    tile->draw(0,0, window);
    window->display();
}

void Engine::processInput() {
    sf::Event event;

    while(window->pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            window->close();
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
    sf::Texture sprite;
    if (!sprite.loadFromFile("K:\\Liam\\ClionProjects\\CS368FinalProject-RPG\\grass.jpg")) {
        throw "Texture could not be opened";
    }
    textureManager->addTexture(sprite);
    tile = new Tile(textureManager->getTexture(0));
}
