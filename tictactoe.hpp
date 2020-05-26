#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <iostream>

class TicTacToe {
public:
    TicTacToe() : player(1) {}
    bool isEnd() const;
    int winner() const;
    int makeMove(int move);
    const int* legalActions() const;
    const int* getBoard() const;

private:
    short player;
    int board[9] = {};

    
};

std::ostream& operator<< (std::ostream& output, const TicTacToe& game);

#endif