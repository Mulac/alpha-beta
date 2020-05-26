#include "tictactoe.hpp"

const int* TicTacToe::getBoard() const {
    return board;
}

char toSym(int player) {
    return (player > 0) ? 'X' : (player < 0) ? 'O' : '-';
}

std::ostream& operator<< (std::ostream& output, const TicTacToe& game){
    const int* board = game.getBoard();

    output << toSym(board[0]) << ' ' << toSym(board[1]) << ' ' << toSym(board[2]) << std::endl;
    output << toSym(board[3]) << ' ' << toSym(board[4]) << ' ' << toSym(board[5]) << std::endl;
    output << toSym(board[6]) << ' ' << toSym(board[7]) << ' ' << toSym(board[8]) << std::endl;

    return output;
}

int main(){
    TicTacToe t;
    std::cout << t << std::endl;
}