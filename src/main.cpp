#include <SFML/Graphics.hpp>
#include <vector>
#include "tile_file.h"
#include "tile_selector.h"
#include "mouse_selector_component.h"
#include "output_canvas.h"
#include "input_component.h"

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

    TileSelector* tile_selector = new TileSelector(tile_width, tile_height, width / 2, height, &window);
    TileFile* tile_file = new TileFile("TilesetHouse.png", tile_selector);
    OutputCanvas* output_canvas = new OutputCanvas(width / 2, width, height, tile_width, tile_height);
    MouseSelectorComponent* mouse_selector_component = new MouseSelectorComponent(tile_file->texture, &window, width, output_canvas);
    tile_selector->mouse_selector_component = mouse_selector_component;

    InputComponent* input_component = new InputComponent(
            &window,
            width,
            tile_selector,
            mouse_selector_component
            );


    std::vector<Component*> components;
    components.push_back(tile_file);
    components.push_back(tile_selector);
    components.push_back(mouse_selector_component);
    components.push_back(output_canvas);
    components.push_back(input_component);


    while(window.isOpen()) {


        for(Component* component : components)
            component->update();


        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed)
                window.close();



        }


        window.clear();

        for(Component* component : components)
            component->render(window);
        window.display();



    }

    return 0;
}
