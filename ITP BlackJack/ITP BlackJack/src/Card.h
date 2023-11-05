#pragma once

#include "Core.h"

enum SuitEnum {
	SUIT_CLUBS,
	SUIT_DIAMONDS,
	SUIT_HEARTS,
	SUIT_SPADES
};

enum CardEnum {
	CARD_A_MAX,
	CARD_A_MIN,
	CARD_2,
	CARD_3,
	CARD_4,
	CARD_5,
	CARD_6,
	CARD_7,
	CARD_8,
	CARD_9,
	CARD_10,
	CARD_J,
	CARD_Q,
	CARD_K
};

const std::string SuitNames[]{ "Clubs", "Diamonds","Hearts","Spades" };
const std::string ValueNames[]{ "Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };

class Card
{
public:
	Card(int _card, int _suit);
	~Card(){}
	void SetID(CardEnum _id);
	CardEnum GetID() const;

	void SetName();
	std::string GetCardName() const;

	void SetValue();
	int GetValue() const;

private:
	CardEnum CardID;
	SuitEnum SuitID;
	std::string Name;
	int Value;


	friend class CardDeck;
};

class CardDeck
{
public:
	CardDeck();


	void Shuffle();
	Card* DrawCard();
	int GetDeckTop()  { return DeckTop; }

private:
	std::vector<Card*> Cards;
	int DeckTop;

};

