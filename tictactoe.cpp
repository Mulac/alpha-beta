#include "tictactoe.hpp"
#include <algorithm>

const int* TicTacToe::getBoard() const {
    return board;
}

const std::list<int> TicTacToe::legalActions() const {
    std::list<int> actions;
    const int* board = getBoard();
    for (int i=0; i<9; i++){
        if (!board[i])
            actions.push_back(i);
    }
    return actions;
}

bool TicTacToe::makeMove(int move) {
    // Check move is legal
    auto actions = legalActions();
    if (std::find(actions.begin(), actions.end(), move) == actions.end())
        return -1;
    
    // Make move and switch player
    board[move] = player;
    player *= -1;
    return 1;
}

int TicTacToe::winner() const {
    return (hasWon(1)) ? 1 : (hasWon(-1)) ? -1 : 0;
}

bool TicTacToe::hasWon(int player) const {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            for (int k = 0; k < 9; k++)
                if (i != j && i != k && j != k)
                    if (board[i] == player && board[j] == player && board[k] == player)
                        if (magic[i] + magic[j] + magic[k] == 15)
                            return true;
    return false;
}

bool TicTacToe::isEnd() const {
    return (legalActions().empty() || winner()) ? true : false;
}

short TicTacToe::getPlayer() const{
    return player;
}

char toSym(int player) {
    return (player > 0) ? 'X' : (player < 0) ? 'O' : '-';
}

std::ostream& operator<< (std::ostream& output, Game game){
    const int* board = game->getBoard();
    
    output << toSym(board[0]) << ' ' << toSym(board[1]) << ' ' << toSym(board[2]) << std::endl;
    output << toSym(board[3]) << ' ' << toSym(board[4]) << ' ' << toSym(board[5]) << std::endl;
    output << toSym(board[6]) << ' ' << toSym(board[7]) << ' ' << toSym(board[8]) << std::endl;

    return output;
}

int main(){
    TicTacToe t;
    Game game = t.create();

    while (!game->isEnd()){
        int move;

        std::cout << "player: " << game->getPlayer() << std::endl;
        std::cout << game;

        if (game->getPlayer() < 0) {
            std::cin >> move;
        }
        else {
            move = alphabeta(game);
        }

        if (!game->makeMove(move)){
            std::cout << "error";
            return 1;
        }


        std::cout << "move: " << move << std::endl;
    }
}