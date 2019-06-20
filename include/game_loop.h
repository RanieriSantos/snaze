#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <fstream>   //Stream class to read and write from/to files - using std::ifstream
#include <iomanip>   // std::setw, std::setfill
#include <iostream>  //std::cout, std::cin
#include <queue>     //std::queue
#include <sstream>   // std::ostringstream
#include <string>    //std::string, std::getline.
#include <vector>    //std::vector

static const char SPAWN = '*';      // Snake spawn.
static const char WHT_SPACE = ' ';  // White space.
static const char WALL = '#';       // Common wall.
static const char INV_WALL = '.';   // Invisible wall.

class GameLoop {
       private:
        struct grid {
                // Snake initial position.
                struct spawn {
                        short row, col;
                } spawn;

                short num_row, num_col;              // Number of rows and columns.
                std::vector<std::vector<char>> map;  // Map from file.

                void print_map() {
                        std::ostringstream data;

                        std::cout << "Size:\t[" << num_row << " x " << num_col << "]\n"
                                  << std::endl;
                        std::cout << "Spawn:\t[" << spawn.row << "][" << spawn.col << "]\n"
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

        std::queue<grid> vec_maps;  // Maps from file.
        std::string inputFile;

        //! \brief Read file with snaze maps.
        int read_file(int argc, char *argv[]);

       public:
        /////////////////////////////////////////////
        // Client functions
        /////////////////////////////////////////////

        //! \brief Initialize the game.
        void initialize(int argc, char *argv[]);

        /////////////////////////////////////////////
        // I/O functions
        /////////////////////////////////////////////
};

#endif