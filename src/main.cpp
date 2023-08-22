#include <SFML/Graphics.hpp>
#include "tile_file.h"

int main(int argc, char** argv) {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Title Editor");
    TileFile tile_file("TilesetHouse.png");

    while(window.isOpen()) {


        window.clear();
        tile_file.draw(window);
        window.display();


        sf::Event event;

        while(window.waitEvent(event)) {

            if(event.type == sf::Event::Closed)
                window.close();



        }



    }

    return 0;
}
