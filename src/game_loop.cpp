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

    /* EXPLANATION:
        First thing that we need to do is get the number of rows and the number of columns of the level
        After get then check if they're zeros or greater than the maximun size, if this happens we print an error mensage and terminate the game
        Otherwise we continue, and get the map.
        To get the map we'll have two for one with the number of rowns and other with the number of columns.
        Each iteration needs to check what type of configuration it is (if wall, way or start point), and safe it. (-> I'm doing this because we agreed on working with a matrix of numbers.)
        Wall = 1, Way = 0 and startpoint = 2
        This looping will continue until the file ends, that means that we don't know how many maps the file has
    */

    //file.eof() returns non-zero when the end of the file has been reached, otherwise returns zero
    while (!file.eof()) {

        //currMap will save the information of the current map and then it will be add to our queue
        grid currMap;

        file >> currMap.nRow >> currMap.nCol; //Storing number of rows and columns of the maps

        //Checking if they're zero or greather than the maximun size (100)
        if ((currMap.nRow == 0) || (currMap.nCol == 0) || (currMap.nRow > 100) || (currMap.nCol > 100)){
            std::cerr << "\n\033[0;31m >> Error: Unacceptable number of rows/columns\033[0m\n";
            exit(EXIT_FAILURE);
        }

        //for(auto i = currMap.map.begin)



    }

    
}