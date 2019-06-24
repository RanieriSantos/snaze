#ifndef SNAZEGAME_H
#define SNAZEGAME_H

#include <fstream>   //Stream class to read and write from/to files - using std::ifstream
#include <iomanip>   // std::setw, std::setfill
#include <iostream>  //std::cout, std::cin
#include <queue>     //std::queue
#include <sstream>   // std::ostringstream
#include <string>    //std::string, std::getline.
#include <vector>    //std::vector

#include "basicStructures.h" //position
#include "level.h"//maps

static const char SPAWN = '*';      // Snake spawn.
static const char WHT_SPACE = ' ';  // White space.
static const char WALL = '#';       // Common wall.
static const char INV_WALL = '.';   // Invisible wall.

class GameLoop {
        
       private:
                std::queue<Level> vec_maps;  // Maps from file.
                std::string inputFile; //String that saves input path
                Snake snake; //Snake that will be played

        

                //! \brief Read file with snaze maps.
                int read_file(int argc, char *argv[]);

                //! \brief Initialize snake of the map
                void init_Snake();

       public:
                /////////////////////////////////////////////
                // Client functions
                /////////////////////////////////////////////

                //! \brief Initialize the game.
                void initialize(int argc, char *argv[]);

                /////////////////////////////////////////////
                // I/O functions
                /////////////////////////////////////////////


                //Test Class
                void test();
};

#endif