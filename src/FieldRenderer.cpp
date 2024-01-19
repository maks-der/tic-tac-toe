#include <SFML/Graphics.hpp>
#include "FieldRenderer.h"
#include "./Constants.h"

using namespace Constants;

// TODO: change methods to not static
void FieldRenderer::draw(sf::RenderWindow &window, std::vector<int> &values) {
    sf::Vector2 fieldPosition = drawField(window);
    drawCells(window, fieldPosition);
    fillWithValues(window, fieldPosition, values);
}

sf::Vector2<float> FieldRenderer::drawField(sf::RenderWindow &window) {
    float margin = (WINDOW_HEIGHT - FIELD_SIZE) / 2;

    sf::RectangleShape rec;
    sf::Vector2 size = {FIELD_SIZE, FIELD_SIZE};

    rec.setSize(size);
    rec.setPosition((float) WINDOW_WIDTH / 2 - FIELD_SIZE / 2, margin);
    rec.setFillColor(FIELD_COLOR);

    window.draw(rec);

    return rec.getPosition();
}

void FieldRenderer::drawCells(sf::RenderWindow &window, sf::Vector2<float> fieldPosition) {
    for (int i = 0; i < 9; ++i) {
        Vector2 cellPosition = getPositionByIndex(fieldPosition, i);
        drawCell(window, cellPosition);
    }
}

void FieldRenderer::drawCell(sf::RenderWindow &window, sf::Vector2<float> position) {
    sf::RectangleShape rec;

    sf::Vector2 size = {CELL_SIZE, CELL_SIZE};
    rec.setSize(size);
    rec.setPosition(position);
    rec.setFillColor(CELL_COLOR);

    window.draw(rec);
}

void FieldRenderer::fillWithValues(
        sf::RenderWindow &window,
        sf::Vector2<float> fieldPosition,
        std::vector<int> &values
) {
    for (int i = 0; i < 9; ++i) {
        Vector2 valuePosition = getPositionByIndex(fieldPosition, i);
        drawValue(window, values[i], valuePosition);
    }
}

void FieldRenderer::drawValue(sf::RenderWindow &window, int value, sf::Vector2<float> position) {
    if (value == 0) return;
    if (value == 1) {
//    Draw cross
        sf::ConvexShape cross;
        cross.setPointCount(12);

        float offset = 15;

        cross.setPoint(0, sf::Vector2f(0 + offset,35));
        cross.setPoint(1, sf::Vector2f(35,0 + offset));
        cross.setPoint(2, sf::Vector2f(85,50 + offset));

        cross.setPoint(3, sf::Vector2f(135,0 + offset));
        cross.setPoint(4, sf::Vector2f(170 - offset,35));
        cross.setPoint(5, sf::Vector2f(120 - offset, 85));

        cross.setPoint(6, sf::Vector2f(170 - offset,135));
        cross.setPoint(7, sf::Vector2f(135,170 - offset));
        cross.setPoint(8, sf::Vector2f(85,120 - offset));

        cross.setPoint(9, sf::Vector2f(35,170 - offset));
        cross.setPoint(10, sf::Vector2f(0 + offset,135));
        cross.setPoint(11, sf::Vector2f(50 + offset,85));

        cross.setPosition(position);
        cross.setFillColor(VALUE_COLOR);
        window.draw(cross);

        return;
    }
//    Draw circle
    sf::CircleShape circle;
    float outline = 20.f;

    circle.setRadius(CELL_SIZE / 3);
    circle.setPosition(position.x + outline * 1.5f, position.y + outline * 1.5f);
    circle.setFillColor(sf::Color::Transparent);

    circle.setOutlineThickness(outline);
    circle.setOutlineColor(VALUE_COLOR);

    window.draw(circle);
}

sf::Vector2<float> FieldRenderer::getPositionByIndex(sf::Vector2<float> fieldPosition, int index) {
    float margin = (FIELD_SIZE - CELL_SIZE * 3) / 4;
    float initialTop = fieldPosition.y + margin;
    float initialLeft = fieldPosition.x + margin;
    std::vector<sf::Vector2<float>> cells = {
            {initialLeft,                              initialTop},
            {initialLeft + CELL_SIZE + margin,         initialTop},
            {initialLeft + CELL_SIZE * 2 + margin * 2, initialTop},

            {initialLeft,                              initialTop + CELL_SIZE + margin},
            {initialLeft + CELL_SIZE + margin,         initialTop + CELL_SIZE + margin},
            {initialLeft + CELL_SIZE * 2 + margin * 2, initialTop + CELL_SIZE + margin},

            {initialLeft,                              initialTop + CELL_SIZE * 2 + margin * 2},
            {initialLeft + CELL_SIZE + margin,         initialTop + CELL_SIZE * 2 + margin * 2},
            {initialLeft + CELL_SIZE * 2 + margin * 2, initialTop + CELL_SIZE * 2 + margin * 2},
    };

    return cells[index];
}
