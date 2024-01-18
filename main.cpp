#include <iostream>
#include <SFML/Graphics.hpp>
#include "./src/FieldRenderer.h"
#include "./src/Constants.h"

using namespace Constants;


int main() {
    std::cout << "Hello";

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tic Tac Toe");

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear(CELL_COLOR);
        FieldRenderer::draw(window);
        window.display();
    }
    return 0;
}

