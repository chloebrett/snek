#pragma once

#include <SFML/Graphics.hpp>

class Food {
   public:
    Food(sf::RenderWindow &window);
    void onRender();
    sf::Vector2i getPosition() { return position; }
    void randomizePosition();

   private:
    sf::RenderWindow &window;
    sf::Vector2i position;
};
