#include "game_over_screen.hpp"

#include <SFML/Graphics.hpp>

#include "constants.hpp"
#include "game_controller.hpp"
#include "game_state.hpp"

GameOverScreen::GameOverScreen(GameController &gameController, sf::RenderWindow &window)
    : gameController(gameController), window(window) {
    font = sf::Font();
    font.loadFromFile("res/PressStart2P-Regular.ttf");
}

void GameOverScreen::onRender() {
    sf::Text topText;
    topText.setFont(font);
    topText.setString("GAME OVER. SCORE: " + std::to_string(gameController.getScore()));
    topText.setCharacterSize(12);
    topText.setFillColor(sf::Color::White);

    sf::Text bottomText;
    bottomText.setFont(font);
    bottomText.setString("PRESS SPACE TO RESTART");
    bottomText.setCharacterSize(12);
    bottomText.setFillColor(sf::Color::White);

    int padding = 10;

    int height = topText.getLocalBounds().height + bottomText.getLocalBounds().height;
    topText.setPosition(
        CELL_SIZE * GRID_WIDTH / 2 - topText.getLocalBounds().width / 2,
        CELL_SIZE * GRID_HEIGHT / 2 - height + topText.getLocalBounds().height / 2 - padding);

    bottomText.setPosition(
        CELL_SIZE * GRID_WIDTH / 2 - bottomText.getLocalBounds().width / 2,
        CELL_SIZE * GRID_HEIGHT / 2 - bottomText.getLocalBounds().height / 2 + padding);

    window.draw(topText);
    window.draw(bottomText);
}

void GameOverScreen::onTick() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        gameController.restart();
    }
}
