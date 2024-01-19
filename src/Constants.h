#ifndef TIC_TAC_TOE_CONSTANTS_H
#define TIC_TAC_TOE_CONSTANTS_H

#include <SFML/Graphics.hpp>

namespace Constants {
    const unsigned int WINDOW_WIDTH = 800;
    const unsigned int WINDOW_HEIGHT = 600;

    const float FIELD_SIZE = 570;
    const sf::Color FIELD_COLOR = sf::Color(250, 241, 190);

    const float CELL_SIZE = 170;
    const sf::Color CELL_COLOR = sf::Color(46, 61, 133);
    const sf::Color CELL_COLOR_HOVER = sf::Color(200, 200, 250);

//    const sf::Color VALUE_COLOR = sf::Color(200, 61, 33);
    const sf::Color VALUE_COLOR = sf::Color(40, 250, 95);
}

#endif
