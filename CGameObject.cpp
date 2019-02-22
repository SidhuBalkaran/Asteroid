#include "stdafx.h"
#include "CGameObject.h"


CGameObject::CGameObject()
{
	last = cv::getTickCount();
}


CGameObject::~CGameObject()
{
}

void CGameObject::move()
{
	
	/////Time Calc////
	double time_passed;
	double start = cv::getTickCount();

	time_passed = (start - last) / cv::getTickFrequency();
	last = start;
	//physics engine
	_position += (_velocity*time_passed);


}

bool CGameObject::collide(CGameObject & obj)
{
	int distance = sqrt(((obj._position.x - _position.x)*(obj._position.x - _position.x)) + ((obj._position.y - _position.y)*(obj._position.y - _position.y)));
	if ( distance<=(obj._radius + _radius))
		return TRUE;
	else
	return FALSE;
}

bool CGameObject::collide_wall(Size board)
{
	 
	if (_position.x < 0 || _position.x > board.width)
	{
		return TRUE;
	}
	if (_position.y < 0 || _position.y > board.height)
	{
		return TRUE;
	}

	return FALSE;
}

void CGameObject::hit()
{
	//if (_lives <= 0)
	//	_lives = 10;

	_lives = _lives - 1;
}

void CGameObject::draw(Mat & im)
{
	circle(im, _position, _radius,Scalar(BLUE,GREEN,RED), -1);
}
