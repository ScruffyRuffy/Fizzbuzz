#include <iostream>
#include <string>
#include <vector>
#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::setUp()
{
	std::string temp;
	int  tempI;
	std::cout << "What number would you like to start at? (Recommended 1)\n";
	std::cin >> temp;
	startNum = std::stoi(temp);
	std::cout << "What number would you like to end at? (Recommended 30)\n";
	std::cin >> temp;
	endNum = std::stoi(temp);
	std::cout << "What would you like the trigger for Fizz to be?\n";
	std::cin >> temp;
	tempI = std::stoi(temp);
	triggerWords.push_back("Fizz");
	triggers.push_back(tempI);
	std::cout << "What would you like the trigger for Buzz to be?\n";
	std::cin >> temp;
	tempI = std::stoi(temp);
	triggerWords.push_back("Buzz");
	triggers.push_back(tempI);
	system("CLS");
	std::cout << "This is the state of the game so far:\nstarting at " << startNum << " and ending at " << endNum << "\nFizz triggers at multiples of " << triggers[0] << " and Buzz triggers at " << triggers[1] << std::endl;
}

void Game::setUpMultiplayer()
{
	std::cout << "How many players are there? (min 2)\n";
	int numPlayers;
	std::string name;
	std::cin >> numPlayers;
	for (int i = 1; i <= numPlayers; i++)
	{
		std::cout << "What is player " << i << "'s name" << std::endl;
		std::cin >> name;
		players.push_back(name);
	}
}

void Game::playMulti()
{
	std::string result;
	std::string guess;
	int playerNum = 0;
	bool first;
	for (int i = startNum; i <= endNum; i++)
	{
		first = true;
		system("CLS");
		result = "";
		for (int triggersI = 0; triggersI < triggers.size(); triggersI++)
		{
			if (i % triggers[triggersI] == 0)
			{
				if (!first)
				{
					result += "_";
				}
				result += triggerWords[triggersI];
				first = false;
			}
		}
		if (result == "")
		{
			result = std::to_string(i);
		}
		system("CLS");
		std::cout << players[playerNum] <<" What is the next result? (use _ for spaces)" << std::endl;
		std::cin >> guess;
		if (guess == result)
		{
			std::cout << "correct" << std::endl; 
			playerNum += 1;
			if (playerNum >= players.size()) 
			{
				playerNum = 0;
			}
		}
		else
		{
			std::cout << "incorrect it was " << result << " not " << guess << std::endl;
			players.erase(players.begin() + playerNum);
			if (playerNum >= players.size())
			{
				playerNum = 0;
			}
			if (players.size() == 1) 
			{
				std::cout << players[0] << " wins." << std::endl;
				return;
			}
			
		}
		//std::cout << result << std::endl;
	}

}

void Game::playSingle()
{
	std::string result;
	std::string guess;
	bool first;
	for (int i = startNum; i <= endNum; i++)
	{
		first = true;
		system("CLS");
		result = "";
		for (int triggersI = 0; triggersI < triggers.size(); triggersI++)
		{
			if (i % triggers[triggersI] == 0)
			{
				if (!first) 
				{
					result += "_";
				}
				result += triggerWords[triggersI];
				first = false;
			}
		}
		if (result == "") 
		{
			result = std::to_string(i);
		}
		system("CLS");
		std::cout << "What is the next result? (use _ for spaces)" << std::endl;
		std::cin >> guess;
		if (guess == result) 
		{
			std::cout << "correct" << std::endl;
		}
		else 
		{
			std::cout << "incorrect it was " << result<< " not " << guess <<std::endl;
			return;
		}
		//std::cout << result << std::endl;
	}

}

void Game::results() 
{
	std::string result;
	for (int i = startNum; i <= endNum; i++)
	{
		result = "";
		for (int triggersI = 0; triggersI < triggers.size(); triggersI++)
		{
			if (i % triggers[triggersI] == 0)
			{
				result += triggerWords[triggersI];
				if (triggersI != (triggers.size() - 1))
				{
					result += " ";
				}
			}
		}
		if (result == "")
		{
			result = std::to_string(i);
		}
		std::cout << result << std::endl;
	}

}