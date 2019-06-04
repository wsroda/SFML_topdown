#include "Bullet.h"



Bullet::Bullet(sf::Vector2f pos, float alpha)
{
	sprite.setSize({ 8,4 });
	sprite.setFillColor(sf::Color::Red);
	sprite.setPosition(pos);
	sprite.setOrigin({ 4,2 });
	angle = alpha;
	sprite.setRotation(angle);
	const float PI = 3.14159265359f;
	moveVector = sf::Vector2f(cos(angle * PI / 180), sin(angle * PI / 180));

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

void Bullet::render(sf::RenderWindow * window)
{
	window->draw(sprite);
}

void Bullet::update()
{
	move();
}
