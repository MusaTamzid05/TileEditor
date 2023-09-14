#ifndef MOUSE_SELECTOR_COMPONENT_H
#define MOUSE_SELECTOR_COMPONENT_H


#include "component.h"
#include <vector>

struct TileSelectorItem;
struct OutputCanvas;

struct MouseSelectorItem {

    MouseSelectorItem(
            const sf::IntRect& rect,
            const sf::Texture& texture,
            int offset_x,
            int offset_y);

    int offset_x;
    int offset_y;

    void set_position(int mouse_x, int mouse_y);
    void render(sf::RenderWindow* window);

    sf::Sprite sprite;
    sf::IntRect rect;

    int x;
    int y;
};


struct MouseSelectorComponent : Component {
    MouseSelectorComponent(const sf::Texture& texture, sf::RenderWindow* window, int width,
            OutputCanvas* output_canvas
            );

    void render(sf::RenderWindow& window);
    void update();
    void handle_mouse_pos(const sf::Vector2i& mouse_position);


    void add(const TileSelectorItem& item);

    sf::Texture texture;

    int start_x;
    int start_y;

    std::vector<MouseSelectorItem> items;

    int half_width;
    sf::RenderWindow* window;
    OutputCanvas* output_canvas;




};

#endif
