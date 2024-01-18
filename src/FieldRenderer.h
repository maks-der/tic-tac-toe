#ifndef TIC_TAC_TOE_FIELDRENDERER_H
#define TIC_TAC_TOE_FIELDRENDERER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class FieldRenderer {

public:
    void static draw(RenderWindow &window);

private:
    void static draw_field(RenderWindow &window);

    void static draw_cells(RenderWindow &window);

    void static draw_cell(RenderWindow &window, Vector2<float> position);
};

#endif
