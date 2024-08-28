#pragma once

constexpr float FRAMES_PER_SECOND = 60.0f;
constexpr float SPEED_INCREASE = 0.5f;
constexpr float INITIAL_SPEED = 2.0f;

constexpr int CELL_SIZE = 40;
constexpr int GRID_WIDTH = 10;
constexpr int GRID_HEIGHT = 10;

constexpr int SCREEN_WIDTH = CELL_SIZE * GRID_WIDTH;
constexpr int SCREEN_HEIGHT = CELL_SIZE * GRID_HEIGHT;

constexpr int FONT_SIZE = 12;
constexpr int TEXT_VERTICAL_PADDING = 10;
const std::string FONT_PATH = "res/PressStart2P-Regular.ttf";
const std::string GAME_OVER_TEXT = "GAME OVER. SCORE: ";
const std::string GAME_OVER_RESTART_TEXT = "PRESS SPACE TO RESTART";
