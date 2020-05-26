#ifndef MINI_MAX_WITH_PRUNING_H_
#define MINI_MAX_WITH_PRUNING_H_

#include <vector>
#include <utility>

struct ActionValue
{
  int cell, value;
};

struct State
{
  int x, y;
};

struct Action
{
  int x, value;
};


class SearchableGame
{
public:
  virtual std::vector<std::pair<State, Action>> successorStates(const State& state) const = 0;
  virtual bool terminalState(const State& state) const = 0;
  virtual int getUtility(const State& state) const = 0;

  Action AlphaBetaSearch(const State& state) const;

private:
  int maxValue(const State& state, int alpha, int beta) const;
  int minValue(const State& state, int alpha, int beta) const;
};

class Game : public SearchableGame
{
public:
  Game() : d(1) {}
  std::vector<std::pair<State, Action>> successorStates(const State& state) const override {
    std::vector<std::pair<State, Action>> list;
    list.push_back(std::pair<State, Action>(State(), Action()));
    return list;
  }
  bool terminalState(const State& state) const override { return true; }
  int getUtility(const State& state) const override { return 1; }

private:
  int d;

};

class AlphaBetaSearch
{
public:
  AlphaBetaSearch(const Game& game) : game(game) {}

private:
  Game game;
};



const Action& alphaBetaSearch(const int* board, int boardSize);

#endif