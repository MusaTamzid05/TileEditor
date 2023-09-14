#ifndef COMPONENT_H
#define COMPONENT_H
#include <SFML/Graphics.hpp>

struct Component {
    Component() {}
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void update() = 0;

};

#endif
