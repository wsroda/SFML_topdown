#include "ObjectManager.h"

std::vector<GameObject*> ObjectManager::gameObjects = std::vector<GameObject*>();

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::add(GameObject *obj)
{
	gameObjects.push_back(obj);
}

void ObjectManager::update()
{
	for (GameObject *i : gameObjects)
		i->update();
}

void ObjectManager::render(sf::RenderWindow * win)
{
	for (GameObject *i : gameObjects)
		i->render(win);
}
