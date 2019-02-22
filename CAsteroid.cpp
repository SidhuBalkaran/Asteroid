#include "stdafx.h"
#include "CAsteroid.h"


CAsteroid::CAsteroid()
{     srand(time(NULL));
	_radius=( rand() % 30) + 10; //((float)rand() / (float)RAND_MAX);
	
	_lives = 1;
	int choose = rand() % 2;

	if(choose==0)
	{
		int r = rand() % 2;

	
	if (r == 0)
	{
		_position.x = 5;
		_position.y = 250;
		_velocity.x = (rand() % 90) + 50;
		_velocity.y = (rand() % 90) + -50;
	}

	else
	{
		_position.x = 480;
		_position.y = 250;
		_velocity.x = (rand() % -90) - 50;
		_velocity.y = (rand() % 90) + -50;
	}
	}
	else
	{
		int p = rand() % 2;


		if (p == 0)
		{
			_position.x = 250;
			_position.y = 5;
			_velocity.x = (rand() % 90) + 50;
			_velocity.y = (rand() % 90) + 50;
		}

		else
		{
			_position.x = 250;
			_position.y = 480;
			_velocity.x = (rand() % 90) + -50;
			_velocity.y = (rand() % -90) + -50;
		}
	}
	

	BLUE = 0;
	GREEN = 255;
	RED = 0 ;
}


CAsteroid::~CAsteroid()
{
}
