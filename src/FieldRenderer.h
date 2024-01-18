#ifndef TIC_TAC_TOE_FIELDRENDERER_H
#define TIC_TAC_TOE_FIELDRENDERER_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class FieldRenderer {

public:
    void static draw(RenderWindow &window);

private:
    static sf::Vector2<float> draw_field(sf::RenderWindow &window);

    static void draw_cells(sf::RenderWindow &window, sf::Vector2<float> fieldPosition);

    static void draw_cell(RenderWindow &window, Vector2<float> position);

    void fill_with_values(std::vector<int> values);
};

#endif
