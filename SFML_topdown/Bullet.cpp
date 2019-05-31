#include "Bullet.h"



Bullet::Bullet(sf::Vector2f pos, float alpha)
{
	bulletShape.setSize({ 8,4 });
	bulletShape.setFillColor(sf::Color::Red);
	bulletShape.setPosition(pos);
	bulletShape.setOrigin({ 4,2 });
	angle = alpha;
	bulletShape.setRotation(angle);

	//std::cout << bulletShape.getRotation() << std::endl;
}

Bullet::~Bullet()
{

}

void Bullet::move()
{
	float dt = Time::deltaTime;
	const float PI = 3.14159265359f;

	bulletShape.move({ speed * cos(angle * PI / 180) * dt, speed * sin(angle * PI / 180) * dt });
}

void Bullet::render(sf::RenderWindow * window)
{
	window->draw(bulletShape);
}

void Bullet::update()
{
	;
	move();
}
