#include "stdafx.h"
#include "CMissile.h"


CMissile::CMissile()
{
	_lives = 1;
	_radius = 1;
	_velocity.x = 0;
	_velocity.y = -450;
	BLUE = 255;
	GREEN = 0;
	RED = 0;
}


CMissile::~CMissile()
{
}
