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

    std::vector<OutputCanvasItem> items;
};


#endif
