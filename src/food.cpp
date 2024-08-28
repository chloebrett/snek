#include "food.hpp"

#include <SFML/Graphics.hpp>

#include "constants.hpp"

Food::Food(sf::RenderWindow &window) : window(window) {
    position = {sf::Vector2i(0, 0)};
    randomizePosition();
}

void Food::onRender() {
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::White);
    rectangle.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setPosition(position.x * CELL_SIZE, position.y * CELL_SIZE);
    window.draw(rectangle);
}

void Food::randomizePosition() {
    position = {sf::Vector2i(rand() % GRID_WIDTH, rand() % GRID_HEIGHT)};
}
