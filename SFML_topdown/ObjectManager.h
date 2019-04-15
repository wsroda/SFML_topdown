#pragma once
#include<vector>
#include"GameObject.h"



class ObjectManager
{

private:
	static std::vector<GameObject*> gameObjects;

public:
	ObjectManager();
	~ObjectManager();
	
	static void add(GameObject *obj);
	static void remove(GameObject *obj);

	static void update();
	static void render(sf::RenderWindow *win);
	
};

