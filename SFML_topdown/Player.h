#ifndef PLAYER_H
#define PLAYER_H

#include"SFML/Graphics.hpp"
#include"GameObject.h"
#include<iostream>
#include<vector>

#pragma once

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
	

public:
	Player(sf::Vector2f pos, sf::RenderWindow *win);
	~Player();

	float speed = 200.f;

	float getX();
	float getY();
	
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