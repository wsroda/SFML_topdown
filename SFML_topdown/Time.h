#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
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
	
	
	static void updateDeltaTime();
	static void showFPS(sf::RenderWindow *window);
};

