#include "tictactoe.hpp"
#include <algorithm>

const int* TicTacToe::getBoard() const {
    return board;
}

int TicTacToe::winner() const {
    return (hasWon(1)) ? 1 : (hasWon(-1)) ? -1 : 0;
}

bool TicTacToe::isTerminal() const {
    return (legalActions().empty() || winner()) ? true : false;
}

short TicTacToe::getPlayer() const{
    return player;
}

double TicTacToe::utility() const {
    return (getPlayer() == winner()) ? 1 : (!winner()) ? 0 : -1;
}

const std::list<Action> TicTacToe::legalActions() const {
    std::list<Action> actions;
    const int* board = getBoard();
    for (int i=0; i<9; i++){
        if (!board[i]) {
            Action a = std::make_shared<TTTAction>(i);
            actions.push_back(a);
        }
    }
    return actions;
}

bool TicTacToe::makeMove(Action move) {
    std::shared_ptr<TTTAction> action = std::dynamic_pointer_cast<TTTAction>(move);
    // Check move is legal
    bool legal = false;
    for (auto a : legalActions()) {
        std::shared_ptr<TTTAction> legalAction = std::dynamic_pointer_cast<TTTAction>(a);
        if (legalAction->move == action->move) {
            legal = true;
            break;
        }
    }

    if (!legal)
        return false;
        
    // Make move and switch player
    board[action->move] = player;
    player *= -1;
    return true;
}

bool TicTacToe::hasWon(short player) const {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            for (int k = 0; k < 9; k++)
                if (i != j && i != k && j != k)
                    if (board[i] == player && board[j] == player && board[k] == player)
                        if (magic[i] + magic[j] + magic[k] == 15)
                            return true;
    return false;
}

char toSym(short player) {
    return (player > 0) ? 'X' : (player < 0) ? 'O' : '-';
}

std::ostream& operator<< (std::ostream& output, TicTacToe& game){
    const int* board = game.getBoard();
    
    output << toSym(board[0]) << ' ' << toSym(board[1]) << ' ' << toSym(board[2]) << std::endl;
    output << toSym(board[3]) << ' ' << toSym(board[4]) << ' ' << toSym(board[5]) << std::endl;
    output << toSym(board[6]) << ' ' << toSym(board[7]) << ' ' << toSym(board[8]) << std::endl;

    return output;
}

int main(int argc, char ** argv){
    TicTacToe game;

    while (!game.isTerminal()){
        Action move;

        std::cout << "player: " << game.getPlayer() << std::endl;

        if (game.getPlayer() < 0){
            int input;
            std::cin >> input;
            move = std::make_shared<TTTAction>(input);
        }
        else {
            move = alphabeta(game.clone());
        }

        while (!game.makeMove(move)){
            std::cout << "[ERROR] " << move << " not legal";
            return -1;
        }

        std::cout << game << std::endl;
    }
}