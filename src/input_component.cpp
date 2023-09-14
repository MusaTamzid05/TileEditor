#include "input_component.h"
#include "tile_selector.h"
#include "mouse_selector_component.h"

InputComponent::InputComponent(sf::RenderWindow* window,
        int screen_width,
        TileSelector* tile_selector,
        MouseSelectorComponent* mouse_selector_component
        ):
    screen_width(screen_width),
    window(window),
    tile_selector(tile_selector),
    mouse_selector_component(mouse_selector_component)
{

}

void InputComponent::update() {
    sf::Vector2i mouse_position = sf::Mouse::getPosition(*window);


    sf::Event event;

    while(window->pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window->close();

            if(event.type == sf::Event::MouseButtonPressed) {
                tile_selector->handle_mouse_pressed(event);

            }

            else if(event.type == sf::Event::MouseButtonReleased) {
                tile_selector->handle_mouse_release();
            }

    }

    if(mouse_position.x >  screen_width / 2) {
        mouse_selector_component->handle_mouse_pos(mouse_position);

    }
}

void InputComponent::render(sf::RenderWindow& window) {

}
