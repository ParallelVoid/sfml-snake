#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
#include "common.h"

int main()
{
    srand((unsigned int)time(NULL));
    Game game;
    
    sf::RenderWindow window(sf::VideoMode(game.width, game.height), "SNAKE!");
    //int keyPressed[4]; // 0=UP,1=RIGHT,2=DOWN,3=LEFT
    int dir = NONE;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //keyPressed[0] = keyPressed[1] = keyPressed[2] = keyPressed[3] = 0;
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                if (game.IsGameOver()) {
                    if (event.key.code == sf::Keyboard::Space) {
                        dir = NONE;
                        game.Reset();
                    }
                }
                if (event.key.code == sf::Keyboard::W) {
                    dir = UP;
                }
                if (event.key.code == sf::Keyboard::D) {
                   dir = RIGHT;
                }
                if (event.key.code == sf::Keyboard::S) {
                   dir = DOWN;
                }
                if (event.key.code == sf::Keyboard::A) {
                   dir = LEFT;
                }
            }
        }
        
        game.Update(dir);
        window.clear();
        game.Render(window);
        window.display();
    }

    return 0;
}