#include <SFML/Graphics.hpp>
#include <vector>
#include "tile_file.h"
#include "tile_selector.h"
#include "crop_component.h"

#include <iostream>
#include <cstdlib>


int main(int argc, char** argv) {

    std::cout << argc << "\n";

    int tile_width = 16;
    int tile_height = 16;

    if(argc == 3) {
        tile_width = atoi(argv[1]);
        tile_height = atoi(argv[2]);
    }


    int width = 1920;
    int height = 1080;

    sf::RenderWindow window(sf::VideoMode(width, height), "Title Editor");

    TileSelector* tile_selector = new TileSelector(tile_width, tile_height, width / 2, height);
    TileFile* tile_file = new TileFile("TilesetHouse.png", tile_selector);


    std::vector<Component*> components;
    components.push_back(new CropComponent(&window, tile_file));
    components.push_back(tile_file);
    components.push_back(tile_selector);


    while(window.isOpen()) {


        for(Component* component : components)
            component->update();


        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed)
                window.close();

            for(Component* component : components)
                component->handle_event(event);


        }


        window.clear();

        for(Component* component : components)
            component->render(window);
        window.display();



    }

    return 0;
}
