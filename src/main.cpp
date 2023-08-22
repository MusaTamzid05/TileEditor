#include <SFML/Graphics.hpp>
#include "tile_file.h"
#include <iostream>

int main(int argc, char** argv) {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Title Editor");
    TileFile tile_file("TilesetHouse.png");

    sf::Vector2f start_point;
    sf::Vector2f end_point;
    bool cropping = false;
    sf::RectangleShape cropping_rect;
    cropping_rect.setFillColor(sf::Color(0, 0, 0, 0));
    cropping_rect.setOutlineColor(sf::Color::Red);
    cropping_rect.setOutlineThickness(2.0f);

    while(window.isOpen()) {




        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed) {
                start_point = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                cropping = true;

            }

            if(event.type == sf::Event::MouseButtonReleased) {
                end_point = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                tile_file.crop(start_point, end_point);
                cropping = false;

            }




        }


        window.clear();
        tile_file.draw(window);

        if(cropping) {
            end_point = sf::Vector2f(sf::Mouse::getPosition(window));
            cropping_rect.setPosition(start_point);
            cropping_rect.setSize(end_point - start_point);

            window.draw(cropping_rect);

        }

        window.display();



    }

    return 0;
}
