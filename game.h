#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Game{
public:
    Game(); // c-tor
    ~Game(); //de-tor

    void Update(int dir); // update AI
    void Render(sf::RenderWindow& window); // draw
    bool IsGameOver();
    void Reset();

private:
    bool HitFood();
    void DrawGrid(sf::RenderWindow& window);
    void Generate();

public:
    unsigned int width;
    unsigned int height;
    unsigned int maxX;
    unsigned int maxY;

private:
    Snake snake;
    Food* food;
    sf::Font font;
    sf::Text text;
    sf::Music music;
    unsigned int speedCounter;
    unsigned int resetSpeed;
    unsigned int score;
    unsigned int highScore;
    bool gameOver;
};

#endif
