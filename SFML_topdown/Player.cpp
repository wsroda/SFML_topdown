#include "Player.h"





Player::Player(sf::Vector2f pos, sf::RenderWindow *win)
{
	collider.setSize({ 32, 32 });
	collider.setFillColor(sf::Color::Green);
	collider.setPosition(pos);
	collider.setOrigin({ 16, 16 });
	window = win;
}

Player::~Player()
{

}

float Player::getX()
{
	return collider.getPosition().x;
}

float Player::getY()
{
	return collider.getPosition().y;
}

float Player::getRotation()
{
	return collider.getRotation();
}

void Player::render(sf::RenderWindow *window)
{
	//window->draw(debugline, 2, sf::Lines); // DEBUG
	window->draw(collider);
	
}

void Player::update()
{
	movex = 0.f;
	movey = 0.f;
	
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
		if (collider.getPosition().y > 0)
			movey = -1.f;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		if (collider.getPosition().x < window->getSize().x)
			movex = 1.f;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
		if (collider.getPosition().x > 0)
			movex = -1.f;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
		if (collider.getPosition().y < window->getSize().y)
			movey = 1.f;
	}
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		shoot();
	}

	//shoot cd

	if (!canShoot)
	{
		if (Time::Clock.getElapsedTime().asSeconds() > timeToNextShot)
			canShoot = true;
	}

	//shoot cd

	move();
	rotateToMouse();
	debugline[1] = sf::Vertex(sf::Vector2f(getX(), getY())); //DEBUG



	//rotateToMouse(this->window); // TODO widocznosc window w klasie playera
}

void Player::move()
{
	float dt = Time::deltaTime;
	collider.move({ movex * speed * dt, movey * speed * dt});
}

void Player::shoot(float cd)
{
	if (canShoot)
	{
		ObjectManager::destroy(new Bullet({ getX(), getY() }, getRotation()),1.f);

		canShoot = false;
		timeToNextShot= Time::Clock.getElapsedTime().asSeconds() + cd;
		
		

	}

}

void Player::setRotation(float angle)
{
	collider.setRotation(angle);
}

void Player::rotateToMouse()
{
	sf::Vector2f curPos;
	curPos.x = getX();
	curPos.y = getY();
	sf::Vector2i position = sf::Mouse::getPosition(*window);

	//debugline[0] = sf::Vertex(sf::Vector2f((float)position.x, (float)position.y)); // DEBUG


	const float PI = 3.14159265359f;

	float dx = position.x - curPos.x;
	float dy = position.y - curPos.y;
	angle = (atan2(dy, dx)) * 180 / PI;

	setRotation(angle);
}


