#ifndef BULLET_H
#define BULLET_H

#include"ObjectManager.h"
#include"ShootingEnemy.h"
class Bullet : public GameObject
{

private: 
	sf::RectangleShape sprite;
	void move();
	float angle;
	sf::Vector2f moveVector;

	bool fromEnemy;

public:
	Bullet(sf::Vector2f pos, float angle, bool enemy = false);
	~Bullet();

	float speed = 600.f;


	float getX();
	float getY();

	virtual void render(sf::RenderWindow *window) override;
	virtual void update() override;

	void checkCollisionsWithEnemies();
	void checkCollisionsWithPlayer();
};
#endif

