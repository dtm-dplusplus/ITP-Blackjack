#pragma once

#include "Card.h"
#include "CardHolder.h"

class Game
{
public:
	Game();
	~Game();

	void PlayGame();
private:
	CardDeck* Deck;
	Player* Player;
	Dealer* Dealer;

	static void GameState();
	static void GameResult();

};
