#include "ShootingEnemy.h"



ShootingEnemy::ShootingEnemy(sf::Vector2f pos)
{
	sprite.setRadius(16);
	sprite.setFillColor(sf::Color::Red);
	sprite.setPosition(pos);
}


ShootingEnemy::~ShootingEnemy()
{

}

void ShootingEnemy::render(sf::RenderWindow * window)
{
	window->draw(sprite);
}

void ShootingEnemy::update()
{

}
