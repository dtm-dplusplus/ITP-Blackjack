#include <iostream>
#include <iomanip>

struct Card
{
	char m_cardSuit[9]{ 0 };
	char m_cardName[6]{ 0 };
	int m_cardValue{ 0 };
};

int PlayerInput()
{
	char m_input[9]{};
	bool m_isDigit{ false };

	//Input: Player Input
	std::cin.getline(m_input, 8);
	std::cin.clear();

	//Process: Is Digit?
	for (int i{ 0 }; i < strlen(m_input); i++) { m_isDigit = isdigit(m_input[i]); }

	//Process: Return Input
	if (m_isDigit)
	{
		return atoi(m_input);
	}
	else
	{
		return -1;
	}
}
void PlayerWager(int& _money, int& _bet)
{
	bool m_validWager{ false };

	while (!m_validWager)
	{
		//Output: Money pot
		std::cout << "You have " << char(156) << _money << " in your pot" << std::endl;
		std::cout << "Place a wager: ";
		_bet = PlayerInput();

		if (_bet <= _money && _bet >= 5)
		{
			m_validWager = true;


			std::cout << std::endl;
			std::cout << "You placed a wager: " << char(156) << _bet << std::endl;
		}
		else
		{
			std::cout << "Invalid wager. Place a wager " << char(156) << "5-" << char(156) << _money << std::endl;
		}
	}
	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
}

void DeckShuffle(Card _deck[], int _decktop)
{
	Card m_temp{ 0 };
	srand(time(NULL));

	//Process: Shuffle Cards
	for (int i{ 0 }, shuffle{}; i < (_decktop + 1); i++)
	{
		shuffle = rand() % (_decktop + 1);
		m_temp = _deck[i];
		_deck[i] = _deck[shuffle];
		_deck[shuffle] = m_temp;
	}
}
void DeckStart(Card _deck[], int& _decktop)
{
	char m_cardValueName[][6]{ "Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
	char m_cardSuitName[][9]{ "Hearts", "Diamonds", "Clubs","Spades" };

	//Process: Assign deck values
	for (int suit{ 0 }, suitMin{ 0 }; suit < 4; suit++, suitMin += 13)
	{
		for (int card{ 0 }; card < 13; card++)
		{
			strcpy_s(_deck[suitMin + card].m_cardSuit, m_cardSuitName[suit]);			//Suit Name
			strcpy_s(_deck[suitMin + card].m_cardName, m_cardValueName[card]);			//Card Name

			if (card == 0) { _deck[suitMin + card].m_cardValue = 11; }				//Card Value 1-11
			if (card > 0 && card < 9) { _deck[suitMin + card].m_cardValue = card + 1; }
			if (card > 8) { _deck[suitMin + card].m_cardValue = 10; }
		}
	}

	//Process: Shuffle Deck
	DeckShuffle(_deck, _decktop);
}

void HandStart(Card _deck[], Card _hand[], int& _decktop, int& _handtop)
{
	//Process: Init First Hand
	for (int i{ 0 }; i < 2; i++)
	{
		_hand[++_handtop] = _deck[_decktop--];
	}
}
void HandValue(Card _hand[], int& _handvalue, int _handtop)
{
	//Process: Calculate Hand Value
	_handvalue = 0;
	for (int i{ 0 }; i <= _handtop; i++)
	{
		_handvalue += _hand[i].m_cardValue;
	}
}
void HandPrint(Card _hand[], int _handvalue, int _handtop, int _printtype)
{
	char handPrintContext[][40]{ "Your Hand Value: ", "Dealer Hand Value: ", "DEBUG: Dealer Hand Value: ", "Dealer Hand Value: X " };

	//Output: Hand print type
	switch (_printtype)
	{
	case 0: { std::cout << handPrintContext[0] << _handvalue << std::endl; } break;
	case 1: { std::cout << handPrintContext[1] << _handvalue << std::endl; } break;
	case 2: { std::cout << handPrintContext[2] << _handvalue << std::endl; } break;
	case 3: { std::cout << handPrintContext[3] << std::endl; } break;
	default: { std::cout << "Print Hand Error" << std::endl; } break;
	}

	//Process: Dealer hole card?
	if (_printtype == 3) { --_handtop; }

	//Output: Card name, suit, value
	for (int i{ 0 }; i <= _handtop; i++)
	{
		std::cout << "Card " << (i + 1) << ": " << _hand[i].m_cardName << " of " << _hand[i].m_cardSuit << " Value: " << _hand[i].m_cardValue << std::endl;
	}

	//Output: Dealer hole card
	if (_printtype == 3) { std::cout << "Hole Card " << (_handtop += 2) << ": X of X Value: X" << std::endl; }
}
void HandHit(Card _deck[], Card _hand[], int& _decktop, int& _handvalue, int& _handtop, int _hittype)
{
	char handPrintContext[][11]{ "Player Hit", "Dealer Hit" };

	//Output: Player/Dealer Hit
	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	switch (_hittype)
	{
	case 0: { std::cout << handPrintContext[0] << std::endl; } break;
	case 1: { std::cout << handPrintContext[1] << std::endl; } break;
	default: { std::cout << "Hit Failed" << std::endl; } break;
	}

	//Process: Set ace value
	if (_deck[_decktop].m_cardValue == 11)
	{
		if (_handvalue > 10) { _deck[_decktop].m_cardValue = 1; }
	}

	//Process: Add card to hand
	_hand[++_handtop] = _deck[_decktop--];
	if (_hittype == 0)
	{
		std::cout << "Hit Card: " << _hand[_handtop].m_cardName << " of " << _hand[_handtop].m_cardSuit << " Value: " << _deck[_decktop].m_cardValue << std::endl;
	}

	//Process: Update hand value
	HandValue(_hand, _handvalue, _handtop);
}
void HandStand(Card _hand[], int _handvalue, int _handtop, int _standtype)
{
	char m_standContext[][18]{ "You Stand", "Dealer Stands" };

	//Output: Player/Dealer Stand
	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	switch (_standtype)
	{
	case 0: { std::cout << m_standContext[0] << std::endl; } break;
	case 1: { std::cout << m_standContext[1] << std::endl; } break;
	default: { std::cout << "Print Stand Error" << std::endl; } break;
	}
	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
}

void GameRestart(int& _playgameinput, int& _money)
{
	_playgameinput = -1;
	while (_playgameinput == -1)
	{
		if (_money >= 5)
		{
			std::cout << "Enter 1 to Play Again or 2 to Quit Game" << std::endl;
			_playgameinput = PlayerInput();
		}
		else
		{
			_playgameinput = 2;
		}
		std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;

		if (!(_playgameinput == 1 || _playgameinput == 2)) { _playgameinput = -1; }

		switch (_playgameinput)
		{
		case 1: { std::cout << "Game Restarting" << std::endl; } break;
		case 2: { std::cout << "Game Closing" << std::endl; } break;
		default: {std::cout << "Invalid Input. Press enter to try again" << std::endl; } break;
		}
	}
}
void GameResult(int& _money, int& _bet, int _gamestate)
{
	switch (_gamestate)
	{
		//Process: Player Loose
	case 0:
	{
		_money -= _bet;
		std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
		std::cout << "You lost your bet: " << char(156) << _bet << std::endl;
		std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	}
	break;

	//Process: Player Win
	case 1:
	{
		_money += (_bet * 2);
		std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
		std::cout << "You won double your bet: " << char(156) << (_bet * 2) << std::endl;
		std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	}
	break;

	//Process: Player Draw
	case 2:
	{
		std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
		std::cout << "Your bet of " << char(156) << _bet << " has been returned" << std::endl;
		std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	}
	break;

	default:
	{
		std::cout << "Game winnings error." << std::endl;
	}
	break;
	}

	std::cout << "Your Pot value: " << char(156) << _money << std::endl;
	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	if (_money < 5)
	{
		std::cout << "You are broke! Less than " << char(156) << "5 in your pot" << std::endl;
	}
}
void GameState(int& _gamestate, int _statetype, int _playerhandvalue, int _playertop, int _dealerhandvalue, int _dealertop)
{
	switch (_statetype)
	{
		//Process: Player/Dealer Bust?
	case 0:
	{
		if (_playerhandvalue > 21)
		{
			_gamestate = 0;
			std::cout << "Your bust!" << std::endl;
			std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
		}
		else
		{
			if (_dealerhandvalue > 21)
			{
				_gamestate = 1;
				std::cout << "Showdown! Dealer bust" << std::endl;
				std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
			}
		}
	}
	break;

	//Process: Player Stand Result
	case 1:
	{
		if (_playerhandvalue > _dealerhandvalue)
		{
			_gamestate = 1;
			std::cout << "Your hand is stronger than the dealers" << std::endl;
		}
		else
		{
			if (_playerhandvalue == _dealerhandvalue)
			{
				_gamestate = 2;
				std::cout << "You draw with Dealer" << std::endl;
			}
			else
			{
				_gamestate = 0;
				std::cout << "Dealers hand is stronger than yours" << std::endl;
				if (_dealerhandvalue == 21) { std::cout << "Blackjack! Dealer wins" << std::endl; }
			}
		}
		std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	}
	break;

	//Process: Player Hand = Blackjack?
	case 2:
	{
		if (_playertop == 1 && _playerhandvalue == 21)
		{
			if (_dealertop = 1 && _dealerhandvalue == 21)
			{
				_gamestate = 2;
				std::cout << "Dealer & Player drew Blackjack!" << std::endl;
			}
			else
			{
				_gamestate = 1;
				std::cout << "You have Blackjack!" << std::endl;
			}
		}
	}
	break;
	}
}
void Game(int& _money, int& _bet, int _debug)
{
	int  m_gameState{ -1 }, m_hitOrStandInput{ -1 }, m_deckTop{ 51 }, m_playerTop{ -1 }, m_playerHandValue{ 0 }, m_dealerTop{ -1 }, m_dealerHandValue{ 0 };
	Card m_deck[52]{ 0 }, m_playerHand[11]{ 0 }, m_dealerHand[11]{ 0 };

	//Process: Initialise Deck of Cards
	DeckStart(m_deck, m_deckTop);

	//Process: Initialise Player & Dealer hand + values
	HandStart(m_deck, m_playerHand, m_deckTop, m_playerTop);
	HandStart(m_deck, m_dealerHand, m_deckTop, m_dealerTop);
	HandValue(m_playerHand, m_playerHandValue, m_playerTop);
	HandValue(m_dealerHand, m_dealerHandValue, m_dealerTop);

	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	std::cout << "GAME START" << std::endl;
	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;

	//Process: Set game wager
	PlayerWager(_money, _bet);

	//Process: Game Loop
	while (m_gameState == -1)
	{
		//Process: Player Hand = Blackjack?
		GameState(m_gameState, 2, m_playerHandValue, m_playerTop, m_dealerHandValue, m_dealerTop);

		//Output: Player + Dealer Hand
		if (m_gameState == -1)
		{
			HandPrint(m_playerHand, m_playerHandValue, m_playerTop, 0);
			std::cout << std::endl;

			//Process: Output Debug Hand or Hole Hand?
			if (_debug == 1)
			{
				HandPrint(m_dealerHand, m_dealerHandValue, m_dealerTop, 2);
			}
			else
			{
				HandPrint(m_dealerHand, 0, m_dealerTop, 3);
			}
		}

		//Proccess: Player Hit or Stand?
		if (m_gameState == -1)
		{
			std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
			if (_debug == 1) { std::cout << "DEBUG: Next card in Deck: " << m_deck[m_deckTop].m_cardName << " of " << m_deck[m_deckTop].m_cardSuit << " Value: " << m_deck[m_deckTop].m_cardValue << std::endl; }

			m_hitOrStandInput = -1;
			while (!(m_hitOrStandInput == 1 || m_hitOrStandInput == 2))
			{
				std::cout << "Enter 1 to Hit or 2 to stand" << std::endl;
				m_hitOrStandInput = PlayerInput();

				switch (m_hitOrStandInput)
				{
					//Process: Player Hit
				case 1:
				{
					HandHit(m_deck, m_playerHand, m_deckTop, m_playerHandValue, m_playerTop, 0);

					//Process: Player Bust?
					GameState(m_gameState, 0, m_playerHandValue, m_playerTop, m_dealerHandValue, m_dealerTop);

					//Process: If Bust = False, Player Hand = 21?
					if (m_gameState == -1) { GameState(m_gameState, 2, m_playerHandValue, m_playerTop, m_dealerHandValue, m_dealerTop); }
				}
				break;

				//Process: Player Stand
				case 2:
				{
					if (m_playerHandValue < 12)
					{
						m_hitOrStandInput = -1;
						std::cout << "You cannot stand on less than 12. You must hit" << std::endl;
					}
					else
					{
						HandStand(m_playerHand, m_playerHandValue, m_playerTop, 0);
					}
				}
				break;

				default:
				{
					m_hitOrStandInput = -1;
					std::cout << "Invalid Input. Valid Input: 1-2" << std::endl;
					std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
				}
				break;
				}
			}
		}

		//Proccess: Dealer Actions
		if (m_playerHandValue <= 21)
		{
			//Process: Dealer Hit
			if (m_dealerHandValue < 17)
			{
				HandHit(m_deck, m_dealerHand, m_deckTop, m_dealerHandValue, m_dealerTop, 1);

				//Process: Dealer Bust?
				GameState(m_gameState, 0, m_playerHandValue, m_playerTop, m_dealerHandValue, m_dealerTop);
			}
			//Process: Dealer Stand
			else
			{
				HandStand(m_dealerHand, m_dealerHandValue, m_dealerTop, 1);
			}
		}

		//Proccess: If Player Stand, Result?
		if (m_hitOrStandInput == 2) { GameState(m_gameState, 1, m_playerHandValue, m_playerTop, m_dealerHandValue, m_dealerTop); }
	}

	//Output: Final Hands
	HandPrint(m_playerHand, m_playerHandValue, m_playerTop, 0);
	std::cout << std::endl;
	HandPrint(m_dealerHand, m_dealerHandValue, m_dealerTop, 1);

	//Process: Calculate Game Results
	GameResult(_money, _bet, m_gameState);
}

void MenuRules()
{
	//Output: Game Rules
	std::cout << "GAME RULES" << std::endl;
	std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
	std::cout << "The aim of Blackjack is to accumulate a higher point total than the dealer, without going over 21. " << std::endl;
	std::cout << "You calculate your score by adding the values of your individual cards. " << std::endl << std::endl;
	std::cout << "Cards 2-10 are worth their face value, J-Q-K are worth 10-points." << std::endl;
	std::cout << "Ace is worth 1 or 11 points dependant on the players hand value." << std::endl << std::endl;
	std::cout << "A blackjack hand beats any other hand." << std::endl;
	std::cout << "The best opening hand is A + 10-point card. This is called a Blackjack. " << std::endl;
	std::cout << "The player holding this automatically wins unless the dealer also has a Blackjack." << std::endl << std::endl;
	std::cout << "If a player and the dealer each have a blackjack, the result is a draw." << std::endl;
	std::cout << "If the dealer has a blackjack, all players not holding a blackjack lose. " << std::endl << std::endl;
	std::cout << "After the cards have been dealt, the game goes on with each player action." << std::endl;
	std::cout << "1. The player can keep his hand (stand) when hand is worth more than 12." << std::endl;
	std::cout << "	a. if the players hand beats the dealers, the player wins, unless the dealer has blackjack." << std::endl;
	std::cout << "2. Takes cards one at a time from the deck (hit):" << std::endl;
	std::cout << "	a. until the player judges their hand is strong enough to go against the dealer's hand." << std::endl;
	std::cout << "	b. until it goes over 21, in which case the player immediately loses (busts)." << std::endl << std::endl;
	std::cout << "It is the dealer's turn When all players have finished their actions. The dealer shows the hole card. " << std::endl;
	std::cout << "1. The dealer must hit if the value of the hand is lower than 17, otherwise the dealer will stand. " << std::endl;
	std::cout << "2. Showdown If the dealer goes bust, the player wins." << std::endl;
}
void Menu()
{
	char m_options[][20]{ "Start Game", "Game Rules","Debug Game", "Exit Game" };
	int m_menuOptionInput{ -1 }, m_money{ 100 }, m_bet{};

	while (m_menuOptionInput == -1)
	{
		if (m_money < 5)
		{
			m_menuOptionInput = 4;
		}
		else
		{
			std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
			std::cout << "Welcome to Blackjack" << std::endl;
			std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
			std::cout << "Enter 1-4 to Select an option" << std::endl;

			//Output: Menu options
			for (int i{ 0 }; i < 4; i++)
			{
				std::cout << (i + 1) << ". " << m_options[i] << std::endl;
			}
			std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
			m_menuOptionInput = PlayerInput();
			std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
		}

		switch (m_menuOptionInput)
		{
			//Process: Start Game
		case 1:
		{
			while (m_menuOptionInput == 1)
			{
				Game(m_money, m_bet, 0);
				GameRestart(m_menuOptionInput, m_money);
			}
		}
		break;

		//Process: Game Rules
		case 2:
		{
			MenuRules();
			m_menuOptionInput = -1;
		}
		break;

		//Process: Debug Game
		case 3:
		{
			m_menuOptionInput = 1;
			std::cout << "Entering Debug Mode..." << std::endl;
			while (m_menuOptionInput == 1)
			{
				Game(m_money, m_bet, 1);
				GameRestart(m_menuOptionInput, m_money);
			}
		}
		break;

		//Process: Exit Game
		case 4:
		{
			std::cout << "Game Closing" << std::endl;
		}
		break;

		//Process: Reset Invalid input
		default:
		{
			m_menuOptionInput = -1;
			std::cout << "Invalid Input. Enter Option 1-4" << std::endl;
		}
		break;
		}
	}
}

int main()
{
	Menu();
	return 0;
}