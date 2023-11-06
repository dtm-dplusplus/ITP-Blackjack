#include "Application.h"

void Application::Run()
{
	BlackJack.reset(new Game);

	BlackJack->Menu();
	BlackJack->StartGame();
	while (BlackJack->GetState() == GAME_PLAY) BlackJack->PlayGame();
	BlackJack->EndGame();
}
