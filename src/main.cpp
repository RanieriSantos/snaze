#include <../include/snazeGame.h>

int main(int argc, char* argv[]) {
        GameLoop game;

        game.initialize(argc, argv);

        game.test();
       

        game.render();

        
        return 0;

        // Simulation game;

        // // Set up simulation.
        // game.initialize(argc, argv);

        // // Initial message.
        // game.render();

        // // Game Loop
        // while (!game.game_over()) {
        //         game.process_events(); // Verificar REGRAS.
        //         game.update();         // Atualizar o board.
        //         game.render();         // Exibir o board
        // }

        // return 0;
}