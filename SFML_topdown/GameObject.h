#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include"SFML/Graphics.hpp"
#include"Time.h"

#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void update();
	virtual void render(sf::RenderWindow *window);
	void destroy(float sec);


	bool destroying = false;
	float timeToDestroy;
	
};
#endif
