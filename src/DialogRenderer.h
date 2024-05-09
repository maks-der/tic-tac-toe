#ifndef TIC_TAC_TOE_DIALOG_RENDERER_H
#define TIC_TAC_TOE_DIALOG_RENDERER_H

#include <SFML/Graphics.hpp>

class DialogRenderer {
private:
    sf::RenderWindow &window;

    void displayBackground();

    void displayDialog();

    void displayReplayBtn();

    void displayTitle(std::string &message);

public:
    explicit DialogRenderer(sf::RenderWindow &win) : window(win) {}

    void display(std::string &message);
};

#endif