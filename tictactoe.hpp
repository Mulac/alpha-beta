#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <iostream>
#include <list>

#include "alphabeta.hpp"

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
    int utility() const;
    int winner() const;
    short getPlayer() const;
    bool makeMove(int move);
    const std::list<int> legalActions() const;
    const int* getBoard() const;

private:
    short player;
    int board[9] = {};
    int magic[9] = {2, 7, 6, 9, 5, 1, 4, 3, 8};

    bool hasWon(short player) const;
};

std::ostream& operator<< (std::ostream& output, TicTacToe& game);

#endif