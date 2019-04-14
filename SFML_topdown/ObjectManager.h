#pragma once
#include<vector>
#include"GameObject.h"



class ObjectManager
{

private:
	

public:
	ObjectManager();
	~ObjectManager();
	static std::vector<GameObject *> gameObjects;
	static void add(GameObject *obj);
	static void update();
	static void render(sf::RenderWindow *win);
};

