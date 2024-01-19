#ifndef TIC_TAC_TOE_FIELDRENDERER_H
#define TIC_TAC_TOE_FIELDRENDERER_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class FieldRenderer {

public:
    void static draw(RenderWindow &window, std::vector<int> &values);

private:
    static sf::Vector2<float> drawField(sf::RenderWindow &window);

    static void drawCells(sf::RenderWindow &window, sf::Vector2<float> fieldPosition);

    static void drawCell(RenderWindow &window, Vector2<float> position);

    static void fillWithValues(
            sf::RenderWindow &window,
            sf::Vector2<float> fieldPosition,
            std::vector<int> &values
    );

    static void drawValue(sf::RenderWindow &window, int value, sf::Vector2<float> position);

    static sf::Vector2<float> getPositionByIndex(sf::Vector2<float> fieldPosition, int index);
};

#endif
