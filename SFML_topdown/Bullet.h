#ifndef BULLET_H
#define BULLET_H

#include"ObjectManager.h"
class Bullet : public GameObject
{

private: 
	sf::RectangleShape sprite;
	void move();
	float angle;
	sf::Vector2f moveVector;

public:
	Bullet(sf::Vector2f pos, float angle);
	~Bullet();

	float speed = 600.f;

	virtual void render(sf::RenderWindow *window) override;
	virtual void update() override;
};
#endif

