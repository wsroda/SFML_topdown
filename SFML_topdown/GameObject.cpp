#include "GameObject.h"
#include "ObjectManager.h"




GameObject::GameObject()
{
	ObjectManager::add(this);
}


GameObject::~GameObject()
{
	
}

void GameObject::update()
{

}

void GameObject::render(sf::RenderWindow * window)
{

}

void GameObject::destroy(float sec = 0)
{
	if (sec == 0)
	{
		ObjectManager::remove(this);
	}
	else
	{

	}
}

