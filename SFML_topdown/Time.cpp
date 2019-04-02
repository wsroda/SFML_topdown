#include "Time.h"

sf::Clock Time::dtClock;
float Time::deltaTime;

Time::Time()
{
	
}


Time::~Time()
{

}

void Time::updateDeltaTime()
{
	deltaTime = dtClock.restart().asSeconds();
}
