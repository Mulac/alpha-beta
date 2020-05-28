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

    bool isTerminal() const;
    double utility() const;
    int winner() const;
    short getPlayer() const;
    bool makeMove(Action move);
    const std::list<Action> legalActions() const;
    const int* getBoard() const;

private:
    short player;
    int board[9] = {};
    int magic[9] = {2, 7, 6, 9, 5, 1, 4, 3, 8};

    bool hasWon(short player) const;
};

std::ostream& operator<< (std::ostream& output, TicTacToe& game);

#endif