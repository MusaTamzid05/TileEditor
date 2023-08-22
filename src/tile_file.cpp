#include "tile_file.h"
#include <iostream>


TileFile::TileFile(const std::string& path) {

    if(!texture.loadFromFile(path)) {
        std::cerr << "Failed to load " << path << "\n";
        exit(1);
    }

    sprite.setTexture(texture);
    sprite.setPosition(0, 0);

}

void TileFile::draw(sf::RenderWindow& window) {
    std::cout << "drawing\n";
    window.draw(sprite);

}


