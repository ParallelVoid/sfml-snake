#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "coord.h"

class Snake{
public:
    Snake();
    ~Snake();

    bool Update(int dir);
    void Draw(sf::RenderWindow& window);
    bool ChangeDir(int dir);
    Coord& GetHead();
    int GetLength();
    bool IsSnakeBody(int x, int y);
    void Grow();
    void Reset();
private:
    void Move(int dir);
    void DrawHead(sf::RenderWindow& window);
    bool IsIntersecting();

private:
    std::vector<Coord> positions;
    int direction;
    const unsigned int side;
};

#endif
