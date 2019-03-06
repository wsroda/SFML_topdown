#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<ctime>
#include<cstdlib>

#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"


class Game
{
private:
	//variables
	sf::RenderWindow *window;
	sf::Event sfEvent;


	//init
	void initWindow();

public:
	Game();
	virtual ~Game();

	void updateEvents();
	void update();
	void render();
	void run();


};

#endif