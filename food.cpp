#include "food.h"
#include "common.h"

Food::Food() {
    xy.x = rand() % XCELLS;
    xy.y = rand() % YCELLS;
}

Food::Food(int x, int y) {
    xy.x = x;
    xy.y = y;
}

Food::~Food() {
    
}

void Food::Update() {
    // food is always fresh
}

void Food::Draw(sf::RenderWindow& window) {
    //draw the food 
    sf::CircleShape circle(CELL/2);
    circle.setPosition(CELL*xy.x,CELL*xy.y);
    circle.setFillColor(sf::Color::Red);

    window.draw(circle);
}

Coord& Food::GetCoord() {
    return xy;
}
