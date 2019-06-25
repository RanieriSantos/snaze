#include <../include/snazeGame.h>

int main(int argc, char* argv[]) {
        GameLoop game;

        game.initialize(argc, argv);

        game.test();

        // Initial message.
        game.render();

        // Game Loop
        while (!game.game_over()) {
                game.process_events();
                game.update();
                game.render();
        }

        return 0;
}