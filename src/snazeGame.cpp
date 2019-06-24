#include "../include/snazeGame.h"
#include "../include/basicStructures.h"
#include "../include/output.h"

// funtion used to read a file with the maps used on Snaze
int GameLoop::read_file(int argc, char *argv[]) {
        std::ifstream file;                      // File with maps.
        file.exceptions(std::ifstream::badbit);  // To verify if file opened successfully.
        const short int MAX_SIZE = 100;          // Max size to rows and columns.

        // If the path to the playlist has not been entered.
        if (argc < 2) {
                std::cerr << ">> Input file not entered. Using default playlist...\n";
                inputFile = "data/playlist_0.dat";  // Default playlist.
        } else {
                inputFile = argv[1];  // User playlist.
        }

        std::cout << ">> Trying to open input file (" << inputFile << ")... ";
        file.open(inputFile);  // Opening file in reading mode

        // Checking if the file opened successfully
        if (!file) {
                std::cerr << "\n\033[0;31m >> Error: opening/reading file\033[0m\n";
                exit(EXIT_FAILURE);
        }

        std::cout << "File opened successfully! \n";
        std::cout << ">> Processing data ... \n";

        while (!file.eof()) {
                Level currMap;  // Save each map temporarilly.

                int auxRow, auxCol;

                // Number of rows and columns of the map;
                file >> auxRow >> auxCol;
                currMap.set_mapRow(auxRow);
                currMap.set_mapCol(auxCol);
                file.ignore();

                // Checking if they're zero or greather than the maximun size (MAX_SIZE).
                if ((currMap.get_mapRow() <= 0) || (currMap.get_mapColumn() <= 0) ||
                    (currMap.get_mapRow() > MAX_SIZE) || (currMap.get_mapColumn() > MAX_SIZE)) {
                        std::cerr << "\n\033[0;31m >> Error: Unacceptable number of "
                                     "rows/columns\033[0m\n";
                        exit(EXIT_FAILURE);
                }

                // Prepare to receive the map.
                short i = 0;                                   // Number of the current row.
                std::string line;                              // Current row itself.
                currMap.map.map.resize(currMap.get_mapRow());  // Prepare the matrix;

                // Read the map.
                while ((std::getline(file, line)) && (i < currMap.get_mapRow())) {
                        short j = 0;

                        while (j < (short)line.size() && (j < currMap.get_mapColumn())) {
                                if (line[j] == WHT_SPACE) {  // White space.
                                        currMap.map.map[i].push_back(WHT_SPACE);
                                } else if (line[j] == SPAWN) {  // Spawn.
                                        currMap.map.map[i].push_back(SPAWN);
                                        currMap.map.spawn.index_row = i;
                                        currMap.map.spawn.index_column = j;
                                } else if (line[j] == INV_WALL) {  // Invisible wall.
                                        currMap.map.map[i].push_back(INV_WALL);
                                } else {  // Common wall.
                                        currMap.map.map[i].push_back(WALL);
                                }
                                j++;
                        }

                        i++;
                }

                vec_maps.push(currMap);   // Add to the queue of maps.
                currMap.map.print_map();  // #DEBUG
        }

        return EXIT_SUCCESS;
}

// function that will initialize the game, it'll save maps from a file on an queue that will be used
// on snaze
void GameLoop::initialize(int argc, char *argv[]) {
        if (read_file(argc, argv) == EXIT_FAILURE) {
                exit(EXIT_FAILURE);
        }

        init_msg();  // Print welcome message.
}

void GameLoop::render(){
        //jumping line
        std::cout << std::endl;

        //printing Score, number of currLevel and lifes remaining
        std::cout << "SCORE: "<< score <<"          "<<" LEVEL: "<< currLevel << "          \u2764 :" << snake.get_lifes()<< "\n";

        //print map with snake
        std::ostringstream data;

        for (int i = 0; i < vec_maps.front().map.num_row; i++) {
                for (int j = 0; j < vec_maps.front().map.num_col; j++) {

                        bool is_there = false;
                        
                        // position aux
                        position verifies;
                        verifies.index_row = i;
                        verifies.index_column = j;

                        //verifies if it's snake
                        for (auto value : vec_maps.front().pSnake->get_snake()){
                                if (value == verifies) {
                                        data<< std::setw(1) << "\u25A0"<<" ";
                                        is_there = true;
                                        break;
                                }
                        }
                        
                        //verifies if it's food
                        if (verifies == vec_maps.front().currFood){
                                data<< std::setw(1) << "🐁";
                                is_there = true;
                        }

                        //If is neither food nor snake prints map
                        if (!is_there){
                                data << std::setw(1) << vec_maps.front().map.map[i][j] << " ";
                        }
                        
                        
                }
                data << '\n';
        }

        std::cout << data.str() << std::endl;
        

}

void GameLoop::test() {
        snake.set_snake(9, 3);
        vec_maps.front().set_snake(&snake);
        // generates food
        vec_maps.front().generate_food_position();

        std::cout << "i = " << vec_maps.front().currFood.index_row << "\n"
                  << "j = " << vec_maps.front().currFood.index_column << "\n";
}

