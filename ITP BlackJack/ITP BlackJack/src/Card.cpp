#include "Card.h"


Card::Card(int _card, int _suit)
{
	CardID = static_cast<CardEnum>(_card);
	SuitID = static_cast<SuitEnum>(_suit);
	SetValue();
	SetName();
}

void Card::SetID(const CardEnum _id) { CardID = _id; }

CardEnum Card::GetID() const { return CardID; }

void Card::SetValue()
{
	if (CardID >= CARD_A_MIN && CardID <= CARD_9) { Value = CardID; }
	else if (CardID >= CARD_10) { Value = 10; }
	else { Value = 11; }
}

int Card::GetValue() const { return Value; }

void Card::SetName() { Name = ValueNames[CardID] + " of " + SuitNames[SuitID]; }
std::string Card::GetCardName() const { return Name; }


CardDeck::CardDeck()
{
	DeckTop = -1;

	// Assign deck values
	for (int s{0}; s < 4; s++, DeckTop++) { for (int c{0}; c < 13; c++) { Cards.push_back(new Card(c, s)); } }

	for (const Card* card : Cards) { std::cout << card->Name << std::endl; }
}

void CardDeck::Shuffle()
{
	srand(time(nullptr));

	//Process: Shuffle Cards
	for (int i{ 0 }; i < DeckTop + 1; i++)
	{
		const int shuffle = rand() % (DeckTop + 1);
		Card*& temp = Cards[i];
		Cards[i] = Cards[shuffle];
		Cards[shuffle] = temp;
	}
}

Card* CardDeck::DrawCard()
{
	return Cards[DeckTop--];
}
