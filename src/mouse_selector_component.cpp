#include "mouse_selector_component.h"
#include "tile_selector.h"
#include <iostream>


MouseSelectorItem::MouseSelectorItem(
        const sf::IntRect& rect,
        const sf::Texture& texture,
        int offset_x,
        int offset_y):
    offset_x(offset_x),
    offset_y(offset_y),
    x(0),
    y(0)
{

        sprite = sf::Sprite(texture, rect);



}

void MouseSelectorItem::set_position(int mouse_x, int mouse_y) {

    x = mouse_x + offset_x;
    y = mouse_y + offset_y;

    sprite.setPosition(x, y);

}

void MouseSelectorItem::render(sf::RenderWindow* window) {
    window->draw(sprite);

}



MouseSelectorComponent::MouseSelectorComponent(const sf::Texture& texture, sf::RenderWindow* window, int width):texture(texture),half_width(width / 2), window(window) {

}

void MouseSelectorComponent::render(sf::RenderWindow& window) {
    sf::Vector2i position = sf::Mouse::getPosition(window);

    if(position.x < half_width)
        return;


    for(MouseSelectorItem& item : items) {
        item.render(&window);

    }


}


void MouseSelectorComponent::update() {
    sf::Vector2i position = sf::Mouse::getPosition(*window);

    if(position.x < half_width)
        return;

    for(MouseSelectorItem& item : items)
        item.set_position(position.x, position.y);;
}


void MouseSelectorComponent::handle_event(sf::Event& event) {

}


void MouseSelectorComponent::add(const TileSelectorItem& item) {

    if(items.size() == 0 ) {
        start_x = item.x;
        start_y = item.y;
    }

    int offset_x = abs(item.x - start_x);
    int offset_y = abs(item.y - start_y);

    sf::IntRect rect(item.x, item.y, item.width, item.height);

    MouseSelectorItem mouse_selected_item(rect, texture, offset_x, offset_y);
    items.push_back(mouse_selected_item);


}
