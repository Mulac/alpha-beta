#include <utility>
#include <memory>
#include <list>

class SearchableGame {
public:
    typedef std::shared_ptr<SearchableGame> Game;
    virtual ~SearchableGame() {}

    virtual Game create() const = 0;
    virtual Game clone() const = 0;

    virtual const std::list<int> legalActions() const = 0;
    virtual bool isTerminal() const = 0;
    virtual double utility() const = 0;
    virtual bool makeMove(int move) = 0;
};

typedef std::shared_ptr<SearchableGame> Game;

int alphabeta(Game game);