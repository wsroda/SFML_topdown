#ifndef SHOOTINGENEMY_H
#define SHOOTINGENEMY_H

#include "GameObject.h"
#include "Player.h"

class ShootingEnemy :
	public GameObject
{

private:

	sf::RenderWindow *window;
	sf::CircleShape sprite;
	int healthPoints = 5;
	class Player *target;

	void shoot(float cd = 0.5f);
	bool canShoot = false;
	float timeToNextShot;

	sf::Vector2f getRandomVector();
	sf::Vector2f moveVector;
	void move();
	float speed = 100.f;
	float timeToChangeMoveVector = 0.f;

public:
	ShootingEnemy(sf::Vector2f pos, Player * newTarget);
	~ShootingEnemy();

	static std::vector<ShootingEnemy*> Enemies;

	float getX();
	float getY();
	float collisionRadius = 16.f;

	void takeDamage();

	virtual void render(sf::RenderWindow *window) override;
	virtual void update() override;
};
#endif
