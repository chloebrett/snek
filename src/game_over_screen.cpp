#include "game_over_screen.hpp"

#include <SFML/Graphics.hpp>

#include "constants.hpp"
#include "game_controller.hpp"
#include "game_state.hpp"

GameOverScreen::GameOverScreen(GameController &gameController, sf::RenderWindow &window)
    : _gameController(gameController), _window(window) {
    _font = sf::Font();
    _font.loadFromFile(FONT_PATH);
}

sf::Text GameOverScreen::_makeText(const std::string &textString) {
    sf::Text text;
    text.setFont(_font);
    text.setString(textString);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::White);
    return text;
}

void GameOverScreen::onRender() {
    sf::Text topText = _makeText(GAME_OVER_TEXT + std::to_string(_gameController.getScore()));
    sf::Text bottomText = _makeText(GAME_OVER_RESTART_TEXT);

    sf::FloatRect topTextBounds = topText.getLocalBounds();
    sf::FloatRect bottomTextBounds = bottomText.getLocalBounds();
    int combinedHeight = topTextBounds.height + bottomTextBounds.height;
    sf::Vector2i center = sf::Vector2i(CELL_SIZE * GRID_WIDTH, CELL_SIZE * GRID_HEIGHT) / 2;

    topText.setPosition(
        center.x - topTextBounds.width / 2,
        center.y - combinedHeight + topTextBounds.height / 2 - TEXT_VERTICAL_PADDING);

    bottomText.setPosition(center.x - bottomTextBounds.width / 2,
                           center.y - bottomTextBounds.height / 2 + TEXT_VERTICAL_PADDING);

    _window.draw(topText);
    _window.draw(bottomText);
}

void GameOverScreen::onTick() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _gameController.restart();
    }
}
