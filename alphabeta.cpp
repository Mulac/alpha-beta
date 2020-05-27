#include "alphabeta.hpp"
#include <iostream>

std::pair<int, int> negamax(Game game) {

    if (game->isTerminal())
        return std::pair<int, int>(NULL, game->utility());

    std::pair<int, int> best(NULL, INT32_MIN);

    for (auto const& move : game->legalActions()) {
        Game imagine = game->clone();
        imagine->makeMove(move);
        std::pair<int, int> result = negamax(imagine);

        if (result.second*-1 > best.second) {
            best.first = move;
            best.second = result.second*-1;
        }
    }

    return best;
}

int alphabeta(Game game){
    return negamax(game).first;
}