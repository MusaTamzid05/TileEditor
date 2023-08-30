#ifndef TILE_FILE_H
#define TILE_FILE_H


#include <string>
#include <SFML/Graphics.hpp>
#include "component.h"
#include "tile_selector.h"

struct TileFile : Component {
    TileFile(const std::string& path, TileSelector* tile_selector);

    void render(sf::RenderWindow& window);
    void update();
    void handle_event(sf::Event& event);

    void crop(const sf::Vector2f start_point, const sf::Vector2f end_point);

    sf::Texture texture;
    sf::Sprite sprite;
    TileSelector* tile_selector;



};

#endif
