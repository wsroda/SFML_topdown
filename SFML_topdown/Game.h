#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>

#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"

#include"Player.h"
#include"ShootingEnemy.h"


class Game
{
private:

	sf::RenderWindow *window;
	sf::Event sfEvent;
	void initWindow();
	bool paused = false;

public:
	Game();
	virtual ~Game();

	//functions
	Player *player;
	void updateSFMLEvents();
	void update();
	void render();
	void run();

	void pause();
	void resume();

};

#endif