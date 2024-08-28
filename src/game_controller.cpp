#include "game_controller.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

#include "constants.hpp"
#include "game_state.hpp"

GameController::GameController(sf::RenderWindow &window) : window(window) {}

void GameController::restart() {
    gameState = GameState::PLAYING;
    score = 0;
}

void GameController::gameOver() { gameState = GameState::GAME_OVER; }
