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
    void render(sf::RenderWindow* window);

    sf::RectangleShape rect;
    sf::Sprite sprite;

};

#endif
