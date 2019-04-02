#ifndef PLAYER_H
#define PLAYER_H

#include"SFML/Graphics.hpp"
#include"GameObject.h"
#include<iostream>

#pragma once
class Player: public GameObject
{
private:

	sf::RectangleShape playerShape;

	

public:
	Player(sf::Vector2f pos);
	~Player();

	float speed = 200.f;

	float movex;
	float movey;


	float getX();
	float getY();
	void move();
	void setRotation(float angle);

	virtual void render(sf::RenderWindow *window) override;
	virtual void update() override;
	void rotateToMouse(sf::RenderWindow *window);
};

#endif