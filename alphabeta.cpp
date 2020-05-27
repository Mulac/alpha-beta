#include "alphabeta.h"
#include <iostream>

std::pair<int, int> negamax(Game _game) {
    Game game = _game->clone();
    
    if (game->isEnd()) {
        int value = (game->getPlayer() == game->winner()) ? 1 : (!game->winner()) ? 0 : -1;
        return std::pair<int, int>(NULL, value);
    }

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
    
    auto dec = negamax(game);
    
    return dec.first;
}