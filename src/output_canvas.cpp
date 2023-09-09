#include "output_canvas.h"


OutputCanvasItem::OutputCanvasItem(
        int x,
        int y,
        int width,
        int height
        ):
    x(x),
    y(y),
    width(width),
    height(height) {

        rect.setFillColor(sf::Color(0, 0, 0, 0));
        rect.setOutlineThickness(0.5f);
        rect.setOutlineColor(sf::Color::Green);
        rect.setPosition(x, y);
        rect.setSize(sf::Vector2f(width, height));

}


void OutputCanvasItem::render(sf::RenderWindow& window) {
    window.draw(rect);
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

OutputCanvas::OutputCanvas(
        int start_point,
        int total_width,
        int total_height,
        int tile_width,
        int tile_height) {

    for(int y = 0; y < total_height; y += tile_height) {
        for(int x = start_point ; x < total_width; x += tile_width) {
            items.push_back(OutputCanvasItem(x, y, tile_width, tile_height));
        }

    }

}


void OutputCanvas::render(sf::RenderWindow& window) {
    for(OutputCanvasItem item : items) {
        item.render(window);

    }

}
void OutputCanvas::update() {

}

void OutputCanvas::handle_event(sf::Event& event) {

}


sf::Vector2i OutputCanvas::get_hover_tile_position(const sf::Vector2i& mouse_pos) {
    for(OutputCanvasItem item : items) {
        if(item.is_hovered(mouse_pos))
            return sf::Vector2i(item.x, item.y);


    }

    return sf::Vector2i(0, 0);

}
