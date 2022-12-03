#include <iostream>
#include <cstdlib>
#include <ctime>
#include "04_game.h"

Game::Game(const std::vector<std::string>& names)
{
    for (auto name = names.begin(); name != names.end(); ++name)
    {
        players.push_back(Player(*name));
    }

    srand(time(0));
    deck.populate();
    deck.shuffle();
}

Game::~Game()
{}

void Game::play()
{
    // сдать по 2 карты
    for (int i = 0; i < 2; ++i) {
        for (auto player = players.begin(); player != players.end(); ++player) {
            deck.deal(*player);
        }
        deck.deal(house);
    }
    // спрятать первую карту дилера
    house.flip_first_card();
    // открыть игроков
    for (auto player = players.begin(); player != players.end(); ++player) {
            std::cout << *player << std::endl;
    }
    std::cout << house << std::endl;

    // раздать игрокам дополнительные карты
    for (auto player = players.begin(); player != players.end(); ++player) {
            deck.additional_cards(*player);
    }

    // показать первую карту дилера
    house.flip_first_card();
    std::cout << std::endl << house << std::endl;
    // сдать дилеру дополнительную карту
    deck.additional_cards(house);

    if (house.is_boosted()) {
        for (auto player = players.begin(); player != players.end(); ++player) {
            if (!player->is_boosted()) {
                player->win();
            }
        }
    } else {
        for (auto player = players.begin(); player != players.end(); ++player) {
            if (!player->is_boosted()) {
                if (player->get_value() > house.get_value()) {
                    player->win();
                } else if (player->get_value() < house.get_value()) {
                    player->lose();
                } else {
                    player->push();
                }
            }
        }
    }

    for (auto player = players.begin(); player != players.end(); ++player) {
        player->clear();
    }
    house.clear();
}