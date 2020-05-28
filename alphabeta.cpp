#include "alphabeta.hpp"
#include <algorithm>
#include <iostream>
#include <limits>

std::pair<Action, int> negamax(Game game, double alpha, double beta) {

    if (game->isTerminal()) {
        return std::pair<Action, double>(nullptr, game->utility());
    }
    std::pair<Action, double> best(nullptr, -std::numeric_limits<double>::infinity());
    
    for (auto const& move : game->legalActions()) {
        Game imagine = game->clone();
        imagine->makeMove(move);
        
        std::pair<Action, double> result = negamax(imagine, -beta, -alpha);
        
        if (result.second*-1 > best.second) {
            best.first = move;
            best.second = result.second*-1;
        }

        alpha = std::max(alpha, best.second);
        if (alpha >= beta)
            break;
    }

    return best;
}

Action alphabeta(Game game){
    double inifiniy = std::numeric_limits<double>::infinity();
    return negamax(game, -inifiniy, inifiniy).first;
}