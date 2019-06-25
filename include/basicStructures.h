#ifndef BASICSTRUCTURES_H
#define BASICSTRUCTURES_H

#include <iomanip>   // std::setw, std::setfill
#include <iostream>  //std::cout
#include <sstream>   // std::ostringstream
#include <vector>    //std::vector

static const char SPAWN = '*';      // Snake spawn.
static const char WHT_SPACE = ' ';  // White space.
static const char WALL = '#';       // Common wall.
static const char INV_WALL = '.';   // Invisible wall.
static const char FOOD = 'F';       // Food.

struct position {
        int index_row, index_column;

        bool operator==(const position& pos) {
                return ((index_row == pos.index_row) && (index_column == pos.index_column));
        }
};

enum Directions {
        north,  // 0
        south,  // 1
        west,   // 2
        east    // 3
};

struct grid {
        // Snake initial position.
        position spawn;

        short num_row, num_col;              // Number of rows and columns.
        std::vector<std::vector<char>> map;  // Map from file.

        void print_map() {
                std::ostringstream data;

                std::cout << "Size:\t[" << num_row << " x " << num_col << "]\n" << std::endl;
                std::cout << "Spawn:\t[" << spawn.index_row << "][" << spawn.index_column << "]\n"
                          << std::endl;

                for (int i = 0; i < num_row; i++) {
                        if (i < 10) {
                                data << "[" << i << "]" << std::setw(2) << " ";
                        } else {
                                data << "[" << i << "]" << std::setw(1) << " ";
                        }

                        for (int j = 0; j < num_col; j++) {
                                data << std::setw(1) << map[i][j] << " ";
                        }
                        data << '\n';
                }

                std::cout << data.str() << std::endl;
        }
};

#endif