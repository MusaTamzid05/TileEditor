#ifndef CROPPING_COMPONENT_H
#define CROPPING_COMPONENT_H

#include "component.h"

struct CropComponent : public  Component {
    CropComponent(sf::RenderWindow* window);
    void render(sf::RenderWindow& window);
    void handle_event(sf::Event& event);
    void update();

    sf::Vector2f start_point;
    sf::Vector2f end_point;

    bool cropping;
    sf::RectangleShape cropping_rect;

    sf::RenderWindow* window;

};



#endif