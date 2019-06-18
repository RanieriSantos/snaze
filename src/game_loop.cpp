#include "../include/game_loop.h"

//funtion used to read a file with the maps used on Snaze
void GameLoop::read_file(){

    std::ifstream file;
    file.exceptions (std::ifstream::badbit);

    std::cout << ">> Trying to open input file (" << inputFile << ")";

}