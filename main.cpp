#include <SFML/Graphics.hpp>
#include "./src/DialogRenderer.h"
#include "./src/FieldRenderer.h"
#include "./src/Constants.h"
#include "./src/GameController.h"

using namespace Constants;

// TODO: fix bug during resizing window

// TODO: add sounds
// TODO: move all to constants
// TODO: refactor project
// TODO: add score counter

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tic Tac Toe");
    FieldRenderer fieldRenderer(window);
    DialogRenderer messagesRenderer(window);
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
        if (gameController.isGameOver()) {
            std::string statusMessage = gameController.getStatus();
            messagesRenderer.display(statusMessage);
        }

        window.display();
    }
    return 0;
}
