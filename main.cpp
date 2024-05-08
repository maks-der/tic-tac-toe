#include <SFML/Graphics.hpp>
#include "./src/FieldRenderer.h"
#include "./src/Constants.h"
#include "./src/GameController.h"

using namespace Constants;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tic Tac Toe");
    FieldRenderer fieldRenderer(window);
    GameController gameController(window, fieldRenderer);

    window.setPosition({100, 100});


    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear(CELL_COLOR);
        std::vector<int> fieldValues = gameController.getCurrentPosition();
        fieldRenderer.draw(fieldValues);
        window.display();
    }
    return 0;
}
