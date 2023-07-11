# SNAKE

This project was used to learn C++. It is the classic SNAKE game remade in the SFML engine (https://www.sfml-dev.org). I learned how to create a window, draw shapes, handle keyboard inputs, and use audio.

## C++

I learned several things:

- Classes with `public` and `private` functions/variables
- Constants
- `std::vector` & `std::string`
- `std::cout`
- Define directives

Besides building the project, I had to use many constants, which led me to utilize many public and private variables as well. This project employs several .h files, and I used ifdef directives for each .h file. For instance, the `coord.h` file is called by multiple files.

This project allowed me to learn the use of `std::vector`, as the coordinate system for the snake is built upon each value of the vector having an x and y value. The vector is cleared, and new values are added into it. When the snake moves, the values are being replaced by the previous value in the vector.

## SFML

The "graphics" are simple, as the snake is merely a set of squares, the food is a circle, and the grid is made by drawing lines. Working on this project provided me with an understanding of the "game-loop": having a main file, calling upon the update, and then rendering the graphics.

## Makefile

This project also helped me learn how to write a simple Makefile that builds the project without requiring the user to write the name of all the files in the project.

## How to build

```
make all
./snake
```

## Credits

The font used for the game over text and the sound effect is not by me:

- The font is called "MineCrafter," and it is created by PurePixel.
- The sound effect used was made by hosch (https://hosch.itch.io).
