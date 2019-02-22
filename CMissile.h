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
#include "CGameObject.h"
/**
*
* @brief C++ Missile object contains missile data
*
* This class has a all the characteristics of a Missile
*
*
* @author Balkaran Sidhu
*
*/
class CMissile:public CGameObject
{
public:


	/** @brief contains intial object stats.
*
* @param NONE.
* @return nothing to return
*/
	CMissile();
	~CMissile();
};

