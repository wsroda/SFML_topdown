#include "Bullet.h"



Bullet::Bullet(sf::Vector2f pos, float alpha)
{
	bulletShape.setSize({ 4,8 });
	bulletShape.setFillColor(sf::Color::Red);
	bulletShape.setPosition(pos);
	angle = alpha;
}

Bullet::~Bullet()
{

}

void Bullet::move()
{
	bulletShape.move({ speed * cos(angle), speed * sin(angle) });
}

void Bullet::render(sf::RenderWindow * window)
{
	window->draw(bulletShape);
}

void Bullet::update()
{
	move();
}
