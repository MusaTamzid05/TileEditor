#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include "component.h"

struct TileSelector;
struct MouseSelectorComponent;

struct InputComponent : Component {

    InputComponent(sf::RenderWindow* window,
            int screen_width,
            TileSelector* tile_selector,
            MouseSelectorComponent* mouse_selector_component
            );

    void render(sf::RenderWindow& window);
    void update();


    sf::RenderWindow* window;

    int screen_width;

    TileSelector* tile_selector;
    MouseSelectorComponent* mouse_selector_component;


};

#endif
