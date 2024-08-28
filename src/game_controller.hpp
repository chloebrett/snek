#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "constants.hpp"
#include "game_state.hpp"

class GameController {
   public:
    GameController(sf::RenderWindow &window);
    void restart();
    void gameOver();
    void increaseScore() { _score++; }
    int getScore() { return _score; }
    GameState getGameState() { return _gameState; }

   private:
    GameState _gameState = GameState::PLAYING;
    sf::RenderWindow &_window;
    int _score = 0;
};
