#include "Game.h"

#define POUND(m) char(156) << m

Game::Game()
{
	Deck = new CardDeck();
	Player = new ::Player(Deck);
	Dealer = new ::Dealer(Deck);
}

Game::~Game()
{
	delete Deck;
	delete Player;
	delete Dealer;
}

void Game::PlayGame()
{
	std::cout << "Welcome to Blackjack!" << std::endl;
	std::cout << Player->GetCardHolderName() << " has " << POUND(Player->GetMoneyPot()) << " in their pot" << std::endl;
	


	// Set game wager

	// Initialise CardDeck of Cards

	// Initialise Player & Dealer hand + values
	//Process: Game Loop
		// Player Hand = Blackjack?

		//Output: Player + Dealer Hand

		//Proccess: Player Hit or Stand?

		//Proccess: Dealer Actions

		//Proccess: If Player Stand, Result?

	//Output: Final Hands


	//Process: Calculate Game Results & Update Money Pot
}

void Game::GameState()
{
	//switch (_statetype)
	//{
	//	//Process: Player/Dealer Bust?
	//case 0:
	//{
	//	if (_playerhandvalue > 21)
	//	{
	//		_gamestate = 0;
	//		std::cout << "Your bust!" << std::endl;
	//		std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	//	}
	//	else
	//	{
	//		if (_dealerhandvalue > 21)
	//		{
	//			_gamestate = 1;
	//			std::cout << "Showdown! Dealer bust" << std::endl;
	//			std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	//		}
	//	}
	//}
	//break;

	////Process: Player Stand Result
	//case 1:
	//{
	//	if (_playerhandvalue > _dealerhandvalue)
	//	{
	//		_gamestate = 1;
	//		std::cout << "Your hand is stronger than the dealers" << std::endl;
	//	}
	//	else
	//	{
	//		if (_playerhandvalue == _dealerhandvalue)
	//		{
	//			_gamestate = 2;
	//			std::cout << "You draw with Dealer" << std::endl;
	//		}
	//		else
	//		{
	//			_gamestate = 0;
	//			std::cout << "Dealers hand is stronger than yours" << std::endl;
	//			if (_dealerhandvalue == 21) { std::cout << "Blackjack! Dealer wins" << std::endl; }
	//		}
	//	}
	//	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	//}
	//break;

	////Process: Player Hand = Blackjack?
	//case 2:
	//{
	//	if (_playertop == 1 && _playerhandvalue == 21)
	//	{
	//		if (_dealertop = 1 && _dealerhandvalue == 21)
	//		{
	//			_gamestate = 2;
	//			std::cout << "Dealer & Player drew Blackjack!" << std::endl;
	//		}
	//		else
	//		{
	//			_gamestate = 1;
	//			std::cout << "You have Blackjack!" << std::endl;
	//		}
	//	}
	//}
	//break;
	//}
}

void Game::GameResult()
{
	//switch (_gamestate)
	//{
	//	//Process: Player Loose
	//case 0:
	//{
	//	_money -= _bet;
	//	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	//	std::cout << "You lost your bet: " << char(156) << _bet << std::endl;
	//	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	//}
	//break;

	////Process: Player Win
	//case 1:
	//{
	//	_money += (_bet * 2);
	//	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	//	std::cout << "You won double your bet: " << char(156) << (_bet * 2) << std::endl;
	//	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	//}
	//break;

	////Process: Player Draw
	//case 2:
	//{
	//	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	//	std::cout << "Your bet of " << char(156) << _bet << " has been returned" << std::endl;
	//	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	//}
	//break;

	//default:
	//{
	//	std::cout << "Game winnings error." << std::endl;
	//}
	//break;
	//}

	//std::cout << "Your Pot value: " << char(156) << _money << std::endl;
	//std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	//if (_money < 5)
	//{
	//	std::cout << "You are broke! Less than " << char(156) << "5 in your pot" << std::endl;
	//}
}
