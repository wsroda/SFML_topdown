#include "ObjectManager.h"

std::vector<GameObject*> ObjectManager::gameObjects = std::vector<GameObject*>();

std::stack<GameObject*> ObjectManager::toAdd = std::stack<GameObject*>();
std::stack<GameObject*> ObjectManager::toRemove = std::stack<GameObject*>();

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{

}

void ObjectManager::add(GameObject *obj) //adding objects
{
	toAdd.push(obj);
}

void ObjectManager::remove(GameObject *obj) //removing objects
{
	toRemove.push(obj);
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
	//adding objects
	while (!toAdd.empty()) 
	{
		gameObjects.push_back(toAdd.top());
		std::cout << "usunieto: " << toAdd.top() << std::endl;
		toAdd.pop();
	}




	//removing objects
	while (!toRemove.empty()) 
	{ 
		gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), toRemove.top()), gameObjects.end());
		delete toRemove.top();
		toRemove.pop();
	}

	std::cout << "gameobjects size: " << gameObjects.size() << std::endl;
}

