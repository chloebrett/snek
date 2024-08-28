#include "player.hpp"

#include <SFML/Graphics.hpp>

#include "constants.hpp"
#include "food.hpp"
#include "game_controller.hpp"

Player::Player(GameController &gameController, sf::RenderWindow &window, Food &food)
    : _gameController(gameController), _window(window), _food(food) {
    _bodyPositions = {sf::Vector2i(0, 0)};
    _randomizePosition();
}

void Player::onRender() {
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    rectangle.setOutlineColor(sf::Color::Black);

    for (sf::Vector2i position : _bodyPositions) {
        rectangle.setPosition(position.x * CELL_SIZE, position.y * CELL_SIZE);
        _window.draw(rectangle);
    }
}

void Player::onTick() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && _direction != Direction::DOWN) {
        _nextDirection = Direction::UP;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && _direction != Direction::UP) {
        _nextDirection = Direction::DOWN;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && _direction != Direction::RIGHT) {
        _nextDirection = Direction::LEFT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && _direction != Direction::LEFT) {
        _nextDirection = Direction::RIGHT;
    }

    _ticksUntilNextMove--;
    if (_ticksUntilNextMove <= 0) {
        _ticksUntilNextMove = FRAMES_PER_SECOND / _speed;
        _direction = _nextDirection;
        handleMove();
    }
}

void Player::handleMove() {
    sf::Vector2i headPosition = _bodyPositions.front();
    sf::Vector2i newHeadPosition = headPosition;
    switch (_direction) {
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

    _bodyPositions.insert(_bodyPositions.begin(), newHeadPosition);
    if (_food.getPosition() == newHeadPosition) {
        _food.randomizePosition();
        _speed += SPEED_INCREASE;
        _gameController.increaseScore();
    } else {
        _bodyPositions.pop_back();
    }

    for (int i = 1; i < _bodyPositions.size(); i++) {
        if (_bodyPositions[i] == newHeadPosition) {
            // Game over!
            _bodyPositions = {sf::Vector2i(0, 0)};
            _food.randomizePosition();
            _speed = INITIAL_SPEED;
            _gameController.gameOver();
            break;
        }
    }
}

void Player::_randomizePosition() {
    _bodyPositions = {sf::Vector2i(rand() % GRID_WIDTH, rand() % GRID_HEIGHT)};
}
