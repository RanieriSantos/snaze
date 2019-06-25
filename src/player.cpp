#include "../include/player.h"

bool Player::valid_node(int i, int j) {
        if (i == level->currFood.index_row || j == level->currFood.index_column) {
                return true;
        }

        if (level->map.map[i][j] == WHT_SPACE) {
                // Horizontal neighbors.
                if (level->map.map[i][j - 1] == WALL && level->map.map[i][j + 1] == WHT_SPACE) {
                        return true;
                } else if (level->map.map[i][j - 1] == WHT_SPACE &&
                           level->map.map[i][j + 1] == WALL) {
                        return true;
                }

                // Vertical neighbors.
                if (level->map.map[i - 1][j] == WALL && level->map.map[i + 1][j] == WHT_SPACE) {
                        return true;
                } else if (level->map.map[i - 1][j] == WHT_SPACE &&
                           level->map.map[i + 1][j] == WALL) {
                        return true;
                }
        }

        return false;
}

void Player::cardinal_search(int i, int j, std::list<position>& currList) {
        // Find nodes in the north.
        for (int it = i - 1; it >= 0; it--) {
                position currNode;

                if (!valid_node(it, j)) {
                        if (level->map.map[it][j] == WALL) {
                                break;
                        }
                } else {
                        currNode.index_row = it;
                        currNode.index_column = j;
                        currList.push_back(currNode);
                        break;
                }
        }

        // Find nodes in the south.
        for (int it = i + 1; it < (int)level->map.map.size(); it++) {
                position currNode;

                if (!valid_node(it, j)) {
                        if (level->map.map[it][j] == WALL) {
                                break;
                        }
                } else {
                        currNode.index_row = it;
                        currNode.index_column = j;
                        currList.push_back(currNode);
                        break;
                }
        }

        // Find nodes in the east.
        for (int it = j + 1; it < (int)level->map.map[i].size(); it++) {
                position currNode;

                if (!valid_node(i, it)) {
                        if (level->map.map[i][it] == WALL) {
                                break;
                        }
                } else {
                        currNode.index_row = i;
                        currNode.index_column = it;
                        currList.push_back(currNode);
                        break;
                }
        }

        // Find nodes in the west.
        for (int it = j - 1; it >= 0; it--) {
                position currNode;

                if (!valid_node(i, it)) {
                        if (level->map.map[i][it] == WALL) {
                                break;
                        }
                } else {
                        currNode.index_row = i;
                        currNode.index_column = it;
                        currList.push_back(currNode);
                        break;
                }
        }
}

void Player::create_adj_list() {
        for (int i = 0; i < (int)level->map.map.size(); i++) {
                for (int j = 0; j < (int)level->map.map[i].size(); j++) {
                        position currNode;             // Current node.
                        std::list<position> currList;  // Current list of nodes.

                        // Check if a valid node.
                        if (valid_node(i, j)) {
                                // Insert into the current list.
                                currNode.index_row = i;
                                currNode.index_column = j;
                                currList.push_back(currNode);

                                // Find the neighboring nodes.
                                cardinal_search(i, j, currList);

                                // Each list with only two nodes is invalid. Except if has food.
                                if (currList.size() <= 2) {
                                        bool has_food = false;

                                        for (auto const& v : currList) {
                                                if ((v.index_row == level->currFood.index_row) &&
                                                    (v.index_column ==
                                                     level->currFood.index_column)) {
                                                        has_food = true;
                                                }
                                        }

                                        if (!has_food) {
                                                currList.pop_back();
                                        }
                                }
                        }

                        adj_list.push_back(currList);  // Insert into the adjacency list.
                }
        }
}

bool Player::search_path(position p) {
        // Check if food has been found.
        if ((p.index_row == level->currFood.index_row) &&
            (p.index_column == level->currFood.index_column)) {
                path.push_back(p);

                // Remove invalid nodes.
                for (auto i = no_path.begin(); i != no_path.end(); i++) {
                        path.remove(*i);
                }

                return true;  // If food has been found.
        }

        for (auto& main_nodes : adj_list) {
                bool next_visited = false;
                bool wrong_path = false;
                auto it = main_nodes.begin();

                if ((p.index_row == main_nodes.begin()->index_row) &&
                    (p.index_column == main_nodes.begin()->index_column)) {
                        while (it->index_column != 0) {
                                if (!next_visited && !wrong_path) {
                                        path.push_back(*it);
                                }
                                it++;

                                // Check if already in path.
                                for (auto const& node : path) {
                                        if ((node.index_row == it->index_row) &&
                                            (node.index_column == it->index_column)) {
                                                next_visited = true;
                                                break;
                                        } else {
                                                next_visited = false;
                                        }
                                }

                                // Check if already in the invalid path.
                                for (auto const& node : no_path) {
                                        if ((node.index_row == it->index_row) &&
                                            (node.index_column == it->index_column)) {
                                                wrong_path = true;
                                                break;
                                        } else {
                                                wrong_path = false;
                                        }
                                }

                                if (!next_visited && !wrong_path) {
                                        // Check if's a wall.
                                        if (it->index_column != 0) {
                                                if (search_path(*it)) {
                                                        return true;  // If food has been found.
                                                }
                                        } else {
                                                // Backtracking.
                                                no_path.push_back(*--it);
                                                path.pop_back();
                                                it++;
                                        }
                                }
                        }
                }
        }

        return false;  // If food has not been found.
}

void Player::create_path() {
        auto currSnake = level->pSnake->get_snake();  // Current snake.
        create_adj_list();                            // Create the adjacency list.
        search_path(currSnake->front());              // Search the path.
}