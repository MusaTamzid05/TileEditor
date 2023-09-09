#include "output_canvas.h"


OutputCanvasItem::OutputCanvasItem(
        int x,
        int y,
        int width,
        int height
        ) {

        rect.setFillColor(sf::Color(0, 0, 0, 0));
        rect.setOutlineThickness(0.5f);
        rect.setOutlineColor(sf::Color::Green);
        rect.setPosition(x, y);
        rect.setSize(sf::Vector2f(width, height));

}


void OutputCanvasItem::render(sf::RenderWindow& window) {
    window.draw(rect);
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
