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

std::vector<position> Snake::get_snake() { return snake; }

Directions Snake::get_diretion() { return direc; }

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS
void Snake::set_snake(int row, int col) {
        position pos;
        pos.index_row = row;
        pos.index_column = col;

        this->snake.push_back(pos);
}

void Snake::set_diretion(Directions direction) { direc = direction; }

void Snake::move(Directions way) {
        position last_head = snake[0];
        position aux;

        switch (way) {
                case north:  // North -i  keep j
                        for (auto &value : snake) {
                                if (last_head == snake[0]) {
                                        snake[0].index_row--;
                                } else {
                                        aux = value;
                                        value = last_head;
                                        last_head = aux;
                                }
                        }
                        break;

                case south:  // South +i  keep j
                        for (auto &value : snake) {
                                if (last_head == snake[0]) {
                                        snake[0].index_row++;
                                } else {
                                        aux = value;
                                        value = last_head;
                                        last_head = aux;
                                }
                        }
                        break;

                case west:  // West  keep i  --j
                        for (auto &value : snake) {
                                if (last_head == snake[0]) {
                                        snake[0].index_column--;
                                } else {
                                        aux = value;
                                        value = last_head;
                                        last_head = aux;
                                }
                        }
                        break;

                case east:  // East  keep i  +j
                        for (auto &value : snake) {
                                if (last_head == snake[0]) {
                                        snake[0].index_column++;
                                } else {
                                        aux = value;
                                        value = last_head;
                                        last_head = aux;
                                }
                        }
                        break;
        }
}