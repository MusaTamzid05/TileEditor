#ifndef TILE_SELECTOR_H
#define TILE_SELECTOR_H

#include "component.h"
#include <vector>

struct TileSelectorItem : Component {

    TileSelectorItem(
            int x,
            int y,
            int width,
            int height
            );

    void render(sf::RenderWindow& window);
    void update();
    void handle_event(sf::Event& event);


    int x;
    int y;
    int width;
    int height;

    sf::RectangleShape rect;



};

struct TileSelector : Component {

    TileSelector(int tile_width, int tile_height, int texture_width, int texture_height);

    void render(sf::RenderWindow& window);
    void update();
    void handle_event(sf::Event& event);

    void add(sf::Sprite& sprite, int width, int height);


    std::vector<TileSelectorItem> items;

    int tile_width;
    int tile_height;;
    int texture_width;
    int texture_height;

};

#endif
