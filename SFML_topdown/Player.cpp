#include "Player.h"
#include<string>





Player::Player(sf::Vector2f pos)
{
	sprite.setSize({ 32, 32 });
	sprite.setFillColor(sf::Color::Green);
	sprite.setPosition(pos);
	sprite.setOrigin({ 16, 16 });
}

Player::~Player()
{

}

float Player::getX()
{
	return sprite.getPosition().x;
}

float Player::getY()
{
	return sprite.getPosition().y;
}

float Player::getRotation()
{
	return sprite.getRotation();
}

void Player::takeDamage(int amount)
{
	healthPoints--;
	if (healthPoints > 1)
		;
			//KONIEC GRY
}

void Player::render(sf::RenderWindow *window)
{
	//window->draw(debugline, 2, sf::Lines); // DEBUG
	window->draw(sprite);
	displayUI(window);
}

void Player::update()
{
	if (ObjectManager::player->killCount >= 5)
		level = 2;
	else if (ObjectManager::player->killCount >= 10)
		level = 3;


	movex = 0.f;
	movey = 0.f;
	
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
		if (sprite.getPosition().y > 0)
			movey = -1.f;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		if (sprite.getPosition().x < ObjectManager::win->getSize().x)
			movex = 1.f;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
		if (sprite.getPosition().x > 0)
			movex = -1.f;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
		if (sprite.getPosition().y < ObjectManager::win->getSize().y)
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
	sprite.move({ movex * speed * dt, movey * speed * dt});
}

void Player::shoot(float cd)
{
	if (canShoot)
	{
		float vectorLength = sqrt(direction.x*direction.x + direction.y*direction.y);
		sf::Vector2f offset(direction.y / vectorLength, direction.x / vectorLength);
		switch (level)
		{

		case 1:
			ObjectManager::destroy(new Bullet({ getX() + offset.x * 5, getY() - offset.y * 5 }, getRotation()), 1.f);
			ObjectManager::destroy(new Bullet({ getX() - offset.x * 5, getY() + offset.y * 5 }, getRotation()), 1.f);
			break;
		case 2:

			ObjectManager::destroy(new Bullet({ getX(), getY() }, getRotation()), 1.f);
			ObjectManager::destroy(new Bullet({ getX() + offset.x*10, getY() - offset.y*10 }, getRotation()), 1.f);
			ObjectManager::destroy(new Bullet({ getX() - offset.x*10, getY() + offset.y*10 }, getRotation()), 1.f);
			break;
		case 3:

			ObjectManager::destroy(new Bullet({ getX(), getY() }, getRotation()), 1.f);
			ObjectManager::destroy(new Bullet({ getX() + offset.x*10, getY() - offset.y*10 }, getRotation()), 1.f);
			ObjectManager::destroy(new Bullet({ getX() - offset.x*10, getY() + offset.y*10 }, getRotation()), 1.f);
			ObjectManager::destroy(new Bullet({ getX() + offset.x*20, getY() - offset.y*20 }, getRotation()), 1.f);
			ObjectManager::destroy(new Bullet({ getX() - offset.x*20, getY() + offset.y*20 }, getRotation()), 1.f);
			break;
		}
		

		canShoot = false;
		timeToNextShot= Time::Clock.getElapsedTime().asSeconds() + cd;
	}

}

void Player::setRotation(float angle)
{
	sprite.setRotation(angle);
}

void Player::rotateToMouse()
{
	sf::Vector2f curPos;
	curPos.x = getX();
	curPos.y = getY();
	sf::Vector2i position = sf::Mouse::getPosition(*ObjectManager::win);

	//debugline[0] = sf::Vertex(sf::Vector2f((float)position.x, (float)position.y)); // DEBUG


	const float PI = 3.14159265359f;

	direction = sf::Vector2f(position.x - curPos.x, position.y - curPos.y);

	angle = (atan2(direction.y, direction.x)) * 180 / PI;

	setRotation(angle);
}

void Player::displayUI(sf::RenderWindow *win)
{
	sf::Text HPtext;
	std::stringstream ss;
	int totalseconds = (int)Time::Clock.getElapsedTime().asSeconds();
	int sec = totalseconds % 60;
	int min = totalseconds / 60;
	std::string sep; //separator between min and sec
	if (sec / 10 == 0)
		sep = ":0";
	else
		sep = ":";

	ss << min << sep << sec << "\t\t" << "LVL: " << level << "\t\t" <<"Health: " << healthPoints;
	HPtext.setString(ss.str().c_str());
	HPtext.setFont(ObjectManager::font);
	HPtext.setCharacterSize(30);
	HPtext.setStyle(sf::Text::Bold);
	HPtext.setPosition(ObjectManager::win->getSize().x-500, 0);
	win->draw(HPtext);
}


