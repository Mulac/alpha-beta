#include "tictactoe.hpp"

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
            move = alphabeta(game.clone(), -1);
        }

        while (!game.makeMove(move)){
            std::cout << "[ERROR] " << move << " not legal";
            return -1;
        }

        std::cout << game << std::endl;
    }
}