#include "stdafx.h"
#include "CBase4618.h"

CBase4618::CBase4618()
{

}
void CBase4618::draw()
{

}
void CBase4618::run()
{
	//srand((unsigned)time(0));
	
do
{


	/////Time Calc////

	//do this randomly leave it for now
	random += 100;
	if ( random==4000)
	{
		random = 0;
		astroid_creation();
	}

update();
draw();
} while (cv::waitKey(1) !='q');
}
void CBase4618::astroid_creation()
{
}
void CBase4618::update()
{

}
CBase4618::~CBase4618()
{
}
