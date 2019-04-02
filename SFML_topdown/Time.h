

#include<SFML/System.hpp>

class Time
{
private:
	static sf::Clock dtClock;
	

public:
	Time();
	~Time();
	static float deltaTime;
	
	
	static void updateDeltaTime();
};

