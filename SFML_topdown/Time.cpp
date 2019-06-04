#include "Time.h"

//sf::Clock Time::dtClock;
//sf::Clock Time::Clock;
sftools::Chronometer Time::dtClock;
sftools::Chronometer Time::Clock;
float Time::deltaTime;
sf::Font Time::font;
bool Time::fontLoaded = false;



Time::Time()
{

}


Time::~Time()
{

}

void Time::updateDeltaTime()
{
	deltaTime = dtClock.reset(true).asSeconds();
}

void Time::showFPS(sf::RenderWindow *window)
{
	if (!fontLoaded)
	{
		loadFont();
	}
	float fps = 1.f / deltaTime;
	sf::Text fpsText;
	std::stringstream ss;
	ss << fps;
	fpsText.setString(ss.str().c_str());
	fpsText.setFont(font);
	fpsText.setCharacterSize(14);
	fpsText.setStyle(sf::Text::Bold);
	fpsText.setPosition(5, 0);
	window->draw(fpsText);
}

void Time::startClocks()
{
	Time::dtClock.reset(true).asSeconds();
	Time::Clock.reset(true).asSeconds();
}

void Time::pauseClocks()
{
	Time::dtClock.pause();
	Time::Clock.pause();
}

void Time::resumeClocks()
{
	Time::dtClock.resume();
	Time::Clock.resume();
}

void Time::loadFont()
{
	if (!font.loadFromFile("Helvetica.ttf"))
		std::cout << "NIE DZIALA" << std::endl;
	else
		fontLoaded = true;
}


