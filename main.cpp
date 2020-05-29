#include "include/tictactoe.hpp"
#include <chrono>

int main(int argc, char ** argv){
    TicTacToe game;

    while (!game.isTerminal()){
        Action move;

        std::cout << "player: " << game.getPlayer() << std::endl;

        if (game.getPlayer() < 0){
            int input;
            std::cin >> input;
            move = std::make_shared<TTTAction>(input);
        }
        else {
            auto start = std::chrono::high_resolution_clock::now();
            move = alphabeta(game.clone(), -1);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            std::cout << elapsed.count() << std::endl;
        }

        while (!game.makeMove(move)){
            std::cout << "[ERROR] " << move << " not legal";
            return -1;
        }

        std::cout << game << std::endl;
    }
}
