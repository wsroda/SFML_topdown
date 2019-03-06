#include "Game.h"


//init
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "GRA");
}

//Constructor/Destructor
Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}


//functions
void Game::updateEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->updateEvents();
}

void Game::render()
{
	this->window->clear();

	//render

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
