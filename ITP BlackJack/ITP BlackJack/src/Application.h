#pragma once

#include "Game.h"

class Application
{
public:
	void Run();

private:
	std::unique_ptr<Game> BlackJack;

};

