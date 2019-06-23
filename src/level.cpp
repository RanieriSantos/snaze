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

        //if it pass all the conditions it's a valide position
        currFood.index_row = indexI;
        currFood.index_column = indexJ;
        validPosition = true;
    }
};

//Gets and Sets
void Level::set_mapRow (int row){
    map.num_row = row;
};

void Level::set_mapCol (int col){
    map.num_col = col;
};

int Level::get_mapRow(){
    return map.num_row;
};

int Level::get_mapColumn(){
    return map.num_col;
};
