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

    GameController &gameController;
    sf::RenderWindow &window;
    Food &food;
    int ticksUntilNextMove = 0;
    Direction nextDirection = Direction::RIGHT;
    Direction direction = Direction::RIGHT;
    std::vector<sf::Vector2i> bodyPositions;
    float speed = INITIAL_SPEED;  // moves per second
    void randomizePosition();
};
