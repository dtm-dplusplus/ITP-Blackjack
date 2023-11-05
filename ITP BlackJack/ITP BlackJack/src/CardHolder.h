#pragma once

#include "Card.h"
#include "Core.h"

class CardHolder
{
public:
	CardHolder(CardDeck*& _deck);

	virtual ~CardHolder() = default;

	virtual void Decision();
	void Hit();
	void Stand() const;

	std::string GetCardHolderName() const { return CardHolderName; }

	void PrintHand();
	int GetHandValue() const { return HandValue; }
	int GetHandTop() const { return HandTop; }
protected:
	std::string CardHolderName;
	int HandValue;
	int HandTop;

	Card* Hand[7];
	CardDeck* Deck;
	friend class Game;
};

class Dealer final : public CardHolder
{
public:
	Dealer(CardDeck*& _deck);

	void Decision() override;
};

class Player final : public CardHolder
{
public:
	Player(CardDeck*& _deck);

	void Decision() override;
	bool Bet();

	int GetMoneyPot() const { return MoneyPot; }

private:
	int BetAmount;
	int MoneyPot;
};





