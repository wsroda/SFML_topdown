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
