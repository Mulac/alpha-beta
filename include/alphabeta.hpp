#include <utility>
#include <memory>
#include <list>

struct GameAction {
    virtual ~GameAction() = default;
};
typedef std::shared_ptr<GameAction> Action;

class SearchableGame {
public:
    typedef std::shared_ptr<SearchableGame> Game;
    virtual ~SearchableGame() {}

    virtual Game create() const = 0;
    virtual Game clone() const = 0;

    virtual const std::list<Action> legalActions() const = 0;
    virtual bool isTerminal() const = 0;
    virtual double utility() const = 0;
    virtual bool makeMove(Action move) = 0;
};

Action alphabeta(SearchableGame::Game game, int depth);