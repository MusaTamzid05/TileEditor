#ifndef TILE_FILE_H
#define TILE_FILE_H


#include <string>
#include <SFML/Graphics.hpp>

struct TileFile {
    TileFile(const std::string& path);

    void draw(sf::RenderWindow& window);

    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
