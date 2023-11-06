#include "CardHolder.h"


CardHolder::CardHolder(std::shared_ptr<CardDeck> _deck) : HandValue{ 0 }, HandTop{ -1 }, Deck(_deck)
{
	for (int i{ 0 }; i < 2; i++) Hand[++HandTop] = Deck->DrawCard();
};

int CardHolder::Decision()
{
	int decision;

	for (int valid{ INVALID }; valid == INVALID; )
	{
		std::cout << "1. Hit \n2. Stand" << std::endl;

		decision = PlayerInput();

		if (decision == ACTION_HIT) valid = true;
	}

	if (decision == ACTION_HIT) std::cout << CardHolderName << "Hit" << std::endl;
	else std::cout << CardHolderName << "Stand" << std::endl;

	return (PlayerAction)decision;
}

void CardHolder::Hit()
{
	Hand[++HandTop] = Deck->DrawCard();
	std::cout << CardHolderName << " new card: " << Hand[HandTop]->GetCardName()<< std::endl; 
}

void CardHolder::Stand() const
{
	std::cout << CardHolderName << " stands" << std::endl;
}

bool CardHolder::CheckBust()
{
	if (GetHandValue() > BLACJACK) return true;
	else return false;
}

bool CardHolder::CheckBlackJack()
{
	if (GetHandValue() == BLACJACK) return true;
	else return false;
}



void CardHolder::PrintHand()
{
	for (int i{ 0 }; i <= HandTop; i++) std::cout << Hand[i]->GetCardName() << std::endl;
}

int CardHolder::GetHandValue()
{
	HandValue = 0;
	for (int i{ 0 }; i <= HandTop; i++) HandValue += Hand[i]->GetValue();
	return HandValue;
}


Dealer::Dealer(std::shared_ptr<CardDeck> _deck): CardHolder(_deck)
{
	CardHolderName = "Dealer";
}

int Dealer::Decision()
{
	if (GetHandValue() < DEALER_HIT) return ACTION_HIT;
	else return ACTION_STAND;
}

void Dealer::PrintHand()
{
	std::cout << CardHolderName << " cards" << std::endl;
	for (int i{ 0 }; i < HandTop; i++) std::cout << Hand[i]->GetCardName() << std::endl;
	std::cout << "XXXXX of XXXXX" << std::endl;
}


Player::Player(std::shared_ptr<CardDeck> _deck) : CardHolder(_deck), BetAmount{0}, MoneyPot{ 100 }
{
	CardHolderName = "Player";
}

void Player::Bet()
{
	int newBetAmount;

	for (bool valid{ false }; !valid;)
	{
		std::cout << "You have " << POUND(MoneyPot) << "" << std::endl;
		std::cout << "Place a bet: " << std::endl;
		newBetAmount = PlayerInput();

		// Check Bet Input valid
		if (newBetAmount <= MoneyPot && newBetAmount >= MIN_BET) valid = true;
		else if (newBetAmount == INVALID) std::cout << "Invalid Bet" << std::endl;
		else std::cout << "You don't have enough money" << std::endl;
	}

	BetAmount = newBetAmount;
	MoneyPot -= BetAmount;
}
