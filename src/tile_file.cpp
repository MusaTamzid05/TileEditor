#include "tile_file.h"
#include <iostream>


TileFile::TileFile(const std::string& path) {

    if(!texture.loadFromFile(path)) {
        std::cerr << "Failed to load " << path << "\n";
        exit(1);
    }

    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    crop_image_selected = false;

}

void TileFile::render(sf::RenderWindow& window) {
    window.draw(sprite);


    if(crop_image_selected) {
        window.draw(crop_sprite);

    }
}

void TileFile::update() {
}

void TileFile::handle_event(sf::Event& event) {

}

void TileFile::crop(const sf::Vector2f start_point, const sf::Vector2f end_point) {

    sf::IntRect crop_rect(
            static_cast<int>(start_point.x),
            static_cast<int>(start_point.y),
            static_cast<int>(end_point.x - start_point.x),
            static_cast<int>(end_point.y - start_point.y)
            );

    crop_sprite.setTexture(texture);
    crop_sprite.setTextureRect(crop_rect);
    crop_sprite.setPosition(1500, 100);
    crop_image_selected = true;


}


