#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include"SFML/Graphics.hpp"
#include<iostream>
#include<vector>
#include"ObjectManager.h"
#include"Bullet.h"
#include"ShootingEnemy.h"
#include"ExplodingEnemy.h"
#include"Time.h"

class EnemySpawner
{
private:
	void spawnShootingEnemy();
	void spawnExplodingEnemy();

	float ShootingEnemySpawnInterval = 5;
	float ExplodingEnemySpawnInterval = 8;

	float timeToSpawnShootingEnemy;
	float timeToSpawnExplodingEnemy;
public:
	EnemySpawner();
	~EnemySpawner();

	void update();
	
};

#endif

