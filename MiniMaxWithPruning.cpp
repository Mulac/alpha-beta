#include "MiniMaxWithPruning.hpp"
#include "tictactoe.hpp"

#include <limits.h>
#include <exception>

int main()
{
  Game game();
  return 0;
}


Action SearchableGame::AlphaBetaSearch(const State& state) const
{
  int v = maxValue(state, INT_MIN, INT_MAX);

  auto successors = successorStates(state);
  for (auto successor : successors)
  {
    if (successor.second.value == v)
      return successor.second;
  }

  throw std::exception();
}

int SearchableGame::maxValue(const State& state, int alpha, int beta) const
{

}

int SearchableGame::minValue(const State& state, int alpha, int beta) const
{

}


/* static int maxValue(const TicTacToe& game, int alpha, int beta);
static int minValue(const TicTacToe& game, int alpha, int beta);

const int alphaBetaSearch(const TicTacToe& game)
{
  TicTacToe gameCpy = TicTacToe(game);
  int v = maxValue(gameCpy, INT_MIN, INT_MAX);
  
} */



