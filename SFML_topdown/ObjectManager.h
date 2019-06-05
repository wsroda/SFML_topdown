#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include<vector>
#include<algorithm>
#include"GameObject.h"
#include<stack>
#include"Player.h"



class ObjectManager
{

private:
	
	static std::stack<GameObject*> toRemove;
	static std::stack<GameObject*> toAdd;

public:
	ObjectManager();
	~ObjectManager();

	static sf::Font font;
	static void loadFont();
	
	
	static std::vector<GameObject*> gameObjects;
	static void add(GameObject *obj);
	static void remove(GameObject *obj);
	static void destroy(GameObject *obj, float sec=0.f);

	static void update();
	static void render(sf::RenderWindow *win);
	static void manageObjects();

	static class Player * player;
	static sf::RenderWindow *win;
	static void spawnPlayer(Player *pl);
};
#endif
