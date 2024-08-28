#include "player.hpp"

#include <SFML/Graphics.hpp>

#include "constants.hpp"
#include "food.hpp"
#include "game_controller.hpp"

Player::Player(GameController &gameController, sf::RenderWindow &window, Food &food)
    : gameController(gameController), window(window), food(food) {
    bodyPositions = {sf::Vector2i(0, 0)};
    randomizePosition();
}

void Player::onRender() {
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    rectangle.setOutlineColor(sf::Color::Black);

    for (sf::Vector2i position : bodyPositions) {
        rectangle.setPosition(position.x * CELL_SIZE, position.y * CELL_SIZE);
        window.draw(rectangle);
    }
}

void Player::onTick() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && direction != Direction::DOWN) {
        nextDirection = Direction::UP;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && direction != Direction::UP) {
        nextDirection = Direction::DOWN;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && direction != Direction::RIGHT) {
        nextDirection = Direction::LEFT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && direction != Direction::LEFT) {
        nextDirection = Direction::RIGHT;
    }

    ticksUntilNextMove--;
    if (ticksUntilNextMove <= 0) {
        ticksUntilNextMove = FRAMES_PER_SECOND / speed;
        direction = nextDirection;
        handleMove();
    }
}

void Player::handleMove() {
    sf::Vector2i headPosition = bodyPositions.front();
    sf::Vector2i newHeadPosition = headPosition;
    switch (direction) {
        case Direction::UP:
            newHeadPosition.y--;
            break;
        case Direction::DOWN:
            newHeadPosition.y++;
            break;
        case Direction::LEFT:
            newHeadPosition.x--;
            break;
        case Direction::RIGHT:
            newHeadPosition.x++;
            break;
    }

    // Wrap around the screen
    if (newHeadPosition.x < 0) {
        newHeadPosition.x = GRID_WIDTH - 1;
    } else if (newHeadPosition.x >= GRID_WIDTH) {
        newHeadPosition.x = 0;
    } else if (newHeadPosition.y < 0) {
        newHeadPosition.y = GRID_HEIGHT - 1;
    } else if (newHeadPosition.y >= GRID_HEIGHT) {
        newHeadPosition.y = 0;
    }

    bodyPositions.insert(bodyPositions.begin(), newHeadPosition);
    if (food.getPosition() == newHeadPosition) {
        food.randomizePosition();
        speed += SPEED_INCREASE;
        gameController.increaseScore();
    } else {
        bodyPositions.pop_back();
    }

    for (int i = 1; i < bodyPositions.size(); i++) {
        if (bodyPositions[i] == newHeadPosition) {
            // Game over!
            bodyPositions = {sf::Vector2i(0, 0)};
            food.randomizePosition();
            speed = INITIAL_SPEED;
            gameController.gameOver();
            break;
        }
    }
}

void Player::randomizePosition() {
    bodyPositions = {sf::Vector2i(rand() % GRID_WIDTH, rand() % GRID_HEIGHT)};
}
