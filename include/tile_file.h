#ifndef TILE_FILE_H
#define TILE_FILE_H


#include <string>
#include <SFML/Graphics.hpp>
#include "component.h"

struct TileFile : Component {
    TileFile(const std::string& path);

    void render(sf::RenderWindow& window);
    void update();
    void handle_event(sf::Event& event);

    void crop(const sf::Vector2f start_point, const sf::Vector2f end_point);

    sf::Texture texture;
    sf::Sprite sprite;

    sf::Texture crop_texture;
    sf::Sprite crop_sprite;

    bool crop_image_selected;

};

#endif
