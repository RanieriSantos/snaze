#include "../include/snake.h"

void Snake::lost_life(position respawn) {
        if (lifes == 0) {
                // gameover
        } else {
                // snake loses a life
                lifes--;

                // body is cleared
                snake.clear();

                // head is positioned at respawn
                snake.push_back(respawn);
        }
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS

int Snake::get_lifes() { return lifes; }

std::vector<position>* Snake::get_snake() { return &snake; }

Directions Snake::get_diretion() { return direc; }

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS
void Snake::set_snake(int row, int col) {
        position pos;
        pos.index_row = row;
        pos.index_column = col;

        this->snake.push_back(pos);
}

void Snake::set_diretion(Directions direction) { direc = direction; }