#include "../include/level.h"

void Level::generate_food_position() {
        bool validPosition = false;

        do {
                srand(time(NULL));
                int indexI = rand() % map.num_row;  // random number between 0 and number of rowns
                int indexJ = rand() % map.num_col;  // random number between 0 and number of columns

                // verifies if the position is not an wall or invisible wall
                if (map.map[indexI][indexJ] != '#' && map.map[indexI][indexJ] != '.') {
                        // verifies if the position is not the snake
                        for (auto const& value : *pSnake->get_snake()) {
                                if ((value.index_row) == indexI && (value.index_row == indexJ)) {
                                        validPosition = false;
                                        break;
                                } else {
                                        validPosition = true;
                                }
                        }

                        if (validPosition) {
                                currFood.index_row = indexI;
                                currFood.index_column = indexJ;
                                break;
                        }
                }

        } while (!validPosition);
};

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS
int Level::get_numFood() { return numFood; };

int Level::get_mapRow() { return map.num_row; };

int Level::get_mapColumn() { return map.num_col; };

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS
void Level::set_numFood(int num) { numFood = num; };

void Level::set_mapRow(int row) { map.num_row = row; };

void Level::set_mapCol(int col) { map.num_col = col; };

void Level::set_snake(Snake* snake) { this->pSnake = snake; }
