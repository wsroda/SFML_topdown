#include<vector>
#include"GameObject.h"
#pragma once

class ObjectManager
{

private:
	

public:
	ObjectManager();
	~ObjectManager();

	static std::vector<GameObject> GameObjects;
};

