#include "CardHolder.h"

CardHolder::CardHolder(CardDeck*& _deck) : HandValue{ 0 }, HandTop{ -1 }, Deck(_deck)
{
	for (int i{ 0 }; i < 2; i++) Hand[++HandTop] = Deck->DrawCard();
};


void CardHolder::Decision()
{}

void CardHolder::Hit()
{
	std::cout << CardHolderName << " hits" << std::endl;

	Hand[++HandTop] = Deck->DrawCard();
	std::cout << CardHolderName << " drawed: " << Hand[HandTop]->GetCardName()<< std::endl; PrintHand();
}

void CardHolder::Stand() const
{
	std::cout << CardHolderName << " stands" << std::endl;
}

void CardHolder::PrintHand()
{
	for(const Card* card : Hand)
	{
		std::cout << card->GetCardName() << std::endl;
	}
}

Dealer::Dealer(CardDeck*& _deck): CardHolder(_deck)
{
	CardHolderName = "Dealer";
}


void Dealer::Decision()
{

}


Player::Player(CardDeck*& _deck) : CardHolder(_deck), BetAmount{0}, MoneyPot{ 100 }
{
	CardHolderName = "Player";
}

void Player::Decision()
{
	// Hit or Stand
	
}

bool Player::Bet()
{
	// Get Bet Input
	int bet{ 0 };

	// Check Bet Input valid
	if(bet > MoneyPot)
	{
		std::cout << "You don't have enough money to bet that much" << std::endl;
		return false;
	}

	BetAmount = bet;
	return true;
}
