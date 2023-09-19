#ifndef OUTPUT_CANVAS_H
#define OUTPUT_CANVAS_H

#include "component.h"
#include <vector>

struct TileSelectorItem;
struct Cell;

struct OutputCanvasItem {

    OutputCanvasItem(
            int x,
            int y,
            int width,
            int height,
            TileSelectorItem* original_tile=nullptr
            );

    void render(sf::RenderWindow& window);

    sf::RectangleShape rect;

    bool is_hovered(const sf::Vector2i& mouse_position) const;

    void set_tile(TileSelectorItem* original_tile, const sf::Sprite& mouse_selected_sprite);

    int x;
    int y;
    int width;
    int height;

    sf::Sprite sprite;
    TileSelectorItem* original_tile;
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

    bool is_hovered(const sf::Vector2i& mouse_position, Cell* cell) const;

    sf::Vector2i get_hover_tile_position(const sf::Vector2i& mouse_pos);

    std::map<std::string, Cell*> cell_map;
};


#endif
