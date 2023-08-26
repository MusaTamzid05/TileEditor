#include <SFML/Graphics.hpp>
#include <vector>
#include "tile_file.h"
#include "crop_component.h"


#include <iostream>

int main(int argc, char** argv) {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Title Editor");
    TileFile tile_file("TilesetHouse.png");

    std::vector<Component*> components;
    components.push_back(new CropComponent(&window));


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
        tile_file.draw(window);

        for(Component* component : components)
            component->render(window);
        window.display();



    }

    return 0;
}
