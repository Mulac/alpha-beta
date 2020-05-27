#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <iostream>
#include <list>

class SearchableGame {
public:
    SearchableGame() {}
    virtual bool isEnd() const = 0;
    virtual int winner() const = 0;
    virtual int makeMove(int move) = 0;
    virtual const std::list<int> legalActions() const = 0;
    virtual const int* getBoard() const = 0;

    virtual SearchableGame * clone () const = 0;

private:
};

class TicTacToe {
public:
    TicTacToe() : player(1) {}
    bool isEnd() const;
    int winner() const;
    short getPlayer() const;
    bool makeMove(int move);
    const std::list<int> legalActions() const;
    const int* getBoard() const;

private:
    short player;
    int board[9] = {};
    int magic[9] = {2, 7, 6, 9, 5, 1, 4, 3, 8};

    bool hasWon(int player) const;
};

std::ostream& operator<< (std::ostream& output, const TicTacToe& game);

#endif