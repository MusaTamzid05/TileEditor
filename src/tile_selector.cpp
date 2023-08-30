#include "tile_selector.h"

TileSelector::TileSelector(int y):
    last_x(0),
    last_y(y) {

        space = 5;

}


void TileSelector::render(sf::RenderWindow& window) {

    for(sf::Sprite sprite : sprites)
        window.draw(sprite);


}


void TileSelector::update() {

}

void TileSelector::handle_event(sf::Event& event) {

}


void TileSelector::add(sf::Sprite& sprite, int width, int height) {
    sprite.setPosition(last_x, last_y);
    sprites.push_back(sprite);
    last_x += width + space;

}
