#include "../include/snazeGame.h"
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
                grid currMap;  // Save each map temporarilly.

                // Number of rows and columns of the map;
                file >> currMap.num_row >> currMap.num_col;
                file.ignore();

                // Checking if they're zero or greather than the maximun size (MAX_SIZE).
                if ((currMap.num_row <= 0) || (currMap.num_col <= 0) ||
                    (currMap.num_row > MAX_SIZE) || (currMap.num_col > MAX_SIZE)) {
                        std::cerr << "\n\033[0;31m >> Error: Unacceptable number of "
                                     "rows/columns\033[0m\n";
                        exit(EXIT_FAILURE);
                }

                // Prepare to receive the map.
                short i = 0;                          // Number of the current row.
                std::string line;                     // Current row itself.
                currMap.map.resize(currMap.num_row);  // Prepare the matrix;

                // Read the map.
                while ((std::getline(file, line)) && (i < currMap.num_row)) {
                        short j = 0;

                        while (j < (short)line.size() && (j < currMap.num_col)) {
                                if (line[j] == WHT_SPACE) {  // White space.
                                        currMap.map[i].push_back(WHT_SPACE);
                                } else if (line[j] == SPAWN) {  // Spawn.
                                        currMap.map[i].push_back(SPAWN);
                                        currMap.spawn.index_row = i;
                                        currMap.spawn.index_column = j;
                                } else if (line[j] == INV_WALL) {  // Invisible wall.
                                        currMap.map[i].push_back(INV_WALL);
                                } else {  // Common wall.
                                        currMap.map[i].push_back(WALL);
                                }
                                j++;
                        }

                        i++;
                }

                

                vec_maps.push(currMap);  // Add to the queue of maps.
                currMap.print_map();     // #DEBUG

        }

        return EXIT_SUCCESS;
}

//function that will initialize the game, it'll save maps from a file on an queue that will be used on snaze
void GameLoop::initialize(int argc, char *argv[]) {
        if (read_file(argc, argv) == EXIT_FAILURE) {
                exit(EXIT_FAILURE);
        }

        init_msg();  // Print welcome message.
}
