#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

enum SuitEnum{
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

static std::string SuitNames[]{ "Clubs", "Diamonds","Hearts","Spades" };
static std::string ValueNames[]{ "Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };

struct Card
{
	CardEnum CardID;
	SuitEnum SuitID;
	int Value;
	std::string Name;

	Card(int _card, int _suit)
	{
		CardID = static_cast<CardEnum>(_card);
		SuitID = static_cast<SuitEnum>(_suit);
		SetValue();
		SetName();
	}
	void SetID(const CardEnum _id) { CardID = _id; }
	CardEnum GetID() const { return CardID; }

	void SetValue()
	{
		if (CardID >= CARD_A_MIN && CardID <= CARD_9) { Value = CardID; }
		else if (CardID >= CARD_10) { Value = 10; }
		else { Value = 11; }
	}
	int GetValue() const { return Value; }

	void SetName()
	{
		Name = ValueNames[CardID] + " of " + SuitNames[SuitID];
	}
};



int main()
{
	// Menu();
	DeckStart();
	return 0;
}