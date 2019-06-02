#include "Bullet.h"



Bullet::Bullet(sf::Vector2f pos, float alpha)
{
	collider.setSize({ 8,4 });
	collider.setFillColor(sf::Color::Red);
	collider.setPosition(pos);
	collider.setOrigin({ 4,2 });
	angle = alpha;
	collider.setRotation(angle);

	//std::cout << bulletShape.getRotation() << std::endl;
}

Bullet::~Bullet()
{

}

void Bullet::move()
{
	float dt = Time::deltaTime;
	const float PI = 3.14159265359f;

	collider.move({ speed * cos(angle * PI / 180) * dt, speed * sin(angle * PI / 180) * dt });
}

void Bullet::render(sf::RenderWindow * window)
{
	window->draw(collider);
}

void Bullet::update()
{
	;
	move();
}
