#include <iostream>
#include <SFML/Window.hpp>
#include <Windows.h>
#include "Engine.hpp"

int main() {
    Engine* engine = new Engine();

    try {
        engine->go();
    }
    catch (char* e) {
        MessageBoxA(NULL, e, "Exception thrown", MB_OK | MB_ICONERROR);
    }
    return 0;
}