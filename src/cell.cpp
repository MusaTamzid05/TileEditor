#include "cell.h"
#include <iostream>

Cell::Cell(int x, int y, int width, int height, int id):
    x(x),
    y(y),
    width(width),
    height(height),
    id(id) {
        set_position(x, y);
        rect.setSize(sf::Vector2f(width, height));
        rect.setOutlineThickness(0.5f);
    }

void Cell::set_border_color(const sf::Color& color) {
    rect.setOutlineColor(color);
}


void Cell::set_color(const sf::Color& color) {
    rect.setFillColor(color);
}

void Cell::set_sprite(const sf::Sprite& sprite) {
    this->sprite = sprite;
    this->sprite.setPosition(x, y);
}

void Cell::render(sf::RenderWindow* window) {
    window->draw(rect);

    const sf::Texture* texture = sprite.getTexture();


    if(sprite.getTexture() != nullptr) {
        window->draw(sprite);
    }

}

void Cell::set_position(int x, int y) {
    rect.setPosition(x, y);
    sprite.setPosition(x, y);


}


void Cell::set_texture(const sf::Texture& texture, const  sf::IntRect& texture_rect) {
    sprite = sf::Sprite(texture , texture_rect);
    sprite.setPosition(x, y);

}
