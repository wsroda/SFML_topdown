#include "ObjectManager.h"

std::vector<GameObject*> ObjectManager::gameObjects = std::vector<GameObject*>();

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::add(GameObject *obj) //adding objects to std::stack
{
	gameObjects.push_back(obj);
	
}

void ObjectManager::remove(GameObject *obj) //adding objects to std::stack
{

}

void ObjectManager::update()
{
	for (std::size_t i = 0; i < gameObjects.size(); ++i)
		gameObjects[i]->update();
}



void ObjectManager::render(sf::RenderWindow * win)
{
	for (GameObject *i : gameObjects)
		i->render(win);
}

void ObjectManager::manageObjects()
{
	//adding and removing objects from std::stack
}

