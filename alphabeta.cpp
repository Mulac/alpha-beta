#include "alphabeta.hpp"
#include <algorithm>
#include <iostream>
#include <limits>

std::pair<Action, int> negamax(SearchableGame::Game game, int depth, double alpha, double beta) {
    
    if (game->isTerminal() || depth == 0)
        return std::pair<Action, double>(nullptr, game->utility());
    
    std::pair<Action, double> best(nullptr, -std::numeric_limits<double>::infinity());
    
    for (auto const& move : game->legalActions()) {
        SearchableGame::Game imagine = game->clone();
        imagine->makeMove(move);
        
        std::pair<Action, double> result = negamax(imagine, depth-1, -beta, -alpha);
        
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

Action alphabeta(SearchableGame::Game game, int depth){
    double inifiniy = std::numeric_limits<double>::infinity();
    return negamax(game, depth, -inifiniy, inifiniy).first;
}