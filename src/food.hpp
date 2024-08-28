#pragma once

#include <SFML/Graphics.hpp>

class Food {
   public:
    Food(sf::RenderWindow &window);
    void onRender();
    sf::Vector2i getPosition() { return _position; }
    void randomizePosition();

   private:
    sf::RenderWindow &_window;
    sf::Vector2i _position;
};
