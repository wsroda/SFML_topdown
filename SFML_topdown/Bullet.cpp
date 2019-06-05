#include "Bullet.h"



Bullet::Bullet(sf::Vector2f pos, float alpha, bool enemy)
{
	sprite.setSize({ 8,4 });
	sprite.setFillColor(sf::Color::Red);
	sprite.setPosition(pos);
	sprite.setOrigin({ 4,2 });
	angle = alpha;
	sprite.setRotation(angle);
	const float PI = 3.14159265359f;
	moveVector = sf::Vector2f(cos(angle * PI / 180), sin(angle * PI / 180));
	fromEnemy = enemy;
}

Bullet::~Bullet()
{

}

void Bullet::move()
{
	float dt = Time::deltaTime;
	const float PI = 3.14159265359f;

	sprite.move({ speed * moveVector.x * dt, speed * moveVector.y * dt });
}

float Bullet::getX()
{
	return sprite.getPosition().x;
}

float Bullet::getY()
{
	return sprite.getPosition().y;
}

void Bullet::render(sf::RenderWindow * window)
{
	window->draw(sprite);
}

void Bullet::update()
{
	move();
	if (!fromEnemy)
		checkCollisionsWithEnemies();
	else
		checkCollisionsWithPlayer();
}

void Bullet::checkCollisionsWithEnemies()
{
	for (auto enemy : ShootingEnemy::Enemies)
	{
		float dist = sqrt((enemy->getX() - getX())*(enemy->getX() - getX()) + (enemy->getY() - getY())*(enemy->getY() - getY()));
		if (dist <= enemy->collisionRadius)
		{
			enemy->takeDamage();
			destroying = false;
			ObjectManager::destroy(this);
			break;
		}
	}
}

void Bullet::checkCollisionsWithPlayer()
{
	Player *player = ObjectManager::player;
	float dist = sqrt((player->getX() - getX())*(player->getX() - getX()) + (player->getY() - getY())*(player->getY() - getY()));
	
	if (dist <= player->collisionRadius)
	{
		ObjectManager::player->takeDamage();
		destroying = false;
		ObjectManager::remove(this);
	}
	
}
