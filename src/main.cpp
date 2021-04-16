#include <iostream>

struct Player {
    int health;

    void init(Player &player) {
        player.health = 100;
    }

    void damage(Player &player) {
        player.health = 10;
    }

    void printHealth(Player player) {
        std::cout << player.health << "\n";
    }
};

int main() {
    Player player;
    player.init(player);
    player.printHealth(player);
}
