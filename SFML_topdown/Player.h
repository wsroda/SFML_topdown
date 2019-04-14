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

	sf::RectangleShape playerShape;

	void move();
	float movex;
	float movey;
	float angle;
	void setRotation(float angle);

	sf::RenderWindow *window;
	
	
	std::vector<Bullet*> bullets;

public:
	Player(sf::Vector2f pos, sf::RenderWindow *win);
	~Player();

	float speed = 200.f;

	void shoot();
	float getX();
	float getY();
	float getRotation();
	
	bool canShoot = true;
	float shootCD;

	virtual void render(sf::RenderWindow *window) override;
	virtual void update() override;
	void rotateToMouse();

	sf::Vertex debugline[2] =
	{
		sf::Vertex(sf::Vector2f(0 ,0)),
		sf::Vertex(sf::Vector2f(0 ,0))
	};;
};

#endif