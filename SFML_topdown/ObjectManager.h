#include<vector>
#include"GameObject.h"
#pragma once

class ObjectManager
{

private:
	std::vector<GameObject> GameObjects;

public:
	ObjectManager();
	~ObjectManager();
};

