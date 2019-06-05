#include "ShootingEnemy.h"


std::vector<ShootingEnemy*> ShootingEnemy::Enemies = std::vector<ShootingEnemy*>();



ShootingEnemy::ShootingEnemy(sf::Vector2f pos, Player * newTarget)
{
	sprite.setRadius(16);
	sprite.setFillColor(sf::Color::Magenta);
	sprite.setPosition(pos);
	sprite.setOrigin({ 16, 16 });
	target = newTarget;
	Enemies.push_back(this);
}


ShootingEnemy::~ShootingEnemy()
{
	Enemies.erase(std::remove(Enemies.begin(), Enemies.end(), this), Enemies.end());
}

float ShootingEnemy::getX()
{
	return sprite.getPosition().x;
}

float ShootingEnemy::getY()
{
	return sprite.getPosition().y;
}

void ShootingEnemy::takeDamage()
{
	healthPoints--;
	std::cout << healthPoints << std::endl;
	if (healthPoints < 1)
		ObjectManager::destroy(this,0.1f);
}

void ShootingEnemy::shoot(float cd)
{
	sf::Vector2f direction = sf::Vector2f(target->getX() - getX(), target->getY() - getY());
	float rotation = (atan2(direction.y, direction.x)) * 180 / 3.14159265359f;
	std::cout << rotation << std::endl;
	ObjectManager::destroy(new Bullet({ getX(), getY() }, rotation, true), 3.f);

	canShoot = false;
	timeToNextShot = Time::Clock.getElapsedTime().asSeconds() + cd;
}

sf::Vector2f ShootingEnemy::getRandomVector()
{
	int newDX = rand() % ObjectManager::win->getSize().x - getX();
	int newDY = rand() % ObjectManager::win->getSize().y - getY();
	const float PI = 3.14159265359f;
	float angle = (atan2(newDY, newDX)) * 180 / PI;

	moveVector = sf::Vector2f(cos(angle * PI / 180), sin(angle * PI / 180));
	return moveVector;
}

void ShootingEnemy::move()
{
	float dt = Time::deltaTime;
	float movex = moveVector.x;
	float movey = moveVector.y;
	float newX = getX() + movex * speed * dt;
	float newY = getY() + movey * speed * dt;
	int maxY = ObjectManager::win->getSize().y;
	int maxX = ObjectManager::win->getSize().x;
	if ((newY > 0 && newY < maxY) && (newX > 0 && newX < maxX))
		sprite.move({ movex * speed * dt, movey * speed * dt });
}

void ShootingEnemy::render(sf::RenderWindow * window)
{
	window->draw(sprite);
}

void ShootingEnemy::update()
{
	if (Time::Clock.getElapsedTime().asSeconds() > timeToChangeMoveVector)
	{
		moveVector = getRandomVector();
		timeToChangeMoveVector = Time::Clock.getElapsedTime().asSeconds() + 2;
	}
	move();

	if (canShoot)
		shoot(1.5f);
	else
	{
		if (Time::Clock.getElapsedTime().asSeconds() > timeToNextShot)
			canShoot = true;
	}
	
}
