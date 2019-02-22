#pragma once
#include <string>
#include <iostream>
#include <thread>
#include <conio.h>
#include <istream>
#include "Client.h"
#include "Server.h"
#include "Serial.h"
#include "opencv.hpp"
#include "CBase4618.h"
#include "CAsteroid.h"
#include "CShip.h"
#include "CMissile.h"
#include "CGameObject.h"
#include "CAsteroid.h"
/**
*
* @brief C++ object used draw usnig MSP432 JOTSTICK
*
* This class inherits methods and objects from CBase class.
* this class is overloaded to get joystick data in method update
* and used method draw to draw on a Open cv object
*
* @author Balkaran Sidhu
*
*/
class CAsteriodGame :public CBase4618{

public:
	CAsteriodGame();
	~CAsteriodGame();

	CShip ship;///<ship object

	int score = 0;///<keeps track of score

	int l;///<keeps track of lives

	/** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
	*/
	CAsteriodGame(cv::Size d,int);

	/** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
	*/
	void update() override;

	/** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
	*/
	void draw() override;

	/** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
	*/
	//void run();

	/** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
	*/
	int missile_button();

	void reset();

	void astroid_creation() override;

	int x_pos; ///< X value JoYSTICK
	int y_pos; ///< Y value JoYSTICK
	int flag_reset; ///< BUTTON FLAG value JoYSTICK
	int flag_missile;
	int high; ///< canvas height
	int wide; ///< canvas width 

	vector<CAsteroid>asteroid_list;
	vector<CMissile>missile_list;
	Point2f pos_ship;
	Point2f pos_missile;
};

