#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <fstream> // Stream class to read and write from/to files - using std::ifstream
#include <iostream> // std::cout, std::cin
#include <vector> //std::vector

class GameLoop{

    private:

        std::string inputFile;
        
        struct grid {
            int nRow, nCol;
            std::vector<std::vector<int>> map;
        };

    public:

        /////////////////////////////////////////////
        // Client functions
        /////////////////////////////////////////////

        //! Initialize the game
        void initialize (int argc, char *argv);


        /////////////////////////////////////////////
        // I/O functions
        /////////////////////////////////////////////

        /*!@brief Read file with snaze maps
         */
        void read_file();

};

#endif