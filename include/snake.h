#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "../include/basicStructures.h"  // position, Direction

class Snake {
       private:
        int lifes = 5;                // number of snake lifes. Initating with 5
        std::vector<position> snake;  // snake head + body. Index 0 = snake head
        Directions direc;             // snake direction
                                      // pointe to current level

       public:
        //! |brief Snake constructor
        //! \param init - initial position of snake
        //! \param dir - initial direction of snake

        Snake() {
                // default
        }
        Snake(position init, Directions dir) {
                position pos;
                pos.index_row = init.index_row;
                pos.index_column = init.index_column;

                snake.push_back(pos);
                direc = dir;
        };

        //! \brief Snake loses a life
        //! \param respawn position of current map
        void lost_life(position respawn);

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS

        //! \brief Return how many lifes the snake still has
        int get_lifes();

        //! \brief Returns snake vector
        std::vector<position>* get_snake();

        //! \brief Return snake direction
        Directions get_diretion();

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS

        //! \brief add a position to snake body
        //! \param row - row index of the position
        //! \param col - column index of the position
        void set_snake(int row, int col);

        //! \brief add direction of snake
        void set_diretion(Directions direction);

        void move(Directions way);
};

#endif