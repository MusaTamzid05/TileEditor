#include "tile_selector.h"
#include <iostream>

TileSelectorItem::TileSelectorItem(
        int x,
        int y,
        int width,
        int height):
    x(x),
    y(y),
    width(width),
    height(height)
{


   rect.setFillColor(sf::Color(0, 0, 0, 0));
   rect.setOutlineColor(sf::Color::Red);
   rect.setOutlineThickness(0.5f);

   rect.setPosition(x, y);
   rect.setSize(sf::Vector2f(width, height));



}

void TileSelectorItem::render(sf::RenderWindow& window) {
    sf::Vector2f position = rect.getPosition();
    window.draw(rect);
}

void TileSelectorItem::update() {
}

void TileSelectorItem::handle_event(sf::Event& event) {

}


TileSelector::TileSelector(int tile_width, int tile_height, int texture_width, int texture_height):
    tile_width(tile_width),
    tile_height(tile_height),
    texture_width(texture_width),
    texture_height(texture_height) {


    for(int y = 0; y < texture_height; y += tile_height) {
        for(int x = 0; x < texture_width; x += tile_width) {
            items.push_back(TileSelectorItem(x, y, tile_width, tile_height));

        }
    }



}



void TileSelector::render(sf::RenderWindow& window) {
    for(TileSelectorItem item : items)
        item.render(window);


}


void TileSelector::update() {

}

void TileSelector::handle_event(sf::Event& event) {

}


void TileSelector::add(sf::Sprite& sprite, int width, int height) {
    /*
    sprite.setPosition(last_x, last_y);
    sprites.push_back(sprite);
    last_x += width + space;
    */

}
