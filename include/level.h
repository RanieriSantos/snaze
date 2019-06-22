#ifndef LEVEL_H
#define LEVEL_H

#include "basicStructures.h"
#include "snake.h" //We need this to generate the food
#include <time.h> // Used to generate a radom food all the time the program is run


class Level {

    private:

    position currFood; //position of current food
    grid map; // Map itself
    int numFood = 10; // Each map begins with 10 food
    Snake pSnake; //pointer to the Snake

     //! \brief Funtion that will set a position for the current food
    void generate_food_position ();

};

#endif