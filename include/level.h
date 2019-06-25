#ifndef LEVEL_H
#define LEVEL_H

#include <time.h>     // Used to generate a radom food all the time the program is run
#include <algorithm>  // std::find
#include <vector>     //std::vector
#include "basicStructures.h"
#include "snake.h"  //We need this to generate the food

class Level {
       private:
        // position currFood; //position of current food
        int numFood = 10;  // Each map begins with 10 food

        //! \brief Funtion that will set a position for the current food
        void generate_food_position();

       public:
        grid map;       // Map itself
        Snake* pSnake;  // pointer to the Snake
        position currFood;

        //! \brief Level constructor
        //! \param snake - vector of position that represents snake body
        Level() {
                // default
        }
        Level(grid lvl) { map = lvl; }
        Level(Snake snake) { pSnake = &snake; }

        ~Level(){};

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS
        //! \brief Return how many food are missing to be eaten
        int get_numFood();

        //! brief Returns number of rows of map
        int get_mapRow();

        //! brief Returns number of columns of map
        int get_mapColumn();

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS
        //! \brief Sets number of food that are missing
        void set_numFood(int num);

        //! brief Set map rows
        void set_mapRow(int row);

        //! brief Set map columns
        void set_mapCol(int col);

        //! brief Set snake pointer to the used snake
        void set_snake(Snake* snake);
};

#endif