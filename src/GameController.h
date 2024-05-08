#ifndef TIC_TAC_TOE_GAME_CONTROLLER_H
#define TIC_TAC_TOE_GAME_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "FieldRenderer.h"

class GameController {
private:
    sf::RenderWindow &window;
    FieldRenderer &fieldRenderer;
    std::vector<int> fieldValues = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool isPlayerMove = true;

    void playerMove();

    void compMove();

public:
    explicit GameController(
            sf::RenderWindow &win,
            FieldRenderer &fRend
    ) : window(win), fieldRenderer(fRend) {}

    std::vector<int> getCurrentPosition();
};

#endif
