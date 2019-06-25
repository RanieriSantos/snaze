#ifndef PLAYER_H
#define PLAYER_H

#include <list>    // std::list
#include <vector>  // std::vector

#include "../include/basicStructures.h"
#include "../include/level.h"
#include "../include/snake.h"

class Player {
       public:
        Player() : adj_list(), no_path(0), path(0){};

        ~Player(){};

        void create_path();

        // \brief Set the level reference.
        void setLevel(Level* lvl) { this->level = lvl; }

       private:
        Level* level;  // Reference to the current level.

        std::vector<std::list<position>> adj_list;  //!< Adjacency list.
        std::list<position> no_path;                //!< Invalid path.
        std::list<position> path;                   //!< Path to food.

        // \brief Verify if the position is a valid node.
        bool valid_node(int i, int j);

        // \brief Find nodes in all directions.
        void cardinal_search(int i, int j, std::list<position>& currList);

        // \brief Create the adjacency list of nodes.
        void create_adj_list();

        // \brief Search the path from snake to food.
        bool search_path(position p);
};

#endif