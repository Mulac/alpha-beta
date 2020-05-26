#ifndef TICTACTOE_H_
#define TICTACTOE_H_

class TicTacToe {
public:
    TicTacToe() : player(1) {}
    bool isEnd() const;
    int winner() const;
    int makeMove(int x, int y);
    const int* getBoard() const;

private:
    short player;
    int board[9] = {};
};

#endif