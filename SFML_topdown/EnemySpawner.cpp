#include "EnemySpawner.h"



void EnemySpawner::spawnShootingEnemy()
{
	sf::Vector2f position({ (float)(rand() % ObjectManager::win->getSize().x),(float)(rand() % ObjectManager::win->getSize().y) });
	new ShootingEnemy(position, ObjectManager::player);
};

void EnemySpawner::spawnExplodingEnemy()
{
	int side = rand() % 4;
	sf::Vector2f position;
	switch (side)
	{
	case 1:
		position = sf::Vector2f({ 0, (float)(rand() % ObjectManager::win->getSize().y) });
		break;
	case 2:
		position = sf::Vector2f({ (float)ObjectManager::win->getSize().x, (float)(rand() % ObjectManager::win->getSize().y) });
		break;
	case 3:
		position = sf::Vector2f({ (float)(rand() % ObjectManager::win->getSize().x), 0 });
		break;
	case 4:
		position = sf::Vector2f({ (float)(rand() % ObjectManager::win->getSize().x), (float)ObjectManager::win->getSize().y });
		break;

	}

	new ExplodingEnemy(position, ObjectManager::player);
}

EnemySpawner::EnemySpawner()
{
	timeToSpawnExplodingEnemy = Time::Clock.getElapsedTime().asSeconds() + ExplodingEnemySpawnInterval;
	timeToSpawnShootingEnemy = Time::Clock.getElapsedTime().asSeconds() + ShootingEnemySpawnInterval;
}


EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::update()
{
	if (Time::Clock.getElapsedTime().asSeconds() > 20)
	{
		ShootingEnemySpawnInterval = 3;
	}
	if (Time::Clock.getElapsedTime().asSeconds() > 30)
	{
		ShootingEnemySpawnInterval = 1.5f;
		ExplodingEnemySpawnInterval = 3;
	}
	if (Time::Clock.getElapsedTime().asSeconds() > 60)
		ShootingEnemySpawnInterval = 0.75f;
	if (Time::Clock.getElapsedTime().asSeconds() > 90)
		ShootingEnemySpawnInterval = 0.3f;


	if (Time::Clock.getElapsedTime().asSeconds() > timeToSpawnShootingEnemy)
	{
		spawnShootingEnemy();
		timeToSpawnShootingEnemy = Time::Clock.getElapsedTime().asSeconds() + ShootingEnemySpawnInterval + ((float)rand() / (float)(RAND_MAX)) * 2.0f;
	}

	if (Time::Clock.getElapsedTime().asSeconds() > timeToSpawnExplodingEnemy)
	{
		spawnExplodingEnemy();
		timeToSpawnExplodingEnemy = Time::Clock.getElapsedTime().asSeconds() + ExplodingEnemySpawnInterval + ((float)rand() / (float)(RAND_MAX)) * 2.0f;
	}

}
