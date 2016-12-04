#include <iostream>
#include <SFML/Window.hpp>
#include <Windows.h>
#include "Engine.hpp"

int main() {
    std::cout << "Hi" << std::endl;
    Engine* engine = new Engine();

    try {
        engine->go();
    }
    catch (char* e) {
        MessageBoxA(NULL, e, "Exception thrown", MB_OK | MB_ICONERROR);
    }
//    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Game");
//    sf::Texture texture;
//    texture.loadFromFile("K:\\Liam\\ClionProjects\\CS368FinalProject-RPG\\grass.jpg");
//    sf::Sprite sprite;
//    sprite.setTexture(texture);
//    window.clear();
//    window.draw(sprite);
//    window.display();
//    Sleep(2000);
    return 0;
}