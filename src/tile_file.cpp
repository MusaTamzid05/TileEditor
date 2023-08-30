#include "tile_file.h"
#include <iostream>


TileFile::TileFile(const std::string& path, TileSelector* tile_selector) {

    if(!texture.loadFromFile(path)) {
        std::cerr << "Failed to load " << path << "\n";
        exit(1);
    }

    this->tile_selector = tile_selector;

    sprite.setTexture(texture);
    sprite.setPosition(0, 0);

}

void TileFile::render(sf::RenderWindow& window) {
    window.draw(sprite);


}

void TileFile::update() {
}

void TileFile::handle_event(sf::Event& event) {

}

void TileFile::crop(const sf::Vector2f start_point, const sf::Vector2f end_point) {

    int width = end_point.x - start_point.x;
    int height = end_point.y - start_point.y;

    sf::IntRect crop_rect(
            static_cast<int>(start_point.x),
            static_cast<int>(start_point.y),
            static_cast<int>(width),
            static_cast<int>(height)
            );

    sf::Sprite crop_sprite;

    crop_sprite.setTexture(texture);
    crop_sprite.setTextureRect(crop_rect);

    tile_selector->add(crop_sprite, width, height);


}


