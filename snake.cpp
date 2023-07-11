#include "snake.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "common.h"

Snake::Snake()
    :side(CELL) {
    Reset();
}

Snake::~Snake() {
    
}

bool Snake::Update(int dir) {
    ChangeDir(dir);
    Move(direction);
    bool res = IsIntersecting();
    if (res) {
        return false;
    }
    return true;
}

// draw the snake 
void Snake::Draw(sf::RenderWindow& window) {
    for (int i=0;i<positions.size();i++) {
        Coord c = positions[i];
        sf::RectangleShape shape(sf::Vector2f(side, side));
        shape.setPosition(CELL*c.x,CELL*c.y);
        shape.setFillColor(sf::Color::Yellow);

        window.draw(shape);
    }
    DrawHead(window);
}

void Snake::DrawHead(sf::RenderWindow& window) {
    Coord c = positions[0];
    sf::RectangleShape shape(sf::Vector2f(side, side));
    shape.setPosition(CELL*c.x,CELL*c.y);
    shape.setFillColor(sf::Color(255,128,0));
    window.draw(shape);
}

void Snake::Move(int dir) {
    int dirY = 0;
    int dirX = 0;
    if (dir>NONE) {

        if (dir == UP) {
            dirY = -1;
        }
        if (dir == DOWN) {
            dirY = 1;
        }
        if (dir == RIGHT) {
            dirX = 1;
        }
        if (dir == LEFT) {
            dirX = -1;
        }
    }
    //move the coordinates of the snake
    for (int i=positions.size();i>=0;i--) {
        if (i == 0) {
            positions[i].x += dirX;
            positions[i].y += dirY;            
        }
        else{
            positions[i].x = positions[i-1].x;
            positions[i].y = positions[i-1].y;
        }
    }
}

bool Snake::ChangeDir(int dir) {
    if (dir == UP && direction == DOWN) {
        return false;
    }
    if (dir == LEFT && direction == RIGHT) {
        return false;
    }
    if (dir == DOWN && direction == UP) {
        return false;
    }
    if (dir == RIGHT && direction == LEFT) {
        return false;
    }
    if (dir != NONE) {
        direction = dir;
        return true;
    }
    return true;
}

Coord& Snake::GetHead() {
    return positions[0];
}

int Snake::GetLength() {
    return positions.size();
}

void Snake::Grow() {
    Coord last = positions.back();
    positions.push_back(last);
}

bool Snake::IsIntersecting() {
    for (int i = 1; i < positions.size(); i++) {
        if (positions[0].x == positions[i].x && positions[0].y == positions[i].y) {
            return true;
        }
    }
    return false;
}

void Snake::Reset() {
    positions.clear();

    Coord c1{3,1};
    positions.push_back(c1);

    Coord c2{4,1};
    positions.push_back(c2);

    Coord c3{5,1};
    positions.push_back(c3);

    direction = LEFT;
}

bool Snake::IsSnakeBody(int x, int y) {
    for (int i = 0; i < positions.size(); i++) {
        if (x == positions[i].x && y == positions[i].y) {
            return true;
        }
    }
    return false;
}
