#include "game_controller.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

#include "constants.hpp"
#include "game_state.hpp"

GameController::GameController(sf::RenderWindow &window) : _window(window) {}

void GameController::restart() {
    _gameState = GameState::PLAYING;
    _score = 0;
}

void GameController::gameOver() { _gameState = GameState::GAME_OVER; }
