#include "../include/level.h"

void Level::generate_food_position (){
    bool validPosition = false;
    
    while(!validPosition){

        srand(time(NULL));

        int indexI = rand() % map.num_row; //random number between 0 and number of rowns
        int indexJ = rand() % map.num_col; //random number between 0 and number of columns

        if (map.map[indexI][indexJ] == '#'){
            continue;
        }
        //we also need to verify if the food is on top of the snake

        //if it pass all the condition it's a valide position
        validPosition = true;
    }

};