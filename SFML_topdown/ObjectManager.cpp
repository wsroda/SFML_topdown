#include "ObjectManager.h"

std::vector<GameObject*> ObjectManager::gameObjects = std::vector<GameObject*>();

std::stack<GameObject*> ObjectManager::toAdd = std::stack<GameObject*>();
std::stack<GameObject*> ObjectManager::toRemove = std::stack<GameObject*>();
Player *ObjectManager::player;
sf::RenderWindow *ObjectManager::win;

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

void ObjectManager::destroy(GameObject *obj, float sec) //destroying objects (schedule destroying)
{
	if (sec == 0.f)
	{
		ObjectManager::remove(obj);
	}
	else
	{
		if (!obj->destroying)
		{
			obj->destroying = true;
			obj->timeToDestroy = Time::Clock.getElapsedTime().asSeconds() + sec;
		}
	}
	

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
	//checking objects scheduled to destroy
	for (auto object: ObjectManager::gameObjects)
		if (object->destroying)
		{
			if (Time::Clock.getElapsedTime().asSeconds() > object->timeToDestroy)
				ObjectManager::remove(object);
		}

	//adding objects
	while (!toAdd.empty()) 
	{
		gameObjects.push_back(toAdd.top());
		toAdd.pop();
	}


	//removing objects
	while (!toRemove.empty()) 
	{ 
		gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), toRemove.top()), gameObjects.end());
		delete toRemove.top();
		toRemove.pop();
	}
}

void ObjectManager::spawnPlayer(Player *pl)
{
	player = pl;
}

