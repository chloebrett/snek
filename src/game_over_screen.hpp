#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "game_controller.hpp"

class GameOverScreen {
   public:
    GameOverScreen(GameController &gameController, sf::RenderWindow &window);
    void onTick();
    void onRender();

   private:
    sf::Font _font;
    GameController &_gameController;
    sf::RenderWindow &_window;
};
