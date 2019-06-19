#include "../include/game_loop.h"

//funtion used to read a file with the maps used on Snaze
void GameLoop::read_file(){

    std::ifstream file;
    file.exceptions (std::ifstream::badbit);

    std::cout << ">> Trying to open input file (" << inputFile << ") ... ";
    file.open(inputFile); //Opening file in reading mode

    //Checking if the file opened successfully
    if(!file){
        std::cerr << "\n\033[0;31m >> Error: opening/reading file\033[0m\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "File opened successfully! \n";
    std::cout << ">> Processing data ... \n";

    //Queue of grid that's going to safe all maps of the file
    std::queue <grid> vec_maps;

    
}