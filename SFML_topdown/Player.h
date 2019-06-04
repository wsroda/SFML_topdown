#ifndef PLAYER_H
#define PLAYER_H

#include"SFML/Graphics.hpp"
#include<iostream>
#include<vector>
#include"ObjectManager.h"
#include"Bullet.h"



class Player: public GameObject
{
private:

	sf::RectangleShape sprite;

	void move();
	float movex;
	float movey;
	float angle;
	void setRotation(float angle);
	int level = 3;
	sf::Vector2f direction;

	sf::RenderWindow *window;

	bool canShoot = true;
	float timeToNextShot;


public:
	Player(sf::Vector2f pos, sf::RenderWindow *win);
	~Player();

	float speed = 200.f;
	int healthPoints = 5;

	void shoot(float cd=0.5f);
	float getX();
	float getY();
	float getRotation();
	
	virtual void render(sf::RenderWindow *window) override;
	virtual void update() override;
	void rotateToMouse();

	sf::Vertex debugline[2] =
	{
		sf::Vertex(sf::Vector2f(0 ,0)),
		sf::Vertex(sf::Vector2f(0 ,0))
	};
};

#endif