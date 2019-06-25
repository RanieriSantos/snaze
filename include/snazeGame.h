#ifndef SNAZEGAME_H
#define SNAZEGAME_H

#include <fstream>   //Stream class to read and write from/to files - using std::ifstream
#include <iomanip>   // std::setw, std::setfill
#include <iostream>  //std::cout, std::cin
#include <queue>     //std::queue
#include <sstream>   // std::ostringstream
#include <string>    //std::string, std::getline.
#include <vector>    //std::vector

#include "basicStructures.h"  // position
#include "level.h"            // maps
#include "player.h"           // Player

class GameLoop {
       private:
        std::queue<Level> vec_maps;  // Maps from file.
        std::string inputFile;       // String that saves input path
        Snake snake;                 // Snake that will be played
        int score;                   // player score
        int currLevel = 1;           // number of our current level

        //! \brief Read file with snaze maps.
        int read_file(int argc, char *argv[]);

        //! \brief Initialize snake of the map
        void init_Snake();

       public:
        /////////////////////////////////////////////
        // Client functions
        /////////////////////////////////////////////

        //! \brief Start the simulation reading from the input file.
        void initialize(int argc, char *argv[]);

        //! \brief Runs while extinction, stability, or maximum generation is not reached.
        // \return true if extintion, stabilty or maximum generation has been reached.
        bool game_over();

        //! Apply the rules of conway's game of life, defining which cells will live.
        void process_events();

        //! Update the petri_dish with the new generation, adding and removing cells.
        void update();

        //! Process the output (text and images).
        void render();

        // Test Class
        void test();
};

#endif