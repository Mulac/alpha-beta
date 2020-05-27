#include <utility>

#include "tictactoe.hpp"


std::pair<int, int> negamax(TicTacToe game) {
    if (game.isEnd()) {
        int value = (game.getPlayer() == game.winner()) ? 1 : (!game.winner()) ? 0 : -1;
        return std::pair<int, int>(NULL, value);
    }

    std::pair<int, int> best(NULL, INT32_MIN);

    for (auto const& move : game.legalActions()) {
        TicTacToe imagine = game;
        imagine.makeMove(move);
        std::pair<int, int> result = negamax(imagine);

        if (result.second*-1 > best.second) {
            best.first = move;
            best.second = result.second*-1;
        }

    }

    return best;
}

int alphabeta(TicTacToe& game){
    auto dec = negamax(game);
    std::cout << "confidence: " << dec.second << std::endl;
    return dec.first;
}



int main(){
    TicTacToe game;

    while (!game.isEnd()){
        int move;

        std::cout << "player: " << game.getPlayer() << std::endl;
        std::cout << game;

        if (game.getPlayer() < 0) {
            std::cin >> move;
        }
        else {
            move = alphabeta(game);
        }

        if (!game.makeMove(move)){
            std::cout << "error";
            return 1;
        }


        std::cout << "move: " << move << std::endl;
    }
}