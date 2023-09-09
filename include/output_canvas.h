#ifndef OUTPUT_CANVAS_H
#define OUTPUT_CANVAS_H

#include "component.h"
#include <vector>

struct OutputCanvasItem {

    OutputCanvasItem(
            int x,
            int y,
            int width,
            int height
            );

    void render(sf::RenderWindow& window);

    sf::RectangleShape rect;

    bool is_hovered(const sf::Vector2i& mouse_position) const;

    int x;
    int y;
    int width;
    int height;
};

struct OutputCanvas : Component {
    OutputCanvas(
            int start_point,
            int total_width,
            int total_height,
            int tile_width,
            int tile_height);

    void render(sf::RenderWindow& window);
    void update();
    void handle_event(sf::Event& event);

    sf::Vector2i get_hover_tile_position(const sf::Vector2i& mouse_pos);

    std::vector<OutputCanvasItem> items;
};


#endif
