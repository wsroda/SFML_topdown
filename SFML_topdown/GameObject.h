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
};

