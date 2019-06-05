#include "ExplodingEnemy.h"



ExplodingEnemy::ExplodingEnemy(sf::Vector2f pos, Player * newTarget)
{
	sprite.setRadius(16);
	sprite.setFillColor(sf::Color::Red);
	sprite.setPosition(pos);
	sprite.setOrigin({ 16, 16 });
	target = newTarget;
}


ExplodingEnemy::~ExplodingEnemy()
{
}

float ExplodingEnemy::getX()
{
	return sprite.getPosition().x;
}

float ExplodingEnemy::getY()
{
	return sprite.getPosition().y;
}

void ExplodingEnemy::Explode()
{

}

void ExplodingEnemy::move()
{

	float movX = target->getX() - getX();
	float movY = target->getY() - getY();
	float len = sqrt(movX * movX + movY * movY);
	movX /= len;
	movY /= len;
	float dt = Time::deltaTime;
	sprite.move(movX * speed * dt, movY * speed * dt);


}

void ExplodingEnemy::render(sf::RenderWindow * window)
{
	window->draw(sprite);
}

void ExplodingEnemy::update()
{
	float targetDistance = sqrt((target->getX() - getX()) * (target->getX() - getX()) + (target->getY() - getY()) * (target->getY() - getY()));
	if (targetDistance > 48)
	{
		if (!exploding)
			move();
	}
	else
		exploding = true;

}
