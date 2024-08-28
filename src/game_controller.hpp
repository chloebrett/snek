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
    void increaseScore() { score++; }
    int getScore() { return score; }
    GameState getGameState() { return gameState; }

   private:
    GameState gameState = GameState::GAME_OVER;
    sf::RenderWindow &window;
    int score = 0;
};
