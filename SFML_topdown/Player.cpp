#include "Player.h"



Player::Player(sf::Vector2f pos, sf::RenderWindow *win)
{
	playerShape.setSize({ 48,48 });
	playerShape.setFillColor(sf::Color::Green);
	playerShape.setPosition(pos);
	playerShape.setOrigin({ 24,24 });
	window = win;


}

Player::~Player()
{

}

float Player::getX()
{
	return playerShape.getPosition().x;
}

float Player::getY()
{
	return playerShape.getPosition().y;
}

void Player::render(sf::RenderWindow *window)
{
	window->draw(debugline, 2, sf::Lines); // DEBUG
	window->draw(playerShape);
	
}

void Player::update()
{
	movex = 0.f;
	movey = 0.f;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
		movey = -1.f;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		movex = 1.f;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
		movex = -1.f;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
		movey = 1.f;
	}
	move();
	rotateToMouse();
	debugline[1] = sf::Vertex(sf::Vector2f(getX(), getY())); //DEBUG



	//rotateToMouse(this->window); // TODO widocznosc window w klasie playera
}

void Player::move()
{
	float dt = Time::deltaTime;
	playerShape.move({ movex * speed * dt, movey * speed * dt});
}

void Player::setRotation(float angle)
{
	playerShape.setRotation(angle);
}

void Player::rotateToMouse()
{
	sf::Vector2f curPos;
	curPos.x = Player::getX();
	curPos.y = Player::getY();
	sf::Vector2i position = sf::Mouse::getPosition(*window);
	debugline[0] = sf::Vertex(sf::Vector2f((float)position.x, (float)position.y)); // DEBUG


	const float PI = 3.14159265f;

	float dx = curPos.x - position.x;
	float dy = curPos.y - position.y;
	angle = (atan2(dy, dx)) * 180 / PI;

	setRotation(angle);
}


