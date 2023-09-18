#include "cell.h"
#include <iostream>

Cell::Cell(int x, int y, int width, int height, int id):
    x(x),
    y(y),
    width(width),
    height(height),
    id(id) {
        rect.setPosition(x, y);
        rect.setSize(sf::Vector2f(width, height));
        rect.setOutlineThickness(0.5f);
    }

void Cell::set_border_color(const sf::Color& color) {
    rect.setOutlineColor(color);
}


void Cell::set_color(const sf::Color& color) {
    rect.setFillColor(color);
}


void Cell::render(sf::RenderWindow* window) {
    window->draw(rect);
}
