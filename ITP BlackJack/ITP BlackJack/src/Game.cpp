#include "Game.h"


Game::Game()
{
	// Initialise Card Deck and card holder hands
	Deck = std::make_shared<CardDeck>();
	Player = std::make_unique<::Player>(Deck);
	Dealer = std::make_unique<::Dealer>(Deck);
	State = GAME_PLAY;
}

void Game::Menu()
{
	std::cout << "Welcome to Blackjack!" << std::endl;

}

void Game::StartGame()
{
	State = GAME_PLAY;
	// Set game wager
	Player->Bet();
	Player->PrintHand();
	Dealer->PrintHand();
	if (Player->CheckBlackJack())
	{
		State = GAME_WIN;
		std::cout << "BLACKJACK!" << std::endl;
	}
}

void Game::PlayGame()
{
	// Get Player Decision - hit or stand
	if (Player->Decision() == ACTION_HIT)
	{
		Player->Hit();

		if (Player->CheckBust())
		{
			State = GAME_LOOSE;
			return;
		}
	}
	else // ACTION_STAND
	{
		Player->Stand();

		if (Player->GetHandValue() < BLACJACK) State = GAME_LOOSE;
		else if (Player->GetHandValue() == Dealer->GetHandValue()) State = GAME_DRAW;
		else State = GAME_WIN;
		return;
	}

	// Get Dealer Decision - hit or stand
	if (Dealer->Decision() == ACTION_HIT)
	{
		Dealer->Hit();

		if (Dealer->CheckBust())
		{
			State = GAME_WIN;
			return;
		}
	}
	else // ACTION_STAND
	{
		Dealer->Stand();

		if (Dealer->GetHandValue() < BLACJACK) State = GAME_LOOSE;
		else if (Dealer->GetHandValue() == Dealer->GetHandValue()) State = GAME_DRAW;
		else State = GAME_WIN;
		return;
	}
}
	
void Game::EndGame()
{
	Player->PrintHand();
	Dealer->CardHolder::PrintHand();


	switch (State)
	{
		//Process: Player Loose
	case GAME_LOOSE:
	{
		std::cout << "You lost your bet: " << POUND(Player->GetBetAmount()) << std::endl;
	}
	break;

	//Process: Player Win
	case GAME_WIN:
	{
		int reward = Player->GetBetAmount() * 2;
		Player->GetMoneyPot() += reward;
		std::cout << "You won double your bet: " << POUND(reward) << std::endl;
	}
	break;

	//Process: Player Draw
	case GAME_DRAW:
	{
		std::cout << "Your drawed with the dealer. Your bet: " << POUND(Player->GetBetAmount()) << " has been returned" << std::endl;
	}
	break;

	default:
	{
		std::cout << "Game winnings error." << std::endl;
	}
	break;
	}
}
