#pragma once
#include "GameObject.h"
class Bullet : public GameObject
{

private: 
	sf::RectangleShape bulletShape;
	void move();
	float angle;

public:
	Bullet(sf::Vector2f pos, float angle);
	~Bullet();

	float speed = 300.f;

	virtual void render(sf::RenderWindow *window) override;
	virtual void update() override;
};

