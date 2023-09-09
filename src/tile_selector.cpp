#include "tile_selector.h"
#include "mouse_selector_component.h"
#include <iostream>
#include <cmath>

TileSelectorItem::TileSelectorItem(
        int x,
        int y,
        int width,
        int height):
    x(x),
    y(y),
    width(width),
    height(height) {

        rect.setFillColor(sf::Color(0, 0, 0, 0));
        rect.setOutlineThickness(0.5f);
        rect.setPosition(x, y);
        rect.setSize(sf::Vector2f(width, height));



}

void TileSelectorItem::render(sf::RenderWindow& window) {
    window.draw(rect);
}

void TileSelectorItem::update() {
}

void TileSelectorItem::handle_event(sf::Event& event) {

}


void TileSelectorItem::set_color(const sf::Color& color) {
    rect.setFillColor(color);

}


TileSelector::TileSelector(int tile_width, int tile_height, int texture_width, int texture_height, sf::RenderWindow* window):
    tile_width(tile_width),
    tile_height(tile_height),
    texture_width(texture_width),
    texture_height(texture_height),
    selection_on(false),
    window(window)
{
        selected_color = sf::Color(255, 0, 0, 100);


        for(int y = 0; y < texture_height; y += tile_height) {
            for(int x = 0; x < texture_width; x += tile_width) {
                TileSelectorItem item = TileSelectorItem(x, y, tile_width, tile_height);
                items.push_back(item);

            }
        }



}



void TileSelector::render(sf::RenderWindow& window) {
    for(TileSelectorItem item : items)
        item.render(window);


}


void TileSelector::update() {
    if(selection_on) {
        select_end_point = sf::Vector2f(sf::Mouse::getPosition(*window));
        highlight();

    }


}

void TileSelector::handle_event(sf::Event& event) {
    if(event.type == sf::Event::MouseButtonPressed) {
        select_start_point = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        selection_on = true;

    }

    else if(event.type == sf::Event::MouseButtonReleased) {
        update_mouse_selector();
        selection_on = false;

    }

}


void TileSelector::highlight() {
    float min_x = select_start_point.x;
    float max_x = select_start_point.x + fabs(select_end_point.x - select_start_point.x);
    float min_y = select_start_point.y;
    float max_y = select_start_point.y + fabs(select_end_point.y - select_start_point.y);


    for(TileSelectorItem& item : items) {

        int item_max_x = item.x + item.width;
        int item_max_y = item.y + item.height;

        int item_center_x = item.x + (item.width / 2);
        int item_center_y = item.y + (item.height/ 2);

        bool x_axis_collider =  item_center_x >= min_x && item_center_x <= max_x;
        bool y_axis_collider =  item_center_y >= min_y && item_center_y <= max_y;


        if(x_axis_collider && y_axis_collider) {
            item.set_color(selected_color);
        } 
        else {
            item.set_color(sf::Color(0, 0, 0, 0));

        }

    }

}

void TileSelector::update_mouse_selector() {
    mouse_selector_component->items.clear();

    for(TileSelectorItem item : items) {
        if(item.rect.getFillColor() != selected_color)
            continue;

        mouse_selector_component->add(item);

    }


}
