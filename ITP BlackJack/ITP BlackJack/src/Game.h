#pragma once

#include "Card.h"
#include "CardHolder.h"

class Game
{
public:
	Game();

	GameState GetState() const { return State; }

	void Menu();
	void StartGame();
	void PlayGame();
	void EndGame();

private:
	std::shared_ptr<CardDeck> Deck;
	std::unique_ptr<Player> Player;
	std::unique_ptr<Dealer> Dealer;

	GameState State;
};
