#ifndef SHOOTINGENEMY_H
#define SHOOTINGENEMY_H

#include "GameObject.h"
class ShootingEnemy :
	public GameObject
{

private:

	sf::RenderWindow *window;
	sf::CircleShape sprite;
	int healthPoints = 5;

public:
	ShootingEnemy(sf::Vector2f pos);
	~ShootingEnemy();

	virtual void render(sf::RenderWindow *window) override;
	virtual void update() override;
};
#endif
