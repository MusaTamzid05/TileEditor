#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

struct Cell {
    Cell(int x, int y, int width, int height, int id=-1);

    int x;
    int y;
    int width;
    int height;
    int id;

    void set_border_color(const sf::Color& color);
    void set_color(const sf::Color& color);
    void set_sprite(const sf::Sprite& other_sprite);


    void render(sf::RenderWindow* window);

    void set_position(int x, int y);
    void set_texture(const sf::Texture& texture, const  sf::IntRect& texture_rect);

    sf::RectangleShape rect;
    sf::Sprite sprite;



};

#endif
