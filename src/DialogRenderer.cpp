#include "Constants.h"
#include "DialogRenderer.h"

using namespace Constants;

void DialogRenderer::display(std::string &message) {
    displayBackground();
    displayDialog();
//    displayReplayBtn();
    displayTitle(message);
}

void DialogRenderer::displayBackground() {
    sf::RectangleShape background;

    background.setSize({WINDOW_WIDTH, WINDOW_HEIGHT});
    background.setFillColor(sf::Color(0, 0, 0, 150));

    window.draw(background);
}

void DialogRenderer::displayDialog() {
    sf::RectangleShape dialog;

    dialog.setSize({300, 200});
    dialog.setPosition((float) WINDOW_WIDTH / 2 - 150, (float) WINDOW_HEIGHT / 2 - 100);
    dialog.setFillColor(sf::Color::White);

    window.draw(dialog);
}

// TODO: refactor bitton
void DialogRenderer::displayReplayBtn() {
    sf::RectangleShape button;

    button.setSize({110, 50});
    button.setPosition((float) WINDOW_WIDTH / 2 - 60, (float) WINDOW_HEIGHT / 2);
    button.setFillColor(FIELD_COLOR);

    window.draw(button);

    sf::Font font;
    font.loadFromFile("assets/cantarell-regular.ttf");

    sf::Text title("Replay", font);
    title.setPosition((float) WINDOW_WIDTH / 2 - 55, (float) WINDOW_HEIGHT / 2 + 5);
    title.setCharacterSize(30);
    title.setStyle(sf::Text::Bold);
    title.setFillColor(sf::Color::White);

    window.draw(title);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
    }
}

void DialogRenderer::displayTitle(std::string &message) {
    sf::Font font;
    font.loadFromFile("assets/cantarell-regular.ttf");

    sf::Text title(message, font);
    title.setPosition(320, 240);
    title.setCharacterSize(30);
    title.setStyle(sf::Text::Bold);
    title.setFillColor(FIELD_COLOR);

    window.draw(title);
}
