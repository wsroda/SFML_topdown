#include "Time.h"
#include <sstream>

sf::Clock Time::dtClock;
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
	deltaTime = dtClock.restart().asSeconds();
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
	fpsText.setCharacterSize(18);
	fpsText.setStyle(sf::Text::Bold);
	fpsText.setColor(sf::Color::White);

	fpsText.setPosition(5, 0);
	
	window->draw(fpsText);
}

void Time::loadFont()
{
	if (!font.loadFromFile("Helvetica.ttf"))
		std::cout << "NIE DZIALA" << std::endl;
	else
		fontLoaded = true;
}
