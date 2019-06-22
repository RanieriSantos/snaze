#include "../include/snake.h"

void Snake::lost_life(position respawn){
    if (lifes == 0){
        //gameover
    }else{
        //snake loses a life
        lifes --;

        //body is cleared
        snake.clear();

        //head is positioned at respawn
        snake.push_back(respawn);
    }
}

int Snake::get_lifes (){
    return lifes;
}