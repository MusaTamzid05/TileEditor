#include "output_canvas.h"
#include "tile_selector.h"
#include "util.h"


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
            //items.push_back(OutputCanvasItem(x, y, tile_width, tile_height));
            items[key] = new OutputCanvasItem(x, y, tile_width, tile_height);
            //items.insert(key, OutputCanvasItem(x, y, tile_width, tile_height));
        }

    }

}


void OutputCanvas::render(sf::RenderWindow& window) {
    for(auto item : items) {
        item.second->render(window);

    }

}
void OutputCanvas::update() {

}

void OutputCanvas::handle_event(sf::Event& event) {

}


sf::Vector2i OutputCanvas::get_hover_tile_position(const sf::Vector2i& mouse_pos) {
    for(auto item : items) {
        if(item.second->is_hovered(mouse_pos))
            return sf::Vector2i(item.second->x, item.second->y);


    }

    return sf::Vector2i(0, 0);

}
