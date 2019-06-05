#ifndef TIME_H
#define TIME_H

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>
#include<SFML/sftools/Chronometer.hpp>


class Time
{
private:
	//static sf::Clock dtClock;
	static sftools::Chronometer dtClock;
	
	static sf::Font font;
	static bool fontLoaded;
	static void loadFont();

public:
	Time();
	~Time();
	static float deltaTime;
	//static sf::Clock Clock;
	static sftools::Chronometer Clock;
	
	static void updateDeltaTime();
	static void showFPS(sf::RenderWindow *window);

	static void startClocks();
	static void pauseClocks();
	static void resumeClocks();

};
#endif

