#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <iostream>
#include <list>

#include "alphabeta.hpp"

struct TTTAction : public GameAction {
    int move;
    TTTAction(int m) : move(m) {}
};

class TicTacToe : public SearchableGame { 
public:
    TicTacToe() : player(1) {}
    virtual ~TicTacToe() {}

    Game create() const {
        return Game(new TicTacToe());
    }
    Game clone() const {
        return Game(new TicTacToe(*this));
    }

    bool makeMove(Action move);
    const std::list<Action> legalActions() const;
    bool isTerminal() const;
    double utility() const;

    const int* getBoard() const;
    short getPlayer() const;
    int winner() const;

private:
    short player;
    int board[9] = {};
    int magic[9] = {2, 7, 6, 9, 5, 1, 4, 3, 8};

    bool hasWon(short player) const;
};

std::ostream& operator<< (std::ostream& output, const TicTacToe& game);

#endif