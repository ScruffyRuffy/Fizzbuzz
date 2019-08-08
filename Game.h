#include <vector>
#pragma once
class Game
{
public:
	Game();
	~Game();
	void setUp();
	void setUpMultiplayer();
	void playSingle();
	void playMulti();
	void results();
private:
	int startNum;
	int endNum;
	std::vector<std::string> players;
	std::vector<std::string> triggerWords;
	std::vector<int> triggers;
};

