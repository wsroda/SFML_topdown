#pragma once
#include "GameObject.h"
#include "Player.h"
class ExplodingEnemy :
	public GameObject
{
private:
	sf::RenderWindow *window;
	sf::CircleShape sprite;

	class Player *target;
	float speed = 450.f;

public:
	ExplodingEnemy(sf::Vector2f pos, Player * newTarget);
	~ExplodingEnemy();

	float getX();
	float getY();
	float collisionRadius = 16.f;
	float ExplosionRadius = 128.f;
	bool exploding = false;
	void explode();
	void startExploding(float sec);
	float timeToExplosion;
	void move();


	virtual void render(sf::RenderWindow *window) override;
	virtual void update() override;
};

