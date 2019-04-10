#include "Game.h"




//init
void Game::initWindow()
{
	std::ifstream ifs("Config/window.ini");
	sf::VideoMode window_bounds(800,600);
	std::string title = "None";
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;
	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);

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
void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	//player movement

	player->update();

	this->updateSFMLEvents();

}

void Game::render()
{
	this->window->clear();

	player->render(this->window);

	this->window->display();
}

void Game::run()
{
	player = new Player({ 400 , 300 }, window);


	while (this->window->isOpen())
	{
		Time::updateDeltaTime();
		this->update();
		this->render();
	}
}
