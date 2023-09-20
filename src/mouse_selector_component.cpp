#include "mouse_selector_component.h"
#include "tile_selector.h"
#include "output_canvas.h"
#include "util.h"
#include "cell.h"
#include <iostream>


MouseSelectorItem::MouseSelectorItem(
        const sf::IntRect& rect,
        const sf::Texture& texture,
        int offset_x,
        int offset_y,
        Cell* cell
        ):
    offset_x(offset_x),
    offset_y(offset_y),
    x(0),
    y(0),
    cell(cell)
    
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


MouseSelectorComponent::MouseSelectorComponent(const sf::Texture& texture, sf::RenderWindow* window, int width, OutputCanvas* output_canvas):texture(texture),half_width(width / 2), window(window), output_canvas(output_canvas) {

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
}


void MouseSelectorComponent::handle_mouse_pos(const sf::Vector2i& mouse_position) {
    sf::Vector2i tile_position = output_canvas->get_hover_tile_position(mouse_position);

    for(MouseSelectorItem& item : items)
        item.set_position(tile_position.x, tile_position.y);;

}


void MouseSelectorComponent::add(Cell* cell) {

    if(items.size() == 0 ) {
        start_x = cell->x;
        start_y = cell->y;
    }

    int offset_x = abs(cell->x - start_x);
    int offset_y = abs(cell->y - start_y);

    sf::IntRect rect(cell->x, cell->y, cell->width, cell->height);


    MouseSelectorItem mouse_selected_item(rect, texture, offset_x, offset_y, cell);
    items.push_back(mouse_selected_item);


}

void MouseSelectorComponent::update_output_canvas() {


    for(auto item : items) {
        int x = item.x;
        int y = item.y;

        std::string key = get_position_key(x, y);


        Cell* original_cell = item.cell;
        Cell* output_cell = output_canvas->cell_map[key];
        
        sf::IntRect rect(original_cell->x, original_cell->y, original_cell->width, original_cell->height);
        output_cell->set_texture(texture, rect);
        output_cell->id = original_cell->id;



    }

}

