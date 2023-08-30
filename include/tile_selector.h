#ifndef TILE_SELECTOR_H
#define TILE_SELECTOR_H

#include "component.h"
#include <vector>

struct TileSelector : Component {

    TileSelector(int y);
    void render(sf::RenderWindow& window);
    void update();
    void handle_event(sf::Event& event);

    void add(sf::Sprite& sprite, int width, int height);

    int last_x;
    int last_y;

    int space;

    std::vector<sf::Sprite> sprites;

};

#endif
