#include <SFML/Graphics.hpp>
#include "FieldRenderer.h"
#include "./Constants.h"

using namespace Constants;

void FieldRenderer::draw(sf::RenderWindow &window) {
    sf::Vector2 fieldPosition = draw_field(window);
    draw_cells(window, fieldPosition);
}

sf::Vector2<float> FieldRenderer::draw_field(sf::RenderWindow &window) {
    float margin = (WINDOW_HEIGHT - FIELD_SIZE) / 2;

    sf::RectangleShape rec;
    sf::Vector2 size = {FIELD_SIZE, FIELD_SIZE};

    rec.setSize(size);
    rec.setPosition((float) WINDOW_WIDTH / 2 - FIELD_SIZE / 2, margin);
    rec.setFillColor(FIELD_COLOR);

    window.draw(rec);

    return rec.getPosition();
}

void FieldRenderer::draw_cells(sf::RenderWindow &window, sf::Vector2<float> fieldPosition) {
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
    for (int i = 0; i < 9; ++i) {
        draw_cell(window, cells[i]);
    }
}

void FieldRenderer::draw_cell(sf::RenderWindow &window, sf::Vector2<float> position) {
    sf::RectangleShape rec;

    sf::Vector2 size = {CELL_SIZE, CELL_SIZE};
    rec.setSize(size);
    rec.setPosition(position);
    rec.setFillColor(CELL_COLOR);

    window.draw(rec);
}
