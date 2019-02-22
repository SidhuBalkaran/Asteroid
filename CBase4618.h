#pragma once

#include "CControl.h"
#include "opencv.hpp"
using namespace std;

/**
*
* @brief C++ object used to hold common code used in all of the following labs for this course
*
* This class has a CControl object and an Open cv object
* which are used in CSketch class.There will also be three public methods
* which implement the two of which are overloaded in CSketch.
*
*
* @author Balkaran Sidhu
*
*/
class CBase4618
{
public:
	CControl control;///<Control object
	cv::Mat _canvas;///<Mat object
	CBase4618();
	~CBase4618();

	/** @brief Overloaded in CAsteroidgame updates the coordinates.
	*
	*
	* @param None.
	* @return nothing to return
	*/
	virtual void update();

	/** @brief Overloaded in CAsteroidgame to draw.
	*
	*
	* @param NONE.
	* @return nothing to return
	*/
	virtual void draw();

	/** @brief runs update and draw in an infinite loop until a button is pressed.
	*
	*
	* @param NONE.
	* @return Nothing to return
	*/
	virtual void run();
	/** @brief Overloaded in CAsteroidgame create asteroid objects.
*
*
* @param NONE.
* @return Nothing to return
*/
	virtual void astroid_creation();
	int random=0;///<random number genrated
	
	double last;///<time when it hits run
};

