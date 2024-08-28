#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "constants.hpp"
#include "food.hpp"
#include "game_controller.hpp"

class Player {
   public:
    Player(GameController &gameController, sf::RenderWindow &window, Food &food);
    void onTick();
    void onRender();
    void handleMove();

   private:
    enum class Direction { UP, DOWN, LEFT, RIGHT };

    void _randomizePosition();

    GameController &_gameController;
    sf::RenderWindow &_window;
    Food &_food;
    int _ticksUntilNextMove = 0;
    Direction _nextDirection = Direction::RIGHT;
    Direction _direction = Direction::RIGHT;
    std::vector<sf::Vector2i> _bodyPositions;
    float _speed = INITIAL_SPEED;  // moves per second
};
