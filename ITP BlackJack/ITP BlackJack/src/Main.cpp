#include "Game.h"
//
//int PlayerInput()
//{
//	char m_input[9]{};
//	bool m_isDigit{ false };
//
//	//Input: Player Input
//	std::cin.getline(m_input, 8);
//	std::cin.clear();
//
//	//Process: Is Digit?
//	for (int i{ 0 }; i < strlen(m_input); i++) { m_isDigit = isdigit(m_input[i]); }
//
//	//Process: Return Input
//	if (m_isDigit)
//	{
//		return atoi(m_input);
//	}
//	else
//	{
//		return -1;
//	}
//}

int main()
{
	auto game = std::make_unique<Game>();

	game->PlayGame();

	return 0;
}
