#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include<vector>
#include<algorithm>
#include"GameObject.h"
#include<stack>



class ObjectManager
{

private:
	static std::vector<GameObject*> gameObjects;
	static std::stack<GameObject*> toRemove;
	static std::stack<GameObject*> toAdd;

public:
	ObjectManager();
	~ObjectManager();
	
	static void add(GameObject *obj);
	static void remove(GameObject *obj);
	static void destroy(GameObject *obj, float sec=0.f);

	static void update();
	static void render(sf::RenderWindow *win);
	static void manageObjects();
};
#endif
