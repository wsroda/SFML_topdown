#include "Game.h"




//init
void Game::initWindow()
{
	std::ifstream ifs("Config/window.ini");
	sf::VideoMode window_bounds(800,800);
	std::string title = "None";


	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;
	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close);
	ObjectManager::win = this->window;
	sf::Cursor cursor;
	if (cursor.loadFromSystem(sf::Cursor::Cross))
		this->window->setMouseCursor(cursor);
	//this->window->setFramerateLimit(framerate_limit);
	//this->window->setVerticalSyncEnabled(vertical_sync_enabled);

}

//Constructor/Destructor
Game::Game()
{
	this->initWindow();
	Time::startClocks();
}

Game::~Game()
{
	delete this->window;
	delete spawner;
}


//functions
void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();

		if (this->sfEvent.type == sf::Event::LostFocus)
			pause();

		if (this->sfEvent.type == sf::Event::GainedFocus)
			resume();

	}
}

void Game::update()
{

	ObjectManager::update();

}

void Game::render()
{
	this->window->clear(sf::Color::Black);

	ObjectManager::render(this->window);

	Time::showFPS(this->window);

	this->window->display();
}

void Game::run()
{
	ObjectManager::loadFont();
	ObjectManager::spawnPlayer(new Player({ (float)window->getSize().x / 2 , 3 * (float)window->getSize().y / 4 }));
	
	spawner = new EnemySpawner();

	sf::Cursor cursor;
	cursor.loadFromSystem(sf::Cursor::Cross);

	while (this->window->isOpen())
	{
		this->updateSFMLEvents();
		if (!paused)
		{
			this->window->setMouseCursor(cursor);
			Time::updateDeltaTime();
			this->update();
			this->render();
			ObjectManager::manageObjects();
			spawner->update();
		}
	}
	
}

void Game::pause()
{
	if (!paused)
	{
		paused = true;
		Time::pauseClocks();
	}
}

void Game::resume()
{
	if (paused)
	{
		paused = false;
		Time::resumeClocks();
	}
}

