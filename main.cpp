#include <iostream>
#include "core/game.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    // region debug

    std::cout << "Insert number of players " << std::endl;
    int n_pl = 0;
    std::cin >> n_pl;
    std::vector<Player*> players;
    for(int i = 0; i < n_pl; i++) {
        std::cout << "Name: " << std::endl;
        std::string name;
        std::cin >> name;

        auto player = new Player(name);
        players.push_back(player);
    }

    auto game = new Game(players);

    for (auto p : players) {
        std::cout << "player " << p->getName() << std::endl;
        p->printCards();
        std::cout << std::endl;
    }

    // endregion debug
    return 0;
}
