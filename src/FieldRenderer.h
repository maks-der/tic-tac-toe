#ifndef TIC_TAC_TOE_FIELD_RENDERER_H
#define TIC_TAC_TOE_FIELD_RENDERER_H

#include <iostream>
#include <SFML/Graphics.hpp>

class FieldRenderer {
private:
    sf::RenderWindow &window;
    sf::Vector2f fieldPosition;

    sf::Vector2f drawField();

    void drawCells();

    void drawCell(sf::Vector2f position);

    void fillWithValues(std::vector<int> &values);

    void drawValue(int value, sf::Vector2f position);

    sf::Vector2f getPositionByIndex(int index);

    bool isInCell(sf::Vector2f cellLeftTop, sf::Vector2f position);

public:
    explicit FieldRenderer(sf::RenderWindow &win) : window(win) {};

    void draw(std::vector<int> &values);

    int getIndexByPosition(sf::Vector2f position);
};

#endif
