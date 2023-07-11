#include "game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include "common.h"

Game::Game()
    :width(CELL*XCELLS)
    ,height(CELL*YCELLS)
    ,maxX(width/CELL)
    ,maxY(height/CELL)
    ,speedCounter(0)
    ,resetSpeed(RESETSPEED)
    ,score(0)
    ,highScore(0)
    ,gameOver(false) {
    if (!font.loadFromFile("font.ttf")) {
        std::cout<<"Font not loaded"<<std::endl;
    }
    if (!music.openFromFile("sfx_switch.ogg")) {
        std::cout<<"Sound not loaded"<<std::endl;
    }

    food = new Food();
}

Game::~Game() {
    delete food;
}

void Game::Update(int dir) {
    if (gameOver) {
        return;
    }
    speedCounter --;
    if (speedCounter % resetSpeed == 0) {
        speedCounter = resetSpeed;
        bool changed = snake.Update(dir);
        if (!changed) {
            gameOver = true;
        }
    }
    Coord c = snake.GetHead();
    if (c.x<0) {
        gameOver = true;
    }
    else if (c.x>=maxX) {
        gameOver = true;
    }
    else if (c.y<0) {
        gameOver = true;
    }
    else if (c.y>=maxY) {
        gameOver = true;
    }
    bool foodHit = HitFood();
    if (foodHit) {
        if (food != nullptr) {
            Game::Generate();
        }
        snake.Grow();
    }
}

void Game::Render(sf::RenderWindow& window) {
    DrawGrid(window);
    snake.Draw(window);
    if (food != nullptr) {
        food->Draw(window);
    }

    if (IsGameOver()) {
        text.setFont(font); // font is a sf::Font
        text.setString("GAme Over");
        text.setCharacterSize(64); // in pixels, not points!
        text.setFillColor(sf::Color::Green);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setPosition(width/4, height/2);
        window.draw(text);

        text.setString("Press SPACE to PLAY AGAin");
        text.setCharacterSize(32); // in pixels, not points!
        text.setFillColor(sf::Color::Green);
        text.setStyle(sf::Text::Underlined);
        text.setPosition(width/4 - 36, height/2 + 64);
        window.draw(text);

        std::string scoreString;
        std::string tempString;
        if (score > highScore) {
            highScore = score;
        }
        scoreString = "Your Score Is ";
        tempString = std::to_string(score);
        scoreString = scoreString + tempString;
        tempString = " And Your High Score Is ";
        scoreString = scoreString + tempString;
        tempString = std::to_string(highScore);
        scoreString = scoreString + tempString;

        text.setString(scoreString);
        text.setCharacterSize(25); // in pixels, not points!
        text.setFillColor(sf::Color::Green);
        text.setStyle(sf::Text::Underlined);
        text.setPosition(width/8, height/2 + 2*64);
        window.draw(text);
    }
}

void Game::DrawGrid(sf::RenderWindow& window) {
    for (int i=0;i<width;i+=CELL){
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(i, 0)),
            sf::Vertex(sf::Vector2f(i, height))
        };

        window.draw(line, 2, sf::Lines);
    }

    for (int i=0;i<height;i=i+CELL) {
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(0, i)),
            sf::Vertex(sf::Vector2f(width, i))
        };

        window.draw(line, 2, sf::Lines);
    }
}


bool Game::IsGameOver() {
    return gameOver;
}

bool Game::HitFood() {
    if (food == nullptr) {
        return false;
    }

    Coord snakeCoord = snake.GetHead();

    int foodX = food->GetCoord().x;
    int foodY = food->GetCoord().y;

    if (snakeCoord.x == foodX && snakeCoord.y == foodY) {
            int snakeLength = snake.GetLength();
            if ((snakeLength - 3) % 5 == 0) {
                resetSpeed -= 200;
            }
            score++;
            std::cout << "Score:" << score << std::endl;
            music.play();
            return true;
    }
    return false;
}

void Game::Generate() {
    bool inSnake = true;
    int foodX;
    int foodY;
    do {
        foodX = rand() % XCELLS;
        foodY = rand() % YCELLS;

        inSnake = snake.IsSnakeBody(foodX, foodY);
    } while (inSnake);
    
    delete food;
    food = new Food(foodX, foodY);
}

void Game::Reset() {
    resetSpeed = RESETSPEED;
    score = 0;
    snake.Reset();
    Generate();
    gameOver = false;
}
