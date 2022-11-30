#include <iostream>
#include "03_deck.h"
#include "04_game.h"

int main()
{
    std::cout << "Let's play BlackJack!\n";

    int number_of_players;
    std::cout << "How many players will play? ";
    std::cin >> number_of_players;

    std::vector<std::string> player_names;
    for (int i = 0; i < number_of_players; ++i) {
        std::cout << "Enter player's name: ";
        std::string tmp;
        std::getline(std::cin, tmp);
        player_names.push_back(tmp);
    }
    std::cout << std::endl;

    Game game(player_names);
    char answer;
    do {
        game.play();
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> answer;
    } while (answer == 'y' || answer == 'Y');
    
    return 0;
}