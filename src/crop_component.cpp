#include "crop_component.h"


CropComponent::CropComponent(sf::RenderWindow* window, TileFile* tile_file) {
   cropping_rect.setFillColor(sf::Color(255, 0, 0, 10));
   cropping_rect.setOutlineColor(sf::Color::Red);
   cropping_rect.setOutlineThickness(2.0f);
   this->window = window;
   this->tile_file = tile_file;
   cropping = false;


}


void CropComponent::render(sf::RenderWindow& window) {
    if(!cropping)
        return;

    window.draw(cropping_rect);

}


void CropComponent::handle_event(sf::Event& event) {

        if(event.type == sf::Event::MouseButtonPressed) {
            start_point = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
            cropping = true;


        }

        else if(event.type == sf::Event::MouseButtonReleased) {
            end_point = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
            cropping = false;

        }


}

void CropComponent::update() {
        if(cropping) {
            end_point = sf::Vector2f(sf::Mouse::getPosition(*window));
            cropping_rect.setPosition(start_point);
            cropping_rect.setSize(end_point - start_point);


        }

}
