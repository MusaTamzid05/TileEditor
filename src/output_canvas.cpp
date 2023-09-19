#include "output_canvas.h"
#include "tile_selector.h"
#include "util.h"
#include "cell.h"


OutputCanvasItem::OutputCanvasItem(
        int x,
        int y,
        int width,
        int height,
        TileSelectorItem* original_tile
        ):
    x(x),
    y(y),
    width(width),
    height(height),
    original_tile(original_tile) {

        rect.setFillColor(sf::Color(0, 0, 0, 0));
        rect.setOutlineThickness(0.5f);
        rect.setOutlineColor(sf::Color::Green);
        rect.setPosition(x, y);
        rect.setSize(sf::Vector2f(width, height));

}


void OutputCanvasItem::render(sf::RenderWindow& window) {
    window.draw(rect);

    if(original_tile != nullptr) {
        window.draw(sprite);

    }
}


bool OutputCanvasItem::is_hovered(const sf::Vector2i& mouse_position) const {
    int min_x = x;
    int min_y = y;
    int max_x = min_x + width;
    int max_y = min_y + height;

    int mouse_x = mouse_position.x;
    int mouse_y = mouse_position.y;


    bool x_axis = mouse_x >= min_x && mouse_x <= max_x;
    bool y_axis = mouse_y >= min_y && mouse_y <= max_y;

    return x_axis && y_axis;



}

void OutputCanvasItem::set_tile(TileSelectorItem* original_tile, const sf::Sprite& mouse_selected_sprite) {
    sprite = mouse_selected_sprite;
    sprite.setPosition(x, y);
    this->original_tile = original_tile;


}

OutputCanvas::OutputCanvas(
        int start_point,
        int total_width,
        int total_height,
        int tile_width,
        int tile_height) {

    for(int y = 0; y < total_height; y += tile_height) {
        for(int x = start_point ; x < total_width; x += tile_width) {
            std::string key = get_position_key(x, y);
            Cell* cell = new Cell(x, y, tile_width, tile_height);

            cell->set_color(sf::Color(0, 0, 0, 0));
            cell->set_border_color(sf::Color(0, 255, 0, 100));

            //cell_map.insert(key, cell);
            cell_map[key] = cell;
            //items.insert(key, OutputCanvasItem(x, y, tile_width, tile_height));
        }

    }

}


void OutputCanvas::render(sf::RenderWindow& window) {
    for(auto cell_item : cell_map) {
        cell_item.second->render(&window);

    }

}
void OutputCanvas::update() {

}

void OutputCanvas::handle_event(sf::Event& event) {

}

bool OutputCanvas::is_hovered(const sf::Vector2i& mouse_position, Cell* cell) const {
    int min_x = cell->x;
    int min_y = cell->y;
    int max_x = min_x + cell->width;
    int max_y = min_y + cell->height;

    int mouse_x = mouse_position.x;
    int mouse_y = mouse_position.y;


    bool x_axis = mouse_x >= min_x && mouse_x <= max_x;
    bool y_axis = mouse_y >= min_y && mouse_y <= max_y;

    return x_axis && y_axis;

}


sf::Vector2i OutputCanvas::get_hover_tile_position(const sf::Vector2i& mouse_pos) {
    for(auto cell_item : cell_map) {
        if(is_hovered(mouse_pos, cell_item.second))
            return sf::Vector2i(cell_item.second->x, cell_item.second->y);


    }

    return sf::Vector2i(0, 0);

}
