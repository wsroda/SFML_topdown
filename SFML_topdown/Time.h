#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>

class Time
{
private:
	static sf::Clock dtClock;
	
	static sf::Font font;
	static bool fontLoaded;
	static void loadFont();

public:
	Time();
	~Time();
	static float deltaTime;
	static sf::Clock Clock;
	
	static void updateDeltaTime();
	static void showFPS(sf::RenderWindow *window);
};

