#pragma once

#include "Card.h"
#include "Core.h"

#define DEALER_HIT 18

class CardHolder
{
public:
	CardHolder(std::shared_ptr<CardDeck> _deck);

	virtual ~CardHolder() = default;

	virtual int Decision();
	void Hit();

	void Stand() const;

	bool CheckBust();
	bool CheckBlackJack();


	std::string GetCardHolderName() const { return CardHolderName; }

	virtual void PrintHand();

	int GetHandValue();

protected:
	std::string CardHolderName;
	int HandValue;
	int HandTop;

	Card* Hand[7];
	std::shared_ptr<CardDeck> Deck;

	friend class Game;
};

class Dealer final : public CardHolder
{
public:
	Dealer(std::shared_ptr<CardDeck> _deck);

	int Decision() override;
	void PrintHand() override;

private:
	bool showHand;
};

class Player final : public CardHolder
{
public:
	Player(std::shared_ptr<CardDeck> _deck);

	void Bet();
	int GetBetAmount() const { return BetAmount; }

	int GetMoneyPot() const { return MoneyPot; }
	int& GetMoneyPot() { return MoneyPot; }

private:
	int BetAmount;
	int MoneyPot;
};





