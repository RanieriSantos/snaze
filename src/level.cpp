#include "../include/level.h"

void Level::generate_food_position (){
    bool validPosition = true;

    do {

        int indexI = rand() % map.num_row; //random number between 0 and number of rowns
        int indexJ = rand() % map.num_col; //random number between 0 and number of columns

        //verifies if the position is not an wall or invisible wall
        if (map.map[indexI][indexJ] != '#' && map.map[indexI][indexJ] != '.'){

            //verifies if the position is not the snake
            for(auto const& value : pSnake->get_snake()){
                if ((value.index_row) == indexI && (value.index_row == indexJ)) {
                        validPosition = false;
                        break;
                }
            }
            if (validPosition){
                currFood.index_row = indexI;
                currFood.index_column = indexJ;
            }
            
        }

    }while(validPosition);
    // bool validPosition = false;
    
    // while(!validPosition){

    //     srand(time(NULL));

    //     int indexI = rand() % map.num_row; //random number between 0 and number of rowns
    //     int indexJ = rand() % map.num_col; //random number between 0 and number of columns

    //     //verifies if the position is an wall or invisible wall
    //     if (map.map[indexI][indexJ] == '#'|| map.map[indexI][indexJ] == "."){
    //         continue;
    //     } 
        
    //     //we also need to verify if the food is on top of the snake
    //     else if( std::find(pSnake.begin().snake.index_row == indexI) && std::find(pSnake.begin().snake.index_column == indexJ)){
    //         continue;
    //     }
        

    //     //if it pass all the conditions it's a valid position
    //     currFood.index_row = indexI;
    //     currFood.index_column = indexJ;
    //     validPosition = true;
};

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS
int Level::get_numFood(){
    return numFood;
};

int Level::get_mapRow(){
    return map.num_row;
};

int Level::get_mapColumn(){
    return map.num_col;
};

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS
void Level::set_numFood(int num){
    numFood = num;
};

void Level::set_mapRow (int row){
    map.num_row = row;
};

void Level::set_mapCol (int col){
    map.num_col = col;
};

void Level::set_snake (Snake snake){
    pSnake = &snake;
}
