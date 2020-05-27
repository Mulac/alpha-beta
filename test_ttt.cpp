#include "tictactoe.hpp"

int main(){
    TicTacToe game;

    game.makeMove(0);
    game.makeMove(3);
    game.makeMove(1);
    game.makeMove(4);
    game.makeMove(2);

    std::cout << game;
    std::cout << game.isEnd() << std::endl;

    for (auto &a : game.legalActions())
        std::cout << a;
}