#include "game.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <vector>

#include "constants.hpp"
#include "food.hpp"
#include "game_controller.hpp"
#include "game_over_screen.hpp"
#include "game_state.hpp"
#include "player.hpp"

void Game::start() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "snek");

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f / FRAMES_PER_SECOND);

    GameController gameController = GameController(window);

    GameOverScreen gameOverScreen(gameController, window);
    Food food(window);
    Player player(gameController, window, food);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;

            if (gameController.getGameState() == GameState::PLAYING) {
                player.onTick();
            } else if (gameController.getGameState() == GameState::GAME_OVER) {
                gameOverScreen.onTick();
            }
        }

        window.clear();

        if (gameController.getGameState() == GameState::PLAYING) {
            player.onRender();
            food.onRender();
        } else if (gameController.getGameState() == GameState::GAME_OVER) {
            gameOverScreen.onRender();
        }
        window.display();
    }
};
