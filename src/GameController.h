#ifndef TIC_TAC_TOE_GAME_CONTROLLER_H
#define TIC_TAC_TOE_GAME_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "FieldRenderer.h"
#include "SoundsController.h"

// TODO: create dialog for winner or draw

class GameController {
private:
    sf::RenderWindow &window;
    FieldRenderer &fieldRenderer;
    SoundsController soundsController;
    std::vector<int> fieldValues = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool isPlayerMove = true;
    bool gameOver = false;
    std::string status = "Draw";

    void playerMove();

    void compMove();

    int getRandomInteger(int from, int to);

    bool isPlayerWinner();

    bool isCompWinner();

    bool checkForWinner(int value);

public:
    explicit GameController(
            sf::RenderWindow &win,
            FieldRenderer &fRend
    ) : window(win), fieldRenderer(fRend) {}

    std::vector<int> getCurrentPosition();

    bool isGameOver();

    std::string getStatus();
};

#endif
