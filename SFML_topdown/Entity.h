#pragma once
#include"ObjectManager.h"
class Entity : public GameObject
{

private:
	sf::RectangleShape entityShape;
public:
	Entity();
	~Entity();


};

