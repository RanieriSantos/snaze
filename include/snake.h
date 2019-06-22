#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "../include/basicStructures.h" // position, Direction

class Snake{

    private:  

    int lifes = 5;                  //number of snake lifes. Initating with 5
    std::vector <position> snake;   //snake head + body. Index 0 = snake head
    Directions direc;               //snake direction
    //pointe to current level

    public:

        //! \brief Snake loses a life
        //! \param respawn position of current map
        void lost_life(position respawn);

        //! \brief Return how many lifes the snake still has
        int get_lifes ();


};


#endif