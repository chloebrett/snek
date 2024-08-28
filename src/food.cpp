#include "food.hpp"

#include <SFML/Graphics.hpp>

#include "constants.hpp"

Food::Food(sf::RenderWindow &window) : _window(window) {
    _position = {sf::Vector2i(0, 0)};
    randomizePosition();
}

void Food::onRender() {
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::White);
    rectangle.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setPosition(_position.x * CELL_SIZE, _position.y * CELL_SIZE);
    _window.draw(rectangle);
}

void Food::randomizePosition() {
    _position = {sf::Vector2i(rand() % GRID_WIDTH, rand() % GRID_HEIGHT)};
}
