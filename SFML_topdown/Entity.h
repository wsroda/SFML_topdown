#pragma once
#include "GameObject.h"
class Entity : public GameObject
{

private:
	sf::RectangleShape entityShape;
public:
	Entity();
	~Entity();


};

