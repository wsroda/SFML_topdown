#pragma once
#include"ObjectManager.h"
class Bullet : public GameObject
{

private: 
	sf::RectangleShape collider;
	void move();
	float angle;

public:
	Bullet(sf::Vector2f pos, float angle);
	~Bullet();

	float speed = 600.f;

	virtual void render(sf::RenderWindow *window) override;
	virtual void update() override;
};

