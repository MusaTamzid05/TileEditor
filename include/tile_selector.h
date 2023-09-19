#ifndef TILE_SELECTOR_H
#define TILE_SELECTOR_H

#include "component.h"
#include <vector>

struct MouseSelectorComponent;
struct Cell;

struct TileSelectorItem : Component {

    TileSelectorItem(
            int x,
            int y,
            int width,
            int height,
            int id
            );

    void render(sf::RenderWindow& window);
    void update();
    void handle_event(sf::Event& event);

    void set_color(const sf::Color& color);


    int x;
    int y;
    int width;
    int height;

    int id;

    sf::RectangleShape rect;



};

struct TileSelector : Component {

    TileSelector(int tile_width,
            int tile_height,
            int texture_width,
            int texture_height,
            sf::RenderWindow* window
            );

    void render(sf::RenderWindow& window);
    void update();
    void handle_event(sf::Event& event);

    void handle_mouse_pressed(const sf::Event& event);
    void handle_mouse_release();

    void highlight();
    void update_mouse_selector();


    std::vector<Cell*> cells;

    int tile_width;
    int tile_height;;
    int texture_width;
    int texture_height;

    sf::Color selected_color;


    sf::Vector2f select_start_point;
    sf::Vector2f select_end_point;

    bool selection_on;
    sf::RenderWindow* window;

    MouseSelectorComponent* mouse_selector_component;

};

#endif
