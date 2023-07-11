#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include "coord.h"

class Food{
public:
    Food();
    Food(int x, int y);
    ~Food();

    void Update();
    void Draw(sf::RenderWindow& window);
    Coord& GetCoord();

public:
    Coord xy;
};

#endif
