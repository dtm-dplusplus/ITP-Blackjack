#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#define POUND(m) char(156) << m
#define INVALID -1
#define MIN_BET 5
#define BLACJACK 21

inline int PlayerInput()
{
	std::string input;

	std::cin >> input;
	std::cin.clear();

	bool isDigit = false;

	for (char c : input) isDigit = isdigit(c);

	if (isDigit) return atoi(input.c_str());
	return -1;
}

enum PlayerAction
{
	ACTION_HIT,
	ACTION_STAND, 
	ACTION_BET
};

enum GameState
{
	GAME_LOOSE,
	GAME_WIN,
	GAME_DRAW,
	GAME_PLAY
};