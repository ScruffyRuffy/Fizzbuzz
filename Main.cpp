//main.cpp
#include <iostream>
#include <string>
#include "Game.h"



void menu() 
{
	std::cout << "Fizz Buzz\n1) Play a 1 player game\n2) Play a multiplayer game\n3) Display the answers\n4) quit\nPlease enter a number to continue." << std::endl;
	std::string menuOption;
	int choice;
	std::cin >>  menuOption;
	choice = std::stoi(menuOption);
	Game theGame;
	switch (choice)
	{
	case 1:
		system("CLS");
		std::cout << "Loading single player game" << std::endl;
		theGame.setUp();
		theGame.playSingle();
		break;
	case 2:
		system("CLS");
		std::cout << "Loading multi-player game" << std::endl;
		theGame.setUpMultiplayer();
		theGame.setUp();
		theGame.playMulti();
		break;
	case 3:
		system("CLS");
		std::cout << "Displaying results" << std::endl;
		theGame.setUp();
		theGame.results();
		break;
	case 4:
		system("CLS");
		std::cout << "Ending game" << std::endl;
		break;
	default:
		break;
	};


}


int main()
{
	menu();
	std::string var;
	std::cout << "enter anything to exit." << std::endl;
	std::cin>>var;
	return 0;
}


