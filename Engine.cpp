//
// Created by Liam on 11/4/2016.
//

#include "Engine.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <sstream>

Engine::Engine() {

}

Engine::~Engine() {

}

sf::Font font;


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

    if (gameOver) {
        window->draw(menu[3]);
    }
    else if (battleProcessing) {
        window->draw(menu[0]);
        window->draw(menu[1]);
        window->draw(menu[2]);
        window->draw(menu[4]);
        window->draw(menu[5]);
        enemy->draw(window);
    }
    else {
        for (size_t i = 0; i < 20; i++) {
            for (size_t j = 0; j < 20; j++) {
                tiles[i][j]->draw(j * tilesize, i * tilesize, window);
            }
        }
        player->draw(window);
        std::stringstream ss3;
        ss3 << "Step Count: " << player->getTilesMoved();
        menu[6].setString(ss3.str());
        window->draw(menu[6]);
    }
    window->display();
}

void Engine::processInput() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed && !gameOver) {
            if (battleProcessing) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    menu[selectedMenu].setFillColor(sf::Color::White);
                    selectedMenu--;
                    if (selectedMenu < 0) {
                        selectedMenu = 2;
                    }
                    menu[selectedMenu].setFillColor(sf::Color::Red);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    menu[selectedMenu].setFillColor(sf::Color::White);
                    selectedMenu++;
                    if (selectedMenu > 2) {
                        selectedMenu = 0;
                    }
                    menu[selectedMenu].setFillColor(sf::Color::Red);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
                    processBattle();
                }
            }
            else {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    player->setPositionY(player->getSpeed() * -1);
                    player->setPosition();
                    player->setTilesMoved(player->getTilesMoved() + 1);

                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    player->setPositionY(player->getSpeed());
                    player->setPosition();
                    player->setTilesMoved(player->getTilesMoved() + 1);

                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    player->setPositionX(player->getSpeed() * -1);
                    player->setPosition();
                    player->setTilesMoved(player->getTilesMoved() + 1);

                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    player->setPositionX(player->getSpeed());
                    player->setPosition();
                    player->setTilesMoved(player->getTilesMoved() + 1);
                }
            }
        }
        if (player->getTilesMoved() >= 20) {
            battleProcessing = true;
            player->setTilesMoved(0);
        }
    }
}

void Engine::update() {

}

void Engine::go() {
    if(!initialize()) {
        throw "Engine failed";
    }

    loop();
}

void Engine::loadTextures() {
    sf::Image image;
    sf::Texture sprite;
    if (!sprite.loadFromFile("grass.jpg")) {
        throw "Texture could not be opened";
    }
    textureManager->addTexture(sprite);

    if (!image.loadFromFile("OurIntrepidHero.png")) {
        throw "Texture could not be opened";
    }
    sf::Texture sprite2;
    image.createMaskFromColor(sf::Color::White, 0);
    if (!sprite2.loadFromImage(image)) {
        throw "Image couldn't be loaded";
    }
    textureManager->addTexture(sprite2);

    if (!image.loadFromFile("Devil.png")) {
        throw "Texture could not be opened";
    }
    sf::Texture sprite3;
    image.createMaskFromColor(sf::Color::White, 0);
    if (!sprite3.loadFromImage(image)) {
        throw "Image couldn't be loaded";
    }
    textureManager->addTexture(sprite3);

    for (size_t i = 0; i < 20; i++) {
        for (size_t j = 0; j < 20; j++) {
            tiles[i][j] = new Tile(textureManager->getTexture(0));
            tiles[i][j]->setSpriteScale(.1, .1);
        }
    }

    player = new Player(textureManager->getTexture(1), window->getSize().x / 2, window->getSize().y / 2, 40);

    enemy = new Enemy(textureManager->getTexture(2));

    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Font failed to load" << std::endl;
    }

    sf::Text attack;
    attack.setFont(font);
    attack.setFillColor(sf::Color::Red);
    attack.setString("Attack");
    attack.setPosition(tilesize, window->getSize().y - window->getSize().y / 10);

    sf::Text defend;
    defend.setFont(font);
    defend.setFillColor(sf::Color::White);
    defend.setString("Defend");
    defend.setPosition(window->getSize().x / 3 + tilesize, window->getSize().y - window->getSize().y / 10);

    sf::Text flee;
    flee.setFont(font);
    flee.setFillColor(sf::Color::White);
    flee.setString("Flee");
    flee.setPosition( 2 * (window->getSize().x / 3) + tilesize, window->getSize().y - window->getSize().y / 10);

    sf::Text gameover;
    gameover.setFont(font);
    gameover.setFillColor(sf::Color::Red);
    gameover.setString("Game Over");
    gameover.setPosition(window->getSize().x / 2, window->getSize().y / 2);

    sf::Text playerHealth;
    playerHealth.setFont(font);
    playerHealth.setFillColor(sf::Color::Blue);
    std::stringstream ss;
    ss << "Player Health: " << player->getHP();
    playerHealth.setString(ss.str());
    playerHealth.setPosition(tilesize, window->getSize().y / 10);

    sf::Text enemyHealth;
    enemyHealth.setFont(font);
    enemyHealth.setFillColor(sf::Color::Magenta);
    std::stringstream ss2;
    ss2 << "Enemy Health: " << enemy->getHP();
    enemyHealth.setString(ss2.str());
    enemyHealth.setPosition(2 * (window->getSize().x / 3), window->getSize().y / 10);

    sf::Text stepCount;
    stepCount.setFont(font);
    stepCount.setFillColor(sf::Color::Black);
    std::stringstream ss3;
    ss3 << "Step Count: " << player->getTilesMoved();
    stepCount.setString(ss3.str());
    stepCount.setPosition(tilesize, window->getSize().y - window->getSize().y / 10);

    menu.push_back(attack);
    menu.push_back(defend);
    menu.push_back(flee);
    menu.push_back(gameover);
    menu.push_back(playerHealth);
    menu.push_back(enemyHealth);
    menu.push_back(stepCount);
}

void Engine::processBattle() {
    if (selectedMenu == 0) {
        if (player->attack(enemy)) {
            battleProcessing = false;
            enemy->reset();
            std::stringstream ss2;
            ss2 << "Enemy Health: " << enemy->getHP();
            menu[5].setString(ss2.str());
        }
        else if (enemy->attack(player)) {
            battleProcessing = false;
            gameOver = true;
        }
        else {
            std::stringstream ss;
            ss << "Player Health: " << player->getHP();
            menu[4].setString(ss.str());
            std::stringstream ss2;
            ss2 << "Enemy Health: " << enemy->getHP();
            menu[5].setString(ss2.str());
        }
    }
    else if (selectedMenu == 1) {
        player->defend();
        if (enemy->attack(player)) {
            battleProcessing = false;
            gameOver = true;
        }
        else {
            std::stringstream ss;
            ss << "Player Health: " << player->getHP();
            menu[4].setString(ss.str());
            std::stringstream ss2;
            ss2 << "Enemy Health: " << enemy->getHP();
            menu[5].setString(ss2.str());
        }
        player->setDef(player->getDef() / 2);
    }
    else {
        if (player->flee()) {
            battleProcessing = false;
            enemy->reset();
            std::stringstream ss2;
            ss2 << "Enemy Health: " << enemy->getHP();
            menu[5].setString(ss2.str());
        }
        else if (enemy->attack(player)) {
            battleProcessing = false;
            gameOver = true;
        }
    }
}
